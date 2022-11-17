#include "csky_mca_test_helper.h"
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include "hardware_test.h"

// Size of region between two memory blocks to check illegal write.
#define CHECK_BLOCK_SIZE (16 * 4)

// Magic number (dead beaf) for memory test, including illegal read & write.
#define MAGIC_NUMBER_FOR_MEMORY_TEST 0xDEADBEAF

// Fill memory with magic number for memory test.
// If the size is not a multiple of 4, the last several bytes will be filled
// with LSB bytes of the magic number.
static void fill_memory(void *p, size_t size) {
	const unsigned int magic_number = MAGIC_NUMBER_FOR_MEMORY_TEST;

	// p may not be 048C-aligned.
	unsigned char *p_byte = p;
	switch ((unsigned int)p_byte & 3) {
	case 1:
		*p_byte++ = (magic_number >> 8) & 0xFF;
		--size;
	case 2:
		*p_byte++ = (magic_number >> 16) & 0xFF;
		--size;
	case 3:
		*p_byte++ = (magic_number >> 24) & 0xFF;
		--size;
	}

	size_t num_of_loops = size >> 2;
	unsigned int *p_word = (unsigned int *)p_byte;
	while (num_of_loops--) {
		*p_word++ = magic_number;
	}

	// Remaining bytes
	p_byte = (unsigned char *)p_word;
	switch (size & 3) {
	case 3:
		p_byte[2] = (magic_number >> 16) & 0xFF;
	case 2:
		p_byte[1] = (magic_number >> 8) & 0xFF;
	case 1:
		p_byte[0] = magic_number & 0xFF;
	}
}

// Check memory for illegal write.
// This function should be used together with the function fill_memory.
// Returning true means that memory was not changed.
static bool check_memory_for_illegal_write(void *p, size_t size) {
	const unsigned int magic_number = MAGIC_NUMBER_FOR_MEMORY_TEST;

	const void *first_modified_ptr = NULL;
	const void *last_modified_ptr = NULL;
	
	unsigned char *p_byte = p;
	switch ((unsigned int)p & 3) {
	case 1:
		if (*p_byte != ((magic_number >> 8) & 0xFF)) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = p_byte;
			}
			last_modified_ptr = p_byte + 1;
		}
		++p_byte;
		--size;
	case 2:
		if (*p_byte != ((magic_number >> 16) & 0xFF)) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = p_byte;
			}
			last_modified_ptr = p_byte + 1;
		}
		++p_byte;
		--size;
	case 3:
		if (*p_byte != ((magic_number >> 24) & 0xFF)) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = p_byte;
			}
			last_modified_ptr = p_byte + 1;
		}
		++p_byte;
		--size;
	}

	size_t num_of_loops = size >> 2;
	unsigned int *p_word = (unsigned int *)p_byte;
	while (num_of_loops--) {
		if (*p_word != magic_number) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = p_word;
			}
			last_modified_ptr = p_word + 1;
		}
		++p_word;
	}

	p_byte = (unsigned char *)p_word;
	switch (size & 3) {
	case 3:
		if (p_byte[2] != ((magic_number >> 16) & 0xFF)) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = &p_byte[2];
			}
			last_modified_ptr = &p_byte[2] + 1;
		}
	case 2:
		if (p_byte[1] != ((magic_number >> 8) & 0xFF)) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = &p_byte[1];
			}
			last_modified_ptr = &p_byte[1] + 1;
		}
	case 1:
		if (p_byte[0] != (magic_number & 0xFF)) {
			if (first_modified_ptr == NULL) {
				first_modified_ptr = &p_byte[0];
			}
			last_modified_ptr = &p_byte[0] + 1;
		}
	}

	if (first_modified_ptr != NULL) {
		print_log("Memory block (0x%08x) was written illegally, offset = %d, "
			"size = %d.\n",
			(unsigned int)first_modified_ptr,
			(unsigned int)first_modified_ptr - (unsigned int)p,
			(unsigned int)last_modified_ptr - (unsigned int)first_modified_ptr);
		return false;
	}

	return true;
}

static inline size_t alignment_to_size(mca_memory_alignment_t align) {
	size_t align_size;
	switch (align) {
	case align_1: align_size = 0x1; break;
	case align_2: align_size = 0x2; break;
	case align_3: align_size = 0x3; break;
	case align_4: align_size = 0x4; break;
	case align_5: align_size = 0x5; break;
	case align_6: align_size = 0x6; break;
	case align_7: align_size = 0x7; break;
	case align_8: align_size = 0x8; break;
	case align_9: align_size = 0x9; break;
	case align_a: align_size = 0xa; break;
	case align_b: align_size = 0xb; break;
	case align_c: align_size = 0xc; break;
	case align_d: align_size = 0xd; break;
	case align_e: align_size = 0xe; break;
	case align_f: align_size = 0xf; break;
	case align_0:
	default:
		align_size = 0x0;
		break;
	}
	return align_size;
}

static inline void *align_memory_addr_by_alignment(
	void *addr, mca_memory_alignment_t align) {
	size_t align_size = alignment_to_size(align);
	return align_memory_addr_to(addr, align_size);
}

static inline size_t round_up_to_4(size_t n) {
	return (n + 3) & ((size_t)-4);
}

static inline size_t get_num_align_cases(
	const mca_test_block_t *block,
	size_t *index,
	mca_memory_alignment_t *align) {
	size_t num_cases;

	size_t size_of_type = size_of(block->type);
	if (block->aligns == align_all) {
		size_t step = size_of_type;
		// 64-bit integer can actually be aligned as: 0-4-8-C.
		//if (block->type == MCA_FXP64) {
		//	step = 4;
		//}
		num_cases = 0x10 / step;
		if (index != NULL) {			
			*align = (mca_memory_alignment_t)(1 << (*index * step));
		}
	}
	else if (block->aligns == align_any) {
		num_cases = 1;
		if (index != NULL) {
			*align = align_0;
		}
	}
	else {
		num_cases = 0;
		size_t step = size_of_type;
		// 64-bit integer can actually be aligned as: 0-4-8-C.
		//if (block->type == MCA_FXP64) {
		//	step = 4;
		//}
		size_t index_ = 0;
		for (size_t j = 0; j < 0x10; j += step) {
			mca_memory_alignment_t align_ = (mca_memory_alignment_t)(1 << j);
			if (block->aligns & align_) {
				++num_cases;
				if (index != NULL && index_ == *index) {
					*align = align_;
				}
				++index_;
			}
		}
		ASR_ASSERT(num_cases > 0 && "Invalid alignment specification.");
	}
	
	return num_cases;
}

bool mca_generic_hardware_test(
	void *params,
	mca_gen_cache_func cache_generator,
	const mca_cache_block_t *cache_blocks,
	size_t num_cache_blocks,
	mca_test_func test_func,
	mca_test_block_t *test_blocks,
	size_t num_test_blocks) {
	bool total_passed = true, passed;

	char **cache_block_ptrs = fast_malloc(sizeof(char *) * num_cache_blocks);
	char **test_block_ptrs = fast_malloc(sizeof(char *) * num_test_blocks);
	char *cache_memory_blocks;
	char *test_memory_blocks;

	// Allocates buffer for each cache block.
	size_t size_cache_blocks = 0;
	for (size_t i = 0; i < num_cache_blocks; ++i) {
		size_t size = cache_blocks[i].count * size_of(cache_blocks[i].type);
		size = round_up_to_4(size);
		size_cache_blocks += size;
	}
	cache_memory_blocks = fast_malloc(size_cache_blocks);
	for (size_t i = 0, offset = 0; i < num_cache_blocks; ++i) {
		cache_block_ptrs[i] = cache_memory_blocks + offset;
		size_t size = cache_blocks[i].count * size_of(cache_blocks[i].type);
		size = round_up_to_4(size);
		offset += size;
	}

	// Generates caches.
	cache_generator(params, cache_blocks, (void **)cache_block_ptrs);

	// Allocates buffer for test blocks.
	size_t size_test_blocks = CHECK_BLOCK_SIZE;
	for (size_t i = 0; i < num_test_blocks; ++i) {
		size_t size = test_blocks[i].count * size_of(test_blocks[i].type);
		size = round_up_to_4(size);
		size += 0x10; // For alignment
		size += CHECK_BLOCK_SIZE;
		size_test_blocks += size;
	}
	test_memory_blocks = fast_malloc(size_test_blocks);

	// Calculates number of alignment combination cases.
	size_t num_align_cases = 1;
	for (size_t i = 0; i < num_test_blocks; ++i) {
		num_align_cases *= get_num_align_cases(&test_blocks[i], NULL, NULL);
	}

	// Iterates for each alignment combination.
	for (size_t align_idx = 0; align_idx < num_align_cases; ++align_idx) {
		// Allocates buffer for each test block.
		char *buffer_ptr = test_memory_blocks;
		for (size_t i = 0, k = 1; i < num_test_blocks; ++i) {
			size_t num_cases = get_num_align_cases(&test_blocks[i], NULL, NULL);
			size_t index_ = (align_idx / k) % num_cases;
			k *= num_cases;
			mca_memory_alignment_t align_ = align_any;
			get_num_align_cases(&test_blocks[i], &index_, &align_);
			
			test_block_ptrs[i] = align_memory_addr_by_alignment(
				buffer_ptr + CHECK_BLOCK_SIZE, align_);
			size_t size = test_blocks[i].count * size_of(test_blocks[i].type);

			// Copies cache if it is input, or resets with 0xEF if it is output.
			if (test_blocks[i].io_dir == io_dir_input) {
				asr_memcpy(test_block_ptrs[i],
					cache_block_ptrs[test_blocks[i].cache_index], size);
			}
			else {
				// For MCA_FXP24, bits [31:24] are set as 0x00 by MCA.
				// For MCA_FXP16_32BIT, bits [31:16] are not touched.
				// So we set output as 0x00 here.
				memset(test_block_ptrs[i], 0x00, size);
			}
			
			// Fills check block with magic numbers.
			fill_memory(buffer_ptr, test_block_ptrs[i] - buffer_ptr);

			buffer_ptr = test_block_ptrs[i] + size;
		}
		fill_memory(buffer_ptr, CHECK_BLOCK_SIZE);		

		// Runs the test.
		passed = test_func(params, test_blocks, (void **)test_block_ptrs);
		if (!passed) {
			print_log("Test function returned false.\n");
		}

		// Checks output and illegal write of input.
		for (size_t i = 0; i < num_test_blocks; ++i) {
			size_t size = test_blocks[i].count * size_of(test_blocks[i].type);
			if (test_blocks[i].io_dir == io_dir_input) {
				if (!test_blocks[i].input_change_allowed) {
					if (0 != memcmp(test_block_ptrs[i],
						cache_block_ptrs[test_blocks[i].cache_index], size)) {
						print_log("Block %d as input was modified.\n", i);
					}
				}
			}
			else {
				if (!expect_array_equal_with_tol_fxp(
					test_block_ptrs[i],
					cache_block_ptrs[test_blocks[i].cache_index],
					size_of(test_blocks[i].type),
					test_blocks[i].count,
					test_blocks[i].tolerance)) {
					passed = false;
				}
			}
		}

		// Checks illegal write of check blocks.
		buffer_ptr = test_memory_blocks;
		for (size_t i = 0; i < num_test_blocks; ++i) {
			if (!check_memory_for_illegal_write(
				buffer_ptr, test_block_ptrs[i] - buffer_ptr)) {
				print_log("Memory before block %d was modified.\n", i);
				passed = false;
			}
			size_t size = test_blocks[i].count * size_of(test_blocks[i].type);
			buffer_ptr = test_block_ptrs[i] + size;
		}
		if (!check_memory_for_illegal_write(
			buffer_ptr, CHECK_BLOCK_SIZE)) {
			print_log("Memory after block %d was modified.\n",
				num_test_blocks - 1);
			passed = false;
		}

		// Reports test result.
		if (!passed) {
			char *alignment_str =
				fast_malloc(sizeof(char) * 16 * num_test_blocks);
			char *alignment_str_ptr = alignment_str;
			for (size_t i = 0, k = 1; i < num_test_blocks; ++i) {
				size_t num_cases =
					get_num_align_cases(&test_blocks[i], NULL, NULL);
				size_t index_ = (align_idx / k) % num_cases;
				k *= num_cases;
				mca_memory_alignment_t align_ = align_any;
				get_num_align_cases(&test_blocks[i], &index_, &align_);

				alignment_str_ptr += sprintf(alignment_str_ptr,
					"block_%d=0x%X", i, alignment_to_size(align_));
				if (i + 1 != num_test_blocks) {
					strcat(alignment_str, ", ");
					alignment_str_ptr += 2;
				}
			}
			print_log("Test failed for memory alignment combination: %s.\n",
				alignment_str);
			fast_free(alignment_str);
			total_passed = false;
		}
	}

	fast_free(test_memory_blocks);
	fast_free(cache_memory_blocks);
	fast_free(test_block_ptrs);
	fast_free(cache_block_ptrs);

	return total_passed;
}

#define BANK_SIZE (32 * 1024) // 32KB

static size_t upper_round_to(size_t v, size_t align) {
	return (v + align - 1) & (size_t)-(int)align;
}

static void *align_to(void *block, size_t align_in_byte) {
	return (void *)upper_round_to((size_t)block, align_in_byte);
}

void *allocate_bank_awareness(
	void **bank_a, size_t size_bank_a,
	void **bank_b, size_t size_bank_b,
	size_t num_additional_blocks, ...) {
	assert(size_bank_a <= BANK_SIZE);
	assert(size_bank_b <= BANK_SIZE);

	char *big_block = NULL;

	va_list ap, ap_var;
	va_start(ap, num_additional_blocks);

	size_t size_bank_a_rounded = upper_round_to(size_bank_a, 16);
	size_t size_bank_b_rounded = upper_round_to(size_bank_b, 16);

	// Calculates allocation size in bytes.
	size_t size_to_alloc = 0x10;
	size_t remaining_size;
	if (size_bank_a_rounded >= size_bank_b_rounded) {
		size_to_alloc += 2 * size_bank_a_rounded;
		remaining_size = BANK_SIZE - size_bank_b_rounded;
	} else {
		size_to_alloc += 2 * size_bank_b_rounded;
		remaining_size = BANK_SIZE - size_bank_a_rounded;
	}
	size_to_alloc += BANK_SIZE;
	va_copy(ap_var, ap);
	for (size_t i = 0; i < num_additional_blocks; ++i) {
		/*void **block_addr = */va_arg(ap_var, void **);
		size_t block_size = va_arg(ap_var, size_t);
		size_t block_size_rounded = upper_round_to(block_size, 4);
		if (remaining_size >= block_size_rounded) {
			remaining_size -= block_size_rounded;
		} else {
			size_to_alloc += block_size_rounded;
		}
	}
	va_end(ap_var);

	// Distributes the allocated block.
	big_block = (char *)fast_malloc(size_to_alloc);
	if (NULL != big_block) {
		char *block_x_addr, *block_y_addr, *block_z_addr;
		size_t block_x_size, block_y_size, block_z_size;
		block_x_addr = (char *)align_to(big_block, 16);
		block_y_addr = (char *)align_to(big_block, BANK_SIZE);
		block_x_size = (size_t)(block_y_addr - block_x_addr);
		if (size_bank_a_rounded >= size_bank_b_rounded) {
			if (block_x_size >= size_bank_a_rounded) {
				*bank_a = block_x_addr;
				block_x_addr += size_bank_a_rounded;
				block_x_size -= size_bank_a_rounded;
				*bank_b = block_y_addr;
				block_y_addr += size_bank_b_rounded;
				block_y_size = size_to_alloc - (block_y_addr - big_block);
				block_z_addr = NULL;
				block_z_size = 0;
			} else if (block_x_size >= size_bank_b_rounded) {
				*bank_b = block_x_addr;
				block_x_addr += size_bank_b_rounded;
				block_x_size -= size_bank_b_rounded;
				*bank_a = block_y_addr;
				block_y_addr += size_bank_a_rounded;
				block_y_size = size_to_alloc - (block_y_addr - big_block);
				block_z_addr = NULL;
				block_z_size = 0;
			} else {
				*bank_a = block_y_addr;
				block_y_addr += size_bank_a_rounded;
				block_y_size = BANK_SIZE - size_bank_a_rounded;
				block_z_addr = (char *)align_to(block_y_addr, BANK_SIZE);
				*bank_b = block_z_addr;
				block_z_addr += size_bank_b_rounded;
				block_z_size = size_to_alloc - (block_z_addr - big_block);
			}
		} else {
			if (block_x_size >= size_bank_b_rounded) {
				*bank_b = block_x_addr;
				block_x_addr += size_bank_b_rounded;
				block_x_size -= size_bank_b_rounded;
				*bank_a = block_y_addr;
				block_y_addr += size_bank_a_rounded;
				block_y_size = size_to_alloc - (block_y_addr - big_block);
				block_z_addr = NULL;
				block_z_size = 0;
			} else if (block_x_size >= size_bank_a_rounded) {
				*bank_a = block_x_addr;
				block_x_addr += size_bank_a_rounded;
				block_x_size -= size_bank_a_rounded;
				*bank_b = block_y_addr;
				block_y_addr += size_bank_b_rounded;
				block_y_size = size_to_alloc - (block_y_addr - big_block);
				block_z_addr = NULL;
				block_z_size = 0;
			} else {
				*bank_b = block_y_addr;
				block_y_addr += size_bank_b_rounded;
				block_y_size = BANK_SIZE - size_bank_b_rounded;
				block_z_addr = (char *)align_to(block_y_addr, BANK_SIZE);
				*bank_a = block_z_addr;
				block_z_addr += size_bank_a_rounded;
				block_z_size = size_to_alloc - (block_z_addr - big_block);
			}
		}
		va_copy(ap_var, ap);
		for (size_t i = 0; i < num_additional_blocks; ++i) {
			void **block_addr = va_arg(ap_var, void **);
			size_t block_size = va_arg(ap_var, size_t);
			size_t block_size_rounded = upper_round_to(block_size, 4);
			char **block_buffer;
			size_t *block_buffer_size;
			// Chooses the minimal buffer.
			if ((block_x_size <= block_y_size || block_y_size == 0) &&
				block_x_size >= block_size_rounded) {
				if (block_x_size <= block_z_size || block_z_size == 0) {
					block_buffer = &block_x_addr;
					block_buffer_size = &block_x_size;
				} else {
					block_buffer = &block_z_addr;
					block_buffer_size = &block_z_size;
				}
			} else {
				if ((block_y_size <= block_z_size || block_z_size == 0) &&
					block_y_size >= block_size_rounded) {
					block_buffer = &block_y_addr;
					block_buffer_size = &block_y_size;
				} else {
					block_buffer = &block_z_addr;
					block_buffer_size = &block_z_size;
				}
			}
			assert(*block_buffer_size >= block_size_rounded);
			*block_addr = *block_buffer;
			*block_buffer += block_size_rounded;
			*block_buffer_size -= block_size_rounded;
		}
	}
	va_end(ap_var);

	va_end(ap);

	return big_block;
}

/**
 * b   = \frac{\sum_{i=1}^n{(x_i-xm)*(y_i-ym)}}{\sum_{i=1}^n{(x_i-xm)^2}}
 *     = \frac{\sum_{i=1}^n{x_i*y_i}-n*xm*ym}{\sum_{i=1}^n{x_i^2-n*xm^2}}
 * a   = ym-b*xm
 *
 * r^2 = \frac{{\sum_{i=1}^n{(x_i-xm)*(y_i-ym)}}^2}{\sum_{i=1}^n{(x_i-xm)^2}*\sum_{i=1}^n{(y_i-ym)^2}}
 *     = \frac{{\sum_{i=1}^n{x_i*y_i}-n*xm*ym}^2}{\sum_{i=1}^n{x_i^2-n*xm^2}*\sum_{i=1}^n{y_i^2-n*ym^2}}
 */
void linear_regression(
	const float *x,
	const float *y,
	size_t n,
	float *slope,
	float *intercept,
	float *r2) {
	float sum_xy = 0, sum_x2 = 0, sum_y2 = 0, sum_x = 0, sum_y = 0;
	for (size_t i = 0; i < n; ++i) {
		float xe = x[i], ye = y[i];
		sum_xy += xe * ye;
		sum_x2 += xe * xe;
		sum_y2 += ye * ye;
		sum_x += xe;
		sum_y += ye;
	}
	float recip_n = 1.0f / n;
	float mean_x = sum_x * recip_n;
	float mean_y = sum_y * recip_n;
	float b_num = sum_xy - n * mean_x * mean_y;
	float b_den_x = sum_x2 - n * mean_x * mean_x;
	float b_den_y = sum_y2 - n * mean_y * mean_y;
	float slope_ = b_num / b_den_x;
	float intercept_ = mean_y - slope_ * mean_x;
	float r2_ = slope_ * b_num / b_den_y;
	if (slope != NULL) {
		*slope = slope_;
	}
	if (intercept != NULL) {
		*intercept = intercept_;
	}
	if (r2 != NULL) {
		*r2 = r2_;
	}
}

#define FXP128_BITS (CHAR_BIT * sizeof(fxp128_t))
#define FXP128_BITS_HALF (FXP128_BITS >> 1)

void fxp128_init(fxp128_t *x) {
	x->hi.u = x->lo = 0;
}

void fxp128_add(fxp128_t *x, fxp64_t v) {
	if (v < 0) {
		x->hi.u -= 1;
	}
	ufxp64_t uv = v;
	if ((x->lo += uv) < uv) {
		++x->hi.u;
	}
}

void fxp128_negate(fxp128_t *x) {
	x->hi.u = ~x->hi.u;
	x->lo = ~x->lo;
	fxp128_add(x, 1);
}

void fxp128_shl(fxp128_t *x, uint8_t bits) {
	if (bits >= FXP128_BITS) {
		x->hi.u = 0;
		x->lo = 0;
	}
	else if (bits >= FXP128_BITS_HALF) {
		x->hi.u = x->lo << (bits - FXP128_BITS_HALF);
		x->lo = 0;
	}
	else if (bits > 0) {
		x->hi.u <<= bits;
		x->hi.u |= (x->lo >> (FXP128_BITS_HALF - bits));
		x->lo <<= bits;
	}
}

void fxp128_shr(fxp128_t *x, uint8_t bits) {
	if (bits >= FXP128_BITS) {
		x->lo = x->hi.s >> bits;
		x->hi.s = x->lo;
	}
	else if (bits >= FXP128_BITS_HALF) {
		x->lo = x->hi.s >> (bits - FXP128_BITS_HALF);
		x->hi.s >>= bits;
	}
	else if (bits > 0) {
		x->lo >>= bits;
		x->lo |= (x->hi.s << (FXP128_BITS_HALF - bits));
		x->hi.s >>= bits;
	}
}

void fxp128_round(fxp128_t *x, uint8_t q) {
	if (q == 0 || q >= FXP128_BITS - 1) {
		// If q == 0, no need to do rounding.
		// If q >= FXP128_BITS - 1, rounding is not defined.
		return;
	}

	bool is_negative = x->hi.s < 0;
	if (is_negative) {
		fxp128_negate(x);
	}

	if (q <= FXP128_BITS_HALF) {
		ufxp64_t mask = (ufxp64_t)1 << (q - 1);
		if (x->lo & mask) {
			if ((x->lo += mask) < mask) {
				++x->hi.u;
			}
		}
		x->lo &= (~((mask << 1) - 1));
	}
	else {
		ufxp64_t mask = (ufxp64_t)1 << (q - 1 - FXP128_BITS_HALF);
		if (x->hi.u & mask) {
			x->hi.u += mask;
		}
		x->hi.u &= (~((mask << 1) - 1));
		x->lo = 0;
	}

	if (is_negative) {
		fxp128_negate(x);
	}
}

void fxp128_sat_to(const fxp128_t *x, void *v, mca_num_type_t v_type) {
	fxp64_t v_64 = 0;
	fxp128_sat_to_fxp64(x, &v_64);

	switch (v_type) {
	case MCA_FXP64:
		*(fxp64_t *)v = v_64;
		break;
	case MCA_FXP32:
		*(fxp32_t *)v =
			(fxp32_t)coerce(v_64, INT32_MAX, INT32_MIN);
		break;
	case MCA_FXP24:
		*(fxp32_t *)v =
			(fxp32_t)coerce(v_64, INT32_MAX >> 8, INT32_MIN >> 8);
		*(fxp32_t *)v &= 0x00FFFFFF;
		break;
	case MCA_FXP16_32BIT:
		*(fxp32_t *)v =
			(fxp32_t)coerce(v_64, INT16_MAX, INT16_MIN);
		*(fxp32_t *)v &= 0x0000FFFF;
		break;
	case MCA_FXP16:
		*(fxp16_t *)v =
			(fxp16_t)coerce(v_64, INT16_MAX, INT16_MIN);
		break;
	case MCA_FXP8:
		*(fxp8_t *)v =
			(fxp8_t)coerce(v_64, INT8_MAX, INT8_MIN);
		break;
	default:
		break;
	}
}

void fxp128_sat_to_fxp64(const fxp128_t *x, fxp64_t *v) {
	if (x->hi.s > 0) {
		*v = INT64_MAX;
	}
	else if (x->hi.s < -1) {
		*v = INT64_MIN;
	}
	else {
		ufxp64_t mask = (ufxp64_t)1 << (FXP128_BITS_HALF - 1);
		if (x->hi.s == 0) {
			*v = (x->lo & mask) ? INT64_MAX : x->lo;
		}
		else/* if (x->hi.s == -1)*/ {
			*v = (x->lo & mask) ? x->lo : INT64_MIN;
		}
	}
}

static void fxp128_mac_fxp32(
	fxp128_t *x,
	const fxp32_t *a,
	const fxp32_t *b,
	size_t n) {
	for (size_t i = 0; i < n; ++i) {
		fxp128_add(x, (fxp64_t)a[i] * (fxp64_t)b[i]);
	}
}

static void fxp128_mac_fxp24(
	fxp128_t *x,
	const fxp32_t *a,
	const fxp32_t *b,
	size_t n) {
	fxp64_t sum = 0;
	// 64 - (24 + 24) = 16 bits, i.e. 65536 numbers.
	ASR_ASSERT(n < UINT16_MAX);
	for (size_t i = 0; i < n; ++i) {
		// Extends sign-bit.
		sum += (fxp64_t)(a[i] << 8 >> 8) * (fxp64_t)(b[i] << 8 >> 8);
	}
	fxp128_add(x, sum);
}

static void fxp128_mac_fxp16_32bit(
	fxp128_t *x,
	const fxp32_t *a,
	const fxp32_t *b,
	size_t n) {
	fxp64_t sum = 0;
	for (size_t i = 0; i < n; ++i) {
		// Extends sign-bit.
		sum += (fxp32_t)(fxp16_t)a[i] * (fxp32_t)(fxp16_t)b[i];
	}
	fxp128_add(x, sum);
}

static void fxp128_mac_fxp16(
	fxp128_t *x,
	const fxp16_t *a,
	const fxp16_t *b,
	size_t n) {
	fxp64_t sum = 0;
	for (size_t i = 0; i < n; ++i) {
		sum += (fxp32_t)a[i] * (fxp32_t)b[i];
	}
	fxp128_add(x, sum);
}

static void fxp128_mac_fxp8(
	fxp128_t *x,
	const fxp8_t *a,
	const fxp8_t *b,
	size_t n) {
	fxp32_t sum = 0;
	// 32 - (8 + 8) = 16 bits, i.e. 65536 numbers.
	ASR_ASSERT(n < UINT16_MAX);
	for (size_t i = 0; i < n; ++i) {
		sum += (fxp16_t)a[i] * (fxp16_t)b[i];
	}
	fxp128_add(x, sum);
}

void fxp128_mac(
	fxp128_t *x,
	const void *a,
	const void *b,
	mca_num_type_t type,
	size_t n) {
	switch (type) {
	case MCA_FXP32:
		fxp128_mac_fxp32(x, a, b, n);
		break;
	case MCA_FXP24:
		fxp128_mac_fxp24(x, a, b, n);
		break;
	case MCA_FXP16_32BIT:
		fxp128_mac_fxp16_32bit(x, a, b, n);
		break;
	case MCA_FXP16:
		fxp128_mac_fxp16(x, a, b, n);
		break;
	case MCA_FXP8:
		fxp128_mac_fxp8(x, a, b, n);
		break;
	case MCA_FXP64:
	default:
		ASR_ASSERT(false &&
			"Numeric type greater than 32-bit is not supported!");
		break;
	}
}

static inline fxp64_t extend_to_fxp64(const void *data, size_t index,
	mca_num_type_t type) {
	switch (type) {
	case MCA_FXP64:
		return ((const fxp64_t *)data)[index];
	case MCA_FXP32:
		return ((const fxp32_t *)data)[index];
	case MCA_FXP24:
		return ((const fxp32_t *)data)[index] << 8 >> 8;
	case MCA_FXP16_32BIT:
		return ((const fxp32_t *)data)[index] << 16 >> 16;
	case MCA_FXP16:
		return ((const fxp16_t *)data)[index];
	case MCA_FXP8:
		return ((const fxp8_t *)data)[index];
	default:
		ASR_ASSERT(false &&
			"Invalid MCA numeric type identifier!");
		return 0;
	}
}

static void mul_64_64_keep_128(fxp64_t a, fxp64_t b, fxp128_t *prod) {
	int sign = (a < 0 ? 1 : 0) ^ (b < 0 ? 1 : 0);
	
	ufxp64_t ua = a < 0 ? -a : a;
	ufxp64_t ub = b < 0 ? -b : b;
	
	// BIT: [0, 64)
	ufxp64_t prod_0 = (ua & UINT32_MAX) * (ub & UINT32_MAX);
	// BIT: [32, 96)
	ufxp64_t prod_1 = (ua & UINT32_MAX) * (ub >> 32);
	// BIT: [32, 96)
	ufxp64_t prod_2 = (ua >> 32) * (ub & UINT32_MAX);
	// BIT: [64, 128)
	ufxp64_t prod_3 = (ua >> 32) * (ub >> 32);

	ufxp64_t prod_00 = prod_0 >> 32;
	if ((prod_1 += prod_00) < prod_00) {
		prod_3 += (ufxp64_t)1 << 32;
	}
	if ((prod_1 += prod_2) < prod_2) {
		prod_3 += (ufxp64_t)1 << 32;
	}
	prod_3 += (prod_1 >> 32);

	prod->lo = (prod_1 << 32) | (prod_0 & UINT32_MAX);
	prod->hi.u = prod_3;

	if (sign) {
		fxp128_negate(prod);
	}
}

void fxp128_mac_diff_types(
	fxp128_t *x,
	const void *a,
	mca_num_type_t a_type,
	const void *b,
	mca_num_type_t b_type,
	size_t n) {
	if (a_type == b_type) {
		fxp128_mac(x, a, b, a_type, n);
		return;
	}

	bool need_64x64_keep_128 = size_of(a_type) + size_of(b_type) > 8;
	for (size_t i = 0; i < n; ++i) {
		fxp64_t elem_a = extend_to_fxp64(a, i, a_type);
		fxp64_t elem_b = extend_to_fxp64(b, i, b_type);
		if (need_64x64_keep_128) {
			fxp128_t prod;
			mul_64_64_keep_128(elem_a, elem_b, &prod);
			if ((x->lo += prod.lo) < prod.lo) {
				++x->hi.u;
			}
			x->hi.u += prod.hi.u;
		}
		else {
			fxp128_add(x, elem_a * elem_b);
		}
	}
}
