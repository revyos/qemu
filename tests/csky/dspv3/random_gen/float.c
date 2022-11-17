/*
 * Copyright (c) 2021 T-Head Semiconductor Co., Ltd. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <math.h>
#include <arm_fp16.h>


union reg128 {
        unsigned int x32[4];
        unsigned short x16[8];
        int si32[4];
        short si16[8];
        unsigned int ui32[4];
        unsigned short ui16[8];
        float f64[2];
        float f32[4];
        __fp16 f16[8];
};

void print_f32(union reg128 res)
{
        printf(".float32 = {");
        printf("0x%x, ", res.x32[0]);
        printf("0x%x, ", res.x32[1]);
        printf("0x%x, ", res.x32[2]);
        printf("0x%x, ", res.x32[3]);

        printf("},\n");
}

void print_f16(union reg128 res)
{
        printf(".float16 = {");
        printf("0x%x, ", res.x16[0]);
        printf("0x%x, ", res.x16[1]);
        printf("0x%x, ", res.x16[2]);
        printf("0x%x, ", res.x16[3]);
        printf("0x%x, ", res.x16[4]);
        printf("0x%x, ", res.x16[5]);
        printf("0x%x, ", res.x16[6]);
        printf("0x%x, ", res.x16[7]);
        printf("},\n");
}

void vadd_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] + b.f32[0];
        res.f32[1] = a.f32[1] + b.f32[1];
        res.f32[2] = a.f32[2] + b.f32[2];
        res.f32[3] = a.f32[3] + b.f32[3];

        print_f32(res);
}

void vadd_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] + b.f16[0];
        res.f16[1] = a.f16[1] + b.f16[1];
        res.f16[2] = a.f16[2] + b.f16[2];
        res.f16[3] = a.f16[3] + b.f16[3];
        res.f16[4] = a.f16[4] + b.f16[4];
        res.f16[5] = a.f16[5] + b.f16[5];
        res.f16[6] = a.f16[6] + b.f16[6];
        res.f16[7] = a.f16[7] + b.f16[7];

        print_f16(res);
}

void vsub_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] - b.f32[0];
        res.f32[1] = a.f32[1] - b.f32[1];
        res.f32[2] = a.f32[2] - b.f32[2];
        res.f32[3] = a.f32[3] - b.f32[3];

        print_f32(res);
}

void vsub_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] - b.f16[0];
        res.f16[1] = a.f16[1] - b.f16[1];
        res.f16[2] = a.f16[2] - b.f16[2];
        res.f16[3] = a.f16[3] - b.f16[3];
        res.f16[4] = a.f16[4] - b.f16[4];
        res.f16[5] = a.f16[5] - b.f16[5];
        res.f16[6] = a.f16[6] - b.f16[6];
        res.f16[7] = a.f16[7] - b.f16[7];

        print_f16(res);
}

void vpadd_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] + a.f32[1];
        res.f32[1] = a.f32[2] + a.f32[3];
        res.f32[2] = b.f32[0] + b.f32[1];
        res.f32[3] = b.f32[2] + b.f32[3];

        print_f32(res);
}

void vpadd_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] + a.f16[1];
        res.f16[1] = a.f16[2] + a.f16[3];
        res.f16[2] = a.f16[4] + a.f16[5];
        res.f16[3] = a.f16[6] + a.f16[7];
        res.f16[4] = b.f16[0] + b.f16[1];
        res.f16[5] = b.f16[2] + b.f16[3];
        res.f16[6] = b.f16[4] + b.f16[5];
        res.f16[7] = b.f16[6] + b.f16[7];

        print_f16(res);
}


void vasx_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] - b.f32[1];
        res.f32[1] = a.f32[1] + b.f32[0];
        res.f32[2] = a.f32[2] - b.f32[3];
        res.f32[3] = a.f32[3] + b.f32[2];

        print_f32(res);
}

void vasx_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] - b.f16[1];
        res.f16[1] = a.f16[1] + b.f16[0];
        res.f16[2] = a.f16[2] - b.f16[3];
        res.f16[3] = a.f16[3] + b.f16[2];
        res.f16[4] = a.f16[4] - b.f16[5];
        res.f16[5] = a.f16[5] + b.f16[4];
        res.f16[6] = a.f16[6] - b.f16[7];
        res.f16[7] = a.f16[7] + b.f16[6];

        print_f16(res);
}

void vsax_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] + b.f32[1];
        res.f32[1] = a.f32[1] - b.f32[0];
        res.f32[2] = a.f32[2] + b.f32[3];
        res.f32[3] = a.f32[3] - b.f32[2];

        print_f32(res);
}

void vsax_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] + b.f16[1];
        res.f16[1] = a.f16[1] - b.f16[0];
        res.f16[2] = a.f16[2] + b.f16[3];
        res.f16[3] = a.f16[3] - b.f16[2];
        res.f16[4] = a.f16[4] + b.f16[5];
        res.f16[5] = a.f16[5] - b.f16[4];
        res.f16[6] = a.f16[6] + b.f16[7];
        res.f16[7] = a.f16[7] - b.f16[6];

        print_f16(res);
}

void vabs_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = fabs(a.f32[0]);
        res.f32[1] = fabs(a.f32[1]);
        res.f32[2] = fabs(a.f32[2]);
        res.f32[3] = fabs(a.f32[3]);

        print_f32(res);
}

void vabs_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = fabs(a.f16[0]);
        res.f16[1] = fabs(a.f16[1]);
        res.f16[2] = fabs(a.f16[2]);
        res.f16[3] = fabs(a.f16[3]);
        res.f16[4] = fabs(a.f16[4]);
        res.f16[5] = fabs(a.f16[5]);
        res.f16[6] = fabs(a.f16[6]);
        res.f16[7] = fabs(a.f16[7]);

        print_f16(res);
}

void vsabs_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = fabs(a.f32[0] - b.f32[0]);
        res.f32[1] = fabs(a.f32[1] - b.f32[1]);
        res.f32[2] = fabs(a.f32[2] - b.f32[2]);
        res.f32[3] = fabs(a.f32[3] - b.f32[3]);

        print_f32(res);
}

void vsabs_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = fabs(a.f16[0] - b.f16[0]);
        res.f16[1] = fabs(a.f16[1] - b.f16[1]);
        res.f16[2] = fabs(a.f16[2] - b.f16[2]);
        res.f16[3] = fabs(a.f16[3] - b.f16[3]);
        res.f16[4] = fabs(a.f16[4] - b.f16[4]);
        res.f16[5] = fabs(a.f16[5] - b.f16[5]);
        res.f16[6] = fabs(a.f16[6] - b.f16[6]);
        res.f16[7] = fabs(a.f16[7] - b.f16[7]);

        print_f16(res);
}

void vneg_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = -a.f32[0];
        res.f32[1] = -a.f32[1];
        res.f32[2] = -a.f32[2];
        res.f32[3] = -a.f32[3];

        print_f32(res);
}

void vneg_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = -a.f16[0];
        res.f16[1] = -a.f16[1];
        res.f16[2] = -a.f16[2];
        res.f16[3] = -a.f16[3];
        res.f16[4] = -a.f16[4];
        res.f16[5] = -a.f16[5];
        res.f16[6] = -a.f16[6];
        res.f16[7] = -a.f16[7];

        print_f16(res);
}

void vmax_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] > b.f32[0] ? a.f32[0] : b.f32[0];
        res.f32[1] = a.f32[1] > b.f32[1] ? a.f32[1] : b.f32[1];
        res.f32[2] = a.f32[2] > b.f32[2] ? a.f32[2] : b.f32[2];
        res.f32[3] = a.f32[3] > b.f32[3] ? a.f32[3] : b.f32[3];

        print_f32(res);
}

void vmax_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] > b.f16[0] ? a.f16[0] : b.f16[0];
        res.f16[1] = a.f16[1] > b.f16[1] ? a.f16[1] : b.f16[1];
        res.f16[2] = a.f16[2] > b.f16[2] ? a.f16[2] : b.f16[2];
        res.f16[3] = a.f16[3] > b.f16[3] ? a.f16[3] : b.f16[3];
        res.f16[4] = a.f16[4] > b.f16[4] ? a.f16[4] : b.f16[4];
        res.f16[5] = a.f16[5] > b.f16[5] ? a.f16[5] : b.f16[5];
        res.f16[6] = a.f16[6] > b.f16[6] ? a.f16[6] : b.f16[6];
        res.f16[7] = a.f16[7] > b.f16[7] ? a.f16[7] : b.f16[7];

        print_f16(res);
}

void vmin_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] < b.f32[0] ? a.f32[0] : b.f32[0];
        res.f32[1] = a.f32[1] < b.f32[1] ? a.f32[1] : b.f32[1];
        res.f32[2] = a.f32[2] < b.f32[2] ? a.f32[2] : b.f32[2];
        res.f32[3] = a.f32[3] < b.f32[3] ? a.f32[3] : b.f32[3];

        print_f32(res);
}

void vmin_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] < b.f16[0] ? a.f16[0] : b.f16[0];
        res.f16[1] = a.f16[1] < b.f16[1] ? a.f16[1] : b.f16[1];
        res.f16[2] = a.f16[2] < b.f16[2] ? a.f16[2] : b.f16[2];
        res.f16[3] = a.f16[3] < b.f16[3] ? a.f16[3] : b.f16[3];
        res.f16[4] = a.f16[4] < b.f16[4] ? a.f16[4] : b.f16[4];
        res.f16[5] = a.f16[5] < b.f16[5] ? a.f16[5] : b.f16[5];
        res.f16[6] = a.f16[6] < b.f16[6] ? a.f16[6] : b.f16[6];
        res.f16[7] = a.f16[7] < b.f16[7] ? a.f16[7] : b.f16[7];

        print_f16(res);
}

void vmaxnm_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] > b.f32[0] ? a.f32[0] : b.f32[0];
        res.f32[1] = a.f32[1] > b.f32[1] ? a.f32[1] : b.f32[1];
        res.f32[2] = a.f32[2] > b.f32[2] ? a.f32[2] : b.f32[2];
        res.f32[3] = a.f32[3] > b.f32[3] ? a.f32[3] : b.f32[3];

        print_f32(res);
}

void vmaxnm_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] > b.f16[0] ? a.f16[0] : b.f16[0];
        res.f16[1] = a.f16[1] > b.f16[1] ? a.f16[1] : b.f16[1];
        res.f16[2] = a.f16[2] > b.f16[2] ? a.f16[2] : b.f16[2];
        res.f16[3] = a.f16[3] > b.f16[3] ? a.f16[3] : b.f16[3];
        res.f16[4] = a.f16[4] > b.f16[4] ? a.f16[4] : b.f16[4];
        res.f16[5] = a.f16[5] > b.f16[5] ? a.f16[5] : b.f16[5];
        res.f16[6] = a.f16[6] > b.f16[6] ? a.f16[6] : b.f16[6];
        res.f16[7] = a.f16[7] > b.f16[7] ? a.f16[7] : b.f16[7];

        print_f16(res);
}

void vminnm_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] < b.f32[0] ? a.f32[0] : b.f32[0];
        res.f32[1] = a.f32[1] < b.f32[1] ? a.f32[1] : b.f32[1];
        res.f32[2] = a.f32[2] < b.f32[2] ? a.f32[2] : b.f32[2];
        res.f32[3] = a.f32[3] < b.f32[3] ? a.f32[3] : b.f32[3];

        print_f32(res);
}

void vminnm_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] < b.f16[0] ? a.f16[0] : b.f16[0];
        res.f16[1] = a.f16[1] < b.f16[1] ? a.f16[1] : b.f16[1];
        res.f16[2] = a.f16[2] < b.f16[2] ? a.f16[2] : b.f16[2];
        res.f16[3] = a.f16[3] < b.f16[3] ? a.f16[3] : b.f16[3];
        res.f16[4] = a.f16[4] < b.f16[4] ? a.f16[4] : b.f16[4];
        res.f16[5] = a.f16[5] < b.f16[5] ? a.f16[5] : b.f16[5];
        res.f16[6] = a.f16[6] < b.f16[6] ? a.f16[6] : b.f16[6];
        res.f16[7] = a.f16[7] < b.f16[7] ? a.f16[7] : b.f16[7];

        print_f16(res);
}

void vpmax_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] > a.f32[1] ? a.f32[0] : a.f32[1];
        res.f32[1] = a.f32[2] > a.f32[3] ? a.f32[2] : a.f32[3];
        res.f32[2] = b.f32[0] > b.f32[1] ? b.f32[0] : b.f32[1];
        res.f32[3] = b.f32[2] > b.f32[3] ? b.f32[2] : b.f32[3];

        print_f32(res);
}

void vpmax_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] > a.f16[1] ? a.f16[0] : a.f16[1];
        res.f16[1] = a.f16[2] > a.f16[3] ? a.f16[2] : a.f16[3];
        res.f16[2] = a.f16[4] > a.f16[5] ? a.f16[4] : a.f16[5];
        res.f16[3] = a.f16[6] > a.f16[7] ? a.f16[6] : a.f16[7];
        res.f16[4] = b.f16[0] > b.f16[1] ? b.f16[0] : b.f16[1];
        res.f16[5] = b.f16[2] > b.f16[3] ? b.f16[2] : b.f16[3];
        res.f16[6] = b.f16[4] > b.f16[5] ? b.f16[4] : b.f16[5];
        res.f16[7] = b.f16[6] > b.f16[7] ? b.f16[6] : b.f16[7];

        print_f16(res);
}

void vpmin_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] < a.f32[1] ? a.f32[0] : a.f32[1];
        res.f32[1] = a.f32[2] < a.f32[3] ? a.f32[2] : a.f32[3];
        res.f32[2] = b.f32[0] < b.f32[1] ? b.f32[0] : b.f32[1];
        res.f32[3] = b.f32[2] < b.f32[3] ? b.f32[2] : b.f32[3];

        print_f32(res);
}

void vpmin_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] < a.f16[1] ? a.f16[0] : a.f16[1];
        res.f16[1] = a.f16[2] < a.f16[3] ? a.f16[2] : a.f16[3];
        res.f16[2] = a.f16[4] < a.f16[5] ? a.f16[4] : a.f16[5];
        res.f16[3] = a.f16[6] < a.f16[7] ? a.f16[6] : a.f16[7];
        res.f16[4] = b.f16[0] < b.f16[1] ? b.f16[0] : b.f16[1];
        res.f16[5] = b.f16[2] < b.f16[3] ? b.f16[2] : b.f16[3];
        res.f16[6] = b.f16[4] < b.f16[5] ? b.f16[4] : b.f16[5];
        res.f16[7] = b.f16[6] < b.f16[7] ? b.f16[6] : b.f16[7];

        print_f16(res);
}

void vcmpnez_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] != 0 ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] != 0 ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] != 0 ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] != 0 ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmpnez_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] != 0 ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] != 0 ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] != 0 ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] != 0 ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] != 0 ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] != 0 ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] != 0 ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] != 0 ? 0xffff : 0x0;

        print_f16(res);
}

void vcmpne_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] != b.f32[0] ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] != b.f32[1] ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] != b.f32[2] ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] != b.f32[3] ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmpne_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] != b.f16[0] ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] != b.f16[1] ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] != b.f16[2] ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] != b.f16[3] ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] != b.f16[4] ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] != b.f16[5] ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] != b.f16[6] ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] != b.f16[7] ? 0xffff : 0x0;

        print_f16(res);
}

void vcmphsz_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] >= 0 ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] >= 0 ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] >= 0 ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] >= 0 ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmphsz_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] >= 0 ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] >= 0 ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] >= 0 ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] >= 0 ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] >= 0 ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] >= 0 ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] >= 0 ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] >= 0 ? 0xffff : 0x0;

        print_f16(res);
}

void vcmphs_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] >= b.f32[0] ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] >= b.f32[1] ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] >= b.f32[2] ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] >= b.f32[3] ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmphs_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] >= b.f16[0] ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] >= b.f16[1] ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] >= b.f16[2] ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] >= b.f16[3] ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] >= b.f16[4] ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] >= b.f16[5] ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] >= b.f16[6] ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] >= b.f16[7] ? 0xffff : 0x0;

        print_f16(res);
}


void vcmpltz_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] < 0 ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] < 0 ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] < 0 ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] < 0 ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmpltz_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] < 0 ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] < 0 ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] < 0 ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] < 0 ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] < 0 ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] < 0 ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] < 0 ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] < 0 ? 0xffff : 0x0;

        print_f16(res);
}

void vcmplt_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] < b.f32[0] ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] < b.f32[1] ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] < b.f32[2] ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] < b.f32[3] ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmplt_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] < b.f16[0] ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] < b.f16[1] ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] < b.f16[2] ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] < b.f16[3] ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] < b.f16[4] ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] < b.f16[5] ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] < b.f16[6] ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] < b.f16[7] ? 0xffff : 0x0;

        print_f16(res);
}

void vcmphz_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] > 0 ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] > 0 ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] > 0 ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] > 0 ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmphz_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] > 0 ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] > 0 ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] > 0 ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] > 0 ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] > 0 ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] > 0 ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] > 0 ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] > 0 ? 0xffff : 0x0;

        print_f16(res);
}

void vcmplsz_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] <= 0 ? 0xffffffff : 0x0;
        res.ui32[1] = a.f32[1] <= 0 ? 0xffffffff : 0x0;
        res.ui32[2] = a.f32[2] <= 0 ? 0xffffffff : 0x0;
        res.ui32[3] = a.f32[3] <= 0 ? 0xffffffff : 0x0;

        print_f32(res);
}

void vcmplsz_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] <= 0 ? 0xffff : 0x0;
        res.ui16[1] = a.f16[1] <= 0 ? 0xffff : 0x0;
        res.ui16[2] = a.f16[2] <= 0 ? 0xffff : 0x0;
        res.ui16[3] = a.f16[3] <= 0 ? 0xffff : 0x0;
        res.ui16[4] = a.f16[4] <= 0 ? 0xffff : 0x0;
        res.ui16[5] = a.f16[5] <= 0 ? 0xffff : 0x0;
        res.ui16[6] = a.f16[6] <= 0 ? 0xffff : 0x0;
        res.ui16[7] = a.f16[7] <= 0 ? 0xffff : 0x0;

        print_f16(res);
}

void vmul_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] * b.f32[0];
        res.f32[1] = a.f32[1] * b.f32[1];
        res.f32[2] = a.f32[2] * b.f32[2];
        res.f32[3] = a.f32[3] * b.f32[3];

        print_f32(res);
}

void vmul_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] * b.f16[0];
        res.f16[1] = a.f16[1] * b.f16[1];
        res.f16[2] = a.f16[2] * b.f16[2];
        res.f16[3] = a.f16[3] * b.f16[3];
        res.f16[4] = a.f16[4] * b.f16[4];
        res.f16[5] = a.f16[5] * b.f16[5];
        res.f16[6] = a.f16[6] * b.f16[6];
        res.f16[7] = a.f16[7] * b.f16[7];

        print_f16(res);
}

void vmuli_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] * b.f32[0];
        res.f32[1] = a.f32[1] * b.f32[0];
        res.f32[2] = a.f32[2] * b.f32[0];
        res.f32[3] = a.f32[3] * b.f32[0];

        print_f32(res);
}

void vmuli_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] * b.f16[0];
        res.f16[1] = a.f16[1] * b.f16[0];
        res.f16[2] = a.f16[2] * b.f16[0];
        res.f16[3] = a.f16[3] * b.f16[0];
        res.f16[4] = a.f16[4] * b.f16[0];
        res.f16[5] = a.f16[5] * b.f16[0];
        res.f16[6] = a.f16[6] * b.f16[0];
        res.f16[7] = a.f16[7] * b.f16[0];

        print_f16(res);
}


void vmula_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] * b.f32[0] + c.f32[0];
        res.f32[1] = a.f32[1] * b.f32[1] + c.f32[1];
        res.f32[2] = a.f32[2] * b.f32[2] + c.f32[2];
        res.f32[3] = a.f32[3] * b.f32[3] + c.f32[3];

        print_f32(res);
}

void vmula_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] * b.f16[0] + c.f16[0];
        res.f16[1] = a.f16[1] * b.f16[1] + c.f16[1];
        res.f16[2] = a.f16[2] * b.f16[2] + c.f16[2];
        res.f16[3] = a.f16[3] * b.f16[3] + c.f16[3];
        res.f16[4] = a.f16[4] * b.f16[4] + c.f16[4];
        res.f16[5] = a.f16[5] * b.f16[5] + c.f16[5];
        res.f16[6] = a.f16[6] * b.f16[6] + c.f16[6];
        res.f16[7] = a.f16[7] * b.f16[7] + c.f16[7];

        print_f16(res);
}

void vmulai_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] * b.f32[0] + c.f32[0];
        res.f32[1] = a.f32[1] * b.f32[0] + c.f32[1];
        res.f32[2] = a.f32[2] * b.f32[0] + c.f32[2];
        res.f32[3] = a.f32[3] * b.f32[0] + c.f32[3];

        print_f32(res);
}

void vmulai_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] * b.f16[0] + c.f16[0];
        res.f16[1] = a.f16[1] * b.f16[0] + c.f16[1];
        res.f16[2] = a.f16[2] * b.f16[0] + c.f16[2];
        res.f16[3] = a.f16[3] * b.f16[0] + c.f16[3];
        res.f16[4] = a.f16[4] * b.f16[0] + c.f16[4];
        res.f16[5] = a.f16[5] * b.f16[0] + c.f16[5];
        res.f16[6] = a.f16[6] * b.f16[0] + c.f16[6];
        res.f16[7] = a.f16[7] * b.f16[0] + c.f16[7];

        print_f16(res);
}

void vmuls_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] - a.f32[1] * b.f32[1];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[2];
        res.f32[3] = c.f32[3] - a.f32[3] * b.f32[3];

        print_f32(res);
}

void vmuls_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] - a.f16[1] * b.f16[1];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[2];
        res.f16[3] = c.f16[3] - a.f16[3] * b.f16[3];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[4];
        res.f16[5] = c.f16[5] - a.f16[5] * b.f16[5];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[6];
        res.f16[7] = c.f16[7] - a.f16[7] * b.f16[7];

        print_f16(res);
}

void vmulsi_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[0];
        res.f32[3] = c.f32[3] - a.f32[3] * b.f32[0];

        print_f32(res);
}

void vmulsi_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[0];
        res.f16[3] = c.f16[3] - a.f16[3] * b.f16[0];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[0];
        res.f16[5] = c.f16[5] - a.f16[5] * b.f16[0];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[0];
        res.f16[7] = c.f16[7] - a.f16[7] * b.f16[0];

        print_f16(res);
}


void vfmula_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] + a.f32[1] * b.f32[1];
        res.f32[2] = c.f32[2] + a.f32[2] * b.f32[2];
        res.f32[3] = c.f32[3] + a.f32[3] * b.f32[3];

        print_f32(res);
}

void vfmula_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] + a.f16[1] * b.f16[1];
        res.f16[2] = c.f16[2] + a.f16[2] * b.f16[2];
        res.f16[3] = c.f16[3] + a.f16[3] * b.f16[3];
        res.f16[4] = c.f16[4] + a.f16[4] * b.f16[4];
        res.f16[5] = c.f16[5] + a.f16[5] * b.f16[5];
        res.f16[6] = c.f16[6] + a.f16[6] * b.f16[6];
        res.f16[7] = c.f16[7] + a.f16[7] * b.f16[7];

        print_f16(res);
}

void vfmuls_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] - a.f32[1] * b.f32[1];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[2];
        res.f32[3] = c.f32[3] - a.f32[3] * b.f32[3];

        print_f32(res);
}

void vfmuls_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] - a.f16[1] * b.f16[1];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[2];
        res.f16[3] = c.f16[3] - a.f16[3] * b.f16[3];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[4];
        res.f16[5] = c.f16[5] - a.f16[5] * b.f16[5];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[6];
        res.f16[7] = c.f16[7] - a.f16[7] * b.f16[7];

        print_f16(res);
}

void vfnmula_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = -c.f32[0] - a.f32[0] * b.f32[0];
        res.f32[1] = -c.f32[1] - a.f32[1] * b.f32[1];
        res.f32[2] = -c.f32[2] - a.f32[2] * b.f32[2];
        res.f32[3] = -c.f32[3] - a.f32[3] * b.f32[3];

        print_f32(res);
}

void vfnmula_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = -c.f16[0] - a.f16[0] * b.f16[0];
        res.f16[1] = -c.f16[1] - a.f16[1] * b.f16[1];
        res.f16[2] = -c.f16[2] - a.f16[2] * b.f16[2];
        res.f16[3] = -c.f16[3] - a.f16[3] * b.f16[3];
        res.f16[4] = -c.f16[4] - a.f16[4] * b.f16[4];
        res.f16[5] = -c.f16[5] - a.f16[5] * b.f16[5];
        res.f16[6] = -c.f16[6] - a.f16[6] * b.f16[6];
        res.f16[7] = -c.f16[7] - a.f16[7] * b.f16[7];

        print_f16(res);
}

void vfnmuls_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = -c.f32[0] + a.f32[0] * b.f32[0];
        res.f32[1] = -c.f32[1] + a.f32[1] * b.f32[1];
        res.f32[2] = -c.f32[2] + a.f32[2] * b.f32[2];
        res.f32[3] = -c.f32[3] + a.f32[3] * b.f32[3];

        print_f32(res);
}

void vfnmuls_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = -c.f16[0] + a.f16[0] * b.f16[0];
        res.f16[1] = -c.f16[1] + a.f16[1] * b.f16[1];
        res.f16[2] = -c.f16[2] + a.f16[2] * b.f16[2];
        res.f16[3] = -c.f16[3] + a.f16[3] * b.f16[3];
        res.f16[4] = -c.f16[4] + a.f16[4] * b.f16[4];
        res.f16[5] = -c.f16[5] + a.f16[5] * b.f16[5];
        res.f16[6] = -c.f16[6] + a.f16[6] * b.f16[6];
        res.f16[7] = -c.f16[7] + a.f16[7] * b.f16[7];

        print_f16(res);
}

void vfmula_f16_e(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f16[0] * b.f16[0];
        res.f32[1] = c.f32[1] + a.f16[1] * b.f16[1];
        res.f32[2] = c.f32[2] + a.f16[2] * b.f16[2];
        res.f32[3] = c.f32[3] + a.f16[3] * b.f16[3];


        print_f16(res);
}

void vfmulai_f16_e(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f16[0] * b.f16[0];
        res.f32[1] = c.f32[1] + a.f16[1] * b.f16[0];
        res.f32[2] = c.f32[2] + a.f16[2] * b.f16[0];
        res.f32[3] = c.f32[3] + a.f16[3] * b.f16[0];


        print_f16(res);
}

void vfmuls_f16_e(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f16[0] * b.f16[0];
        res.f32[1] = c.f32[1] - a.f16[1] * b.f16[1];
        res.f32[2] = c.f32[2] - a.f16[2] * b.f16[2];
        res.f32[3] = c.f32[3] - a.f16[3] * b.f16[3];


        print_f16(res);
}

void vfmulsi_f16_e(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f16[0] * b.f16[0];
        res.f32[1] = c.f32[1] - a.f16[1] * b.f16[0];
        res.f32[2] = c.f32[2] - a.f16[2] * b.f16[0];
        res.f32[3] = c.f32[3] - a.f16[3] * b.f16[0];

        print_f16(res);
}

void vfmulxaa_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] + a.f32[0] * b.f32[1];
        res.f32[2] = c.f32[2] + a.f32[2] * b.f32[2];
        res.f32[3] = c.f32[3] + a.f32[2] * b.f32[3];

        print_f32(res);
}

void vfmulxaa_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] + a.f16[0] * b.f16[1];
        res.f16[2] = c.f16[2] + a.f16[2] * b.f16[2];
        res.f16[3] = c.f16[3] + a.f16[2] * b.f16[3];
        res.f16[4] = c.f16[4] + a.f16[4] * b.f16[4];
        res.f16[5] = c.f16[5] + a.f16[4] * b.f16[5];
        res.f16[6] = c.f16[6] + a.f16[6] * b.f16[6];
        res.f16[7] = c.f16[7] + a.f16[6] * b.f16[7];

        print_f16(res);
}

void vfmulxaai_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] + a.f32[0] * b.f32[1];
        res.f32[2] = c.f32[2] + a.f32[2] * b.f32[0];
        res.f32[3] = c.f32[3] + a.f32[2] * b.f32[1];

        print_f32(res);
}

void vfmulxaai_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] + a.f16[0] * b.f16[1];
        res.f16[2] = c.f16[2] + a.f16[2] * b.f16[0];
        res.f16[3] = c.f16[3] + a.f16[2] * b.f16[1];
        res.f16[4] = c.f16[4] + a.f16[4] * b.f16[0];
        res.f16[5] = c.f16[5] + a.f16[4] * b.f16[1];
        res.f16[6] = c.f16[6] + a.f16[6] * b.f16[0];
        res.f16[7] = c.f16[7] + a.f16[6] * b.f16[1];

        print_f16(res);
}


void vfmulxas_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] + a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] - a.f32[3] * b.f32[3];
        res.f32[3] = c.f32[3] + a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfmulxas_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] + a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] - a.f16[3] * b.f16[3];
        res.f16[3] = c.f16[3] + a.f16[3] * b.f16[2];
        res.f16[4] = c.f16[4] - a.f16[5] * b.f16[5];
        res.f16[5] = c.f16[5] + a.f16[5] * b.f16[4];
        res.f16[6] = c.f16[6] - a.f16[7] * b.f16[7];
        res.f16[7] = c.f16[7] + a.f16[7] * b.f16[6];

        print_f16(res);
}

void vfmulxasi_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] + a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] - a.f32[3] * b.f32[1];
        res.f32[3] = c.f32[3] + a.f32[3] * b.f32[0];

        print_f32(res);
}

void vfmulxasi_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] + a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] - a.f16[3] * b.f16[1];
        res.f16[3] = c.f16[3] + a.f16[3] * b.f16[0];
        res.f16[4] = c.f16[4] - a.f16[5] * b.f16[1];
        res.f16[5] = c.f16[5] + a.f16[5] * b.f16[0];
        res.f16[6] = c.f16[6] - a.f16[7] * b.f16[1];
        res.f16[7] = c.f16[7] + a.f16[7] * b.f16[0];

        print_f16(res);
}

void vfmulxss_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] - a.f32[0] * b.f32[1];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[2];
        res.f32[3] = c.f32[3] - a.f32[2] * b.f32[3];

        print_f32(res);
}

void vfmulxss_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] - a.f16[0] * b.f16[1];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[2];
        res.f16[3] = c.f16[3] - a.f16[2] * b.f16[3];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[4];
        res.f16[5] = c.f16[5] - a.f16[4] * b.f16[5];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[6];
        res.f16[7] = c.f16[7] - a.f16[6] * b.f16[7];

        print_f16(res);
}

void vfmulxssi_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0];
        res.f32[1] = c.f32[1] - a.f32[0] * b.f32[1];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[0];
        res.f32[3] = c.f32[3] - a.f32[2] * b.f32[1];

        print_f32(res);
}

void vfmulxssi_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0];
        res.f16[1] = c.f16[1] - a.f16[0] * b.f16[1];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[0];
        res.f16[3] = c.f16[3] - a.f16[2] * b.f16[1];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[0];
        res.f16[5] = c.f16[5] - a.f16[4] * b.f16[1];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[0];
        res.f16[7] = c.f16[7] - a.f16[6] * b.f16[1];

        print_f16(res);
}


void vfmulxsa_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] + a.f32[3] * b.f32[3];
        res.f32[3] = c.f32[3] - a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfmulxsa_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] + a.f16[3] * b.f16[3];
        res.f16[3] = c.f16[3] - a.f16[3] * b.f16[2];
        res.f16[4] = c.f16[4] + a.f16[5] * b.f16[5];
        res.f16[5] = c.f16[5] - a.f16[5] * b.f16[4];
        res.f16[6] = c.f16[6] + a.f16[7] * b.f16[7];
        res.f16[7] = c.f16[7] - a.f16[7] * b.f16[6];

        print_f16(res);
}

void vfmulxsai_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] + a.f32[3] * b.f32[1];
        res.f32[3] = c.f32[3] - a.f32[3] * b.f32[0];

        print_f32(res);
}

void vfmulxsai_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] + a.f16[3] * b.f16[1];
        res.f16[3] = c.f16[3] - a.f16[3] * b.f16[0];
        res.f16[4] = c.f16[4] + a.f16[5] * b.f16[1];
        res.f16[5] = c.f16[5] - a.f16[5] * b.f16[0];
        res.f16[6] = c.f16[6] + a.f16[7] * b.f16[1];
        res.f16[7] = c.f16[7] - a.f16[7] * b.f16[0];

        print_f16(res);
}


void vfcmul_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] * b.f32[0] - a.f32[1] * b.f32[1];
        res.f32[1] = a.f32[0] * b.f32[1] + a.f32[1] * b.f32[0];
        res.f32[2] = a.f32[2] * b.f32[2] - a.f32[3] * b.f32[3];
        res.f32[3] = a.f32[2] * b.f32[3] + a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmul_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] * b.f16[0] - a.f16[1] * b.f16[1];
        res.f16[1] = a.f16[0] * b.f16[1] + a.f16[1] * b.f16[0];
        res.f16[2] = a.f16[2] * b.f16[2] - a.f16[3] * b.f16[3];
        res.f16[3] = a.f16[2] * b.f16[3] + a.f16[3] * b.f16[2];
        res.f16[4] = a.f16[4] * b.f16[4] - a.f16[5] * b.f16[5];
        res.f16[5] = a.f16[4] * b.f16[5] + a.f16[5] * b.f16[4];
        res.f16[6] = a.f16[6] * b.f16[6] - a.f16[7] * b.f16[7];
        res.f16[7] = a.f16[6] * b.f16[7] + a.f16[7] * b.f16[6];

        print_f16(res);
}

void vfcmula_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[0] * b.f32[0] - a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] + a.f32[0] * b.f32[1] + a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] + a.f32[2] * b.f32[2] - a.f32[3] * b.f32[3];
        res.f32[3] = c.f32[3] + a.f32[2] * b.f32[3] + a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmula_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[0] * b.f16[0] - a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] + a.f16[0] * b.f16[1] + a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] + a.f16[2] * b.f16[2] - a.f16[3] * b.f16[3];
        res.f16[3] = c.f16[3] + a.f16[2] * b.f16[3] + a.f16[3] * b.f16[2];
        res.f16[4] = c.f16[4] + a.f16[4] * b.f16[4] - a.f16[5] * b.f16[5];
        res.f16[5] = c.f16[5] + a.f16[4] * b.f16[5] + a.f16[5] * b.f16[4];
        res.f16[6] = c.f16[6] + a.f16[6] * b.f16[6] - a.f16[7] * b.f16[7];
        res.f16[7] = c.f16[7] + a.f16[6] * b.f16[7] + a.f16[7] * b.f16[6];

        print_f16(res);
}


void vfcmulc_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f32[0] * b.f32[0] + a.f32[1] * b.f32[1];
        res.f32[1] = a.f32[0] * b.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = a.f32[2] * b.f32[2] + a.f32[3] * b.f32[3];
        res.f32[3] = a.f32[2] * b.f32[3] - a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmulc_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f16[0] * b.f16[0] + a.f16[1] * b.f16[1];
        res.f16[1] = a.f16[0] * b.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = a.f16[2] * b.f16[2] + a.f16[3] * b.f16[3];
        res.f16[3] = a.f16[2] * b.f16[3] - a.f16[3] * b.f16[2];
        res.f16[4] = a.f16[4] * b.f16[4] + a.f16[5] * b.f16[5];
        res.f16[5] = a.f16[4] * b.f16[5] - a.f16[5] * b.f16[4];
        res.f16[6] = a.f16[6] * b.f16[6] + a.f16[7] * b.f16[7];
        res.f16[7] = a.f16[6] * b.f16[7] - a.f16[7] * b.f16[6];

        print_f16(res);
}

void vfcmulca_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] + a.f32[0] * b.f32[0] + a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] + a.f32[0] * b.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] + a.f32[2] * b.f32[2] + a.f32[3] * b.f32[3];
        res.f32[3] = c.f32[3] + a.f32[2] * b.f32[3] - a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmulca_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] + a.f16[0] * b.f16[0] + a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] + a.f16[0] * b.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] + a.f16[2] * b.f16[2] + a.f16[3] * b.f16[3];
        res.f16[3] = c.f16[3] + a.f16[2] * b.f16[3] - a.f16[3] * b.f16[2];
        res.f16[4] = c.f16[4] + a.f16[4] * b.f16[4] + a.f16[5] * b.f16[5];
        res.f16[5] = c.f16[5] + a.f16[4] * b.f16[5] - a.f16[5] * b.f16[4];
        res.f16[6] = c.f16[6] + a.f16[6] * b.f16[6] + a.f16[7] * b.f16[7];
        res.f16[7] = c.f16[7] + a.f16[6] * b.f16[7] - a.f16[7] * b.f16[6];

        print_f16(res);
}



void vfcmuln_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = -a.f32[0] * b.f32[0] + a.f32[1] * b.f32[1];
        res.f32[1] = -a.f32[0] * b.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = -a.f32[2] * b.f32[2] + a.f32[3] * b.f32[3];
        res.f32[3] = -a.f32[2] * b.f32[3] - a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmuln_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = -a.f16[0] * b.f16[0] + a.f16[1] * b.f16[1];
        res.f16[1] = -a.f16[0] * b.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = -a.f16[2] * b.f16[2] + a.f16[3] * b.f16[3];
        res.f16[3] = -a.f16[2] * b.f16[3] - a.f16[3] * b.f16[2];
        res.f16[4] = -a.f16[4] * b.f16[4] + a.f16[5] * b.f16[5];
        res.f16[5] = -a.f16[4] * b.f16[5] - a.f16[5] * b.f16[4];
        res.f16[6] = -a.f16[6] * b.f16[6] + a.f16[7] * b.f16[7];
        res.f16[7] = -a.f16[6] * b.f16[7] - a.f16[7] * b.f16[6];

        print_f16(res);
}

void vfcmulna_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0] + a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] - a.f32[0] * b.f32[1] - a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[2] + a.f32[3] * b.f32[3];
        res.f32[3] = c.f32[3] - a.f32[2] * b.f32[3] - a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmulna_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0] + a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] - a.f16[0] * b.f16[1] - a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[2] + a.f16[3] * b.f16[3];
        res.f16[3] = c.f16[3] - a.f16[2] * b.f16[3] - a.f16[3] * b.f16[2];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[4] + a.f16[5] * b.f16[5];
        res.f16[5] = c.f16[5] - a.f16[4] * b.f16[5] - a.f16[5] * b.f16[4];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[6] + a.f16[7] * b.f16[7];
        res.f16[7] = c.f16[7] - a.f16[6] * b.f16[7] - a.f16[7] * b.f16[6];

        print_f16(res);
}


void vfcmulcn_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = -a.f32[0] * b.f32[0] - a.f32[1] * b.f32[1];
        res.f32[1] = -a.f32[0] * b.f32[1] + a.f32[1] * b.f32[0];
        res.f32[2] = -a.f32[2] * b.f32[2] - a.f32[3] * b.f32[3];
        res.f32[3] = -a.f32[2] * b.f32[3] + a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmulcn_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = -a.f16[0] * b.f16[0] - a.f16[1] * b.f16[1];
        res.f16[1] = -a.f16[0] * b.f16[1] + a.f16[1] * b.f16[0];
        res.f16[2] = -a.f16[2] * b.f16[2] - a.f16[3] * b.f16[3];
        res.f16[3] = -a.f16[2] * b.f16[3] + a.f16[3] * b.f16[2];
        res.f16[4] = -a.f16[4] * b.f16[4] - a.f16[5] * b.f16[5];
        res.f16[5] = -a.f16[4] * b.f16[5] + a.f16[5] * b.f16[4];
        res.f16[6] = -a.f16[6] * b.f16[6] - a.f16[7] * b.f16[7];
        res.f16[7] = -a.f16[6] * b.f16[7] + a.f16[7] * b.f16[6];

        print_f16(res);
}

void vfcmulcna_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = c.f32[0] - a.f32[0] * b.f32[0] - a.f32[1] * b.f32[1];
        res.f32[1] = c.f32[1] - a.f32[0] * b.f32[1] + a.f32[1] * b.f32[0];
        res.f32[2] = c.f32[2] - a.f32[2] * b.f32[2] - a.f32[3] * b.f32[3];
        res.f32[3] = c.f32[3] - a.f32[2] * b.f32[3] + a.f32[3] * b.f32[2];

        print_f32(res);
}

void vfcmulcna_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = c.f16[0] - a.f16[0] * b.f16[0] - a.f16[1] * b.f16[1];
        res.f16[1] = c.f16[1] - a.f16[0] * b.f16[1] + a.f16[1] * b.f16[0];
        res.f16[2] = c.f16[2] - a.f16[2] * b.f16[2] - a.f16[3] * b.f16[3];
        res.f16[3] = c.f16[3] - a.f16[2] * b.f16[3] + a.f16[3] * b.f16[2];
        res.f16[4] = c.f16[4] - a.f16[4] * b.f16[4] - a.f16[5] * b.f16[5];
        res.f16[5] = c.f16[5] - a.f16[4] * b.f16[5] + a.f16[5] * b.f16[4];
        res.f16[6] = c.f16[6] - a.f16[6] * b.f16[6] - a.f16[7] * b.f16[7];
        res.f16[7] = c.f16[7] - a.f16[6] * b.f16[7] + a.f16[7] * b.f16[6];

        print_f16(res);
}



void vrecpe_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si32[0] = 0x7ef0a3d7 - a.si32[0];
        res.si32[1] = 0x7ef0a3d7 - a.si32[1];
        res.si32[2] = 0x7ef0a3d7 - a.si32[2];
        res.si32[3] = 0x7ef0a3d7 - a.si32[3];

        print_f32(res);
}

void vrecpe_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si16[0] = 0x7785 - a.si16[0];
        res.si16[1] = 0x7785 - a.si16[1];
        res.si16[2] = 0x7785 - a.si16[2];
        res.si16[3] = 0x7785 - a.si16[3];
        res.si16[4] = 0x7785 - a.si16[4];
        res.si16[5] = 0x7785 - a.si16[5];
        res.si16[6] = 0x7785 - a.si16[6];
        res.si16[7] = 0x7785 - a.si16[7];

        print_f16(res);
}

void vrecps_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = 2 - a.f32[0] * b.f32[0];
        res.f32[1] = 2 - a.f32[1] * b.f32[1];
        res.f32[2] = 2 - a.f32[2] * b.f32[2];
        res.f32[3] = 2 - a.f32[3] * b.f32[3];

        print_f32(res);
}

void vrecps_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = 2 - a.f16[0] * b.f16[0];
        res.f16[1] = 2 - a.f16[1] * b.f16[1];
        res.f16[2] = 2 - a.f16[2] * b.f16[2];
        res.f16[3] = 2 - a.f16[3] * b.f16[3];
        res.f16[4] = 2 - a.f16[4] * b.f16[4];
        res.f16[5] = 2 - a.f16[5] * b.f16[5];
        res.f16[6] = 2 - a.f16[6] * b.f16[6];
        res.f16[7] = 2 - a.f16[7] * b.f16[7];

        print_f16(res);
}


void vrsqrte_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si32[0] = 0x5f37642f - (a.si32[0] >> 1);
        res.si32[1] = 0x5f37642f - (a.si32[1] >> 1);
        res.si32[2] = 0x5f37642f - (a.si32[2] >> 1);
        res.si32[3] = 0x5f37642f - (a.si32[3] >> 1);

        print_f32(res);
}

void vrsqrte_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si16[0] = 0x59bb - (a.si16[0] >> 1);
        res.si16[1] = 0x59bb - (a.si16[1] >> 1);
        res.si16[2] = 0x59bb - (a.si16[2] >> 1);
        res.si16[3] = 0x59bb - (a.si16[3] >> 1);
        res.si16[4] = 0x59bb - (a.si16[4] >> 1);
        res.si16[5] = 0x59bb - (a.si16[5] >> 1);
        res.si16[6] = 0x59bb - (a.si16[6] >> 1);
        res.si16[7] = 0x59bb - (a.si16[7] >> 1);

        print_f16(res);
}

void vrsqrts_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = 1.5 - a.f32[0] * b.f32[0] / 2;
        res.f32[1] = 1.5 - a.f32[1] * b.f32[1] / 2;
        res.f32[2] = 1.5 - a.f32[2] * b.f32[2] / 2;
        res.f32[3] = 1.5 - a.f32[3] * b.f32[3] / 2;

        print_f32(res);
}

void vrsqrts_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = 1.5 - a.f16[0] * b.f16[0] / 2;
        res.f16[1] = 1.5 - a.f16[1] * b.f16[1] / 2;
        res.f16[2] = 1.5 - a.f16[2] * b.f16[2] / 2;
        res.f16[3] = 1.5 - a.f16[3] * b.f16[3] / 2;
        res.f16[4] = 1.5 - a.f16[4] * b.f16[4] / 2;
        res.f16[5] = 1.5 - a.f16[5] * b.f16[5] / 2;
        res.f16[6] = 1.5 - a.f16[6] * b.f16[6] / 2;
        res.f16[7] = 1.5 - a.f16[7] * b.f16[7] / 2;

        print_f16(res);
}

void vexpe_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        a.f32[0] = a.f32[0] / 30000;
        a.f32[1] = a.f32[1] / 30000;
        a.f32[2] = a.f32[2] / 30000;
        a.f32[3] = a.f32[3] / 30000;
        print_f32(a);
        res.si32[0] = 1064807268.539173f + 12102203.161561f * a.f32[0];
        res.si32[1] = 1064807268.539173f + 12102203.161561f * a.f32[1];
        res.si32[2] = 1064807268.539173f + 12102203.161561f * a.f32[2];
        res.si32[3] = 1064807268.539173f + 12102203.161561f * a.f32[3];

        print_f32(res);
}

void vexpe_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        a.f16[0] = a.f16[0] / 10;
        a.f16[1] = a.f16[1] / 10;
        a.f16[2] = a.f16[2] / 10;
        a.f16[3] = a.f16[3] / 10;
        a.f16[4] = a.f16[4] / 10;
        a.f16[5] = a.f16[5] / 10;
        a.f16[6] = a.f16[6] / 10;
        a.f16[7] = a.f16[7] / 10;
        print_f16(a);

        res.si16[0] = 15293.356023f + 1477.319722f * a.f16[0];
        res.si16[1] = 15293.356023f + 1477.319722f * a.f16[1];
        res.si16[2] = 15293.356023f + 1477.319722f * a.f16[2];
        res.si16[3] = 15293.356023f + 1477.319722f * a.f16[3];
        res.si16[4] = 15293.356023f + 1477.319722f * a.f16[4];
        res.si16[5] = 15293.356023f + 1477.319722f * a.f16[5];
        res.si16[6] = 15293.356023f + 1477.319722f * a.f16[6];
        res.si16[7] = 15293.356023f + 1477.319722f * a.f16[7];

        print_f16(res);
}


void vhtos_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f16[0];
        res.f32[1] = a.f16[1];
        res.f32[2] = a.f16[2];
        res.f32[3] = a.f16[3];
        print_f32(res);

        res.f32[0] = a.f16[4];
        res.f32[1] = a.f16[5];
        res.f32[2] = a.f16[6];
        res.f32[3] = a.f16[7];
        print_f32(res);
}

void vstoh_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.f32[0];
        res.f16[1] = a.f32[1];
        res.f16[2] = a.f32[2];
        res.f16[3] = a.f32[3];
        print_f16(res);
}

void vdtos_f64(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.f64[0];
        res.f32[1] = a.f64[1];
        print_f32(res);
}


void vftox_f32_s32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si32[0] = a.f32[0] * 32;
        res.si32[1] = a.f32[1] * 32;
        res.si32[2] = a.f32[2] * 32;
        res.si32[3] = a.f32[3] * 32;

        print_f32(res);
}

void vftox_f32_u32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0] * 32;
        res.ui32[1] = a.f32[1] * 32;
        res.ui32[2] = a.f32[2] * 32;
        res.ui32[3] = a.f32[3] * 32;

        print_f32(res);
}

void vftox_f16_s16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si16[0] = a.f16[0] * 32;
        res.si16[1] = a.f16[1] * 32;
        res.si16[2] = a.f16[2] * 32;
        res.si16[3] = a.f16[3] * 32;
        res.si16[4] = a.f16[4] * 32;
        res.si16[5] = a.f16[5] * 32;
        res.si16[6] = a.f16[6] * 32;
        res.si16[7] = a.f16[7] * 32;

        print_f16(res);
}

void vftox_f16_u16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0] * 32;
        res.ui16[1] = a.f16[1] * 32;
        res.ui16[2] = a.f16[2] * 32;
        res.ui16[3] = a.f16[3] * 32;
        res.ui16[4] = a.f16[4] * 32;
        res.ui16[5] = a.f16[5] * 32;
        res.ui16[6] = a.f16[6] * 32;
        res.ui16[7] = a.f16[7] * 32;

        print_f16(res);
}

void vftox_f16_s32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si32[0] = a.f16[0] * 32;
        res.si32[1] = a.f16[1] * 32;
        res.si32[2] = a.f16[2] * 32;
        res.si32[3] = a.f16[3] * 32;

        print_f32(res);

        res.si32[0] = a.f16[4] * 32;
        res.si32[1] = a.f16[5] * 32;
        res.si32[2] = a.f16[6] * 32;
        res.si32[3] = a.f16[7] * 32;

        print_f32(res);
}

void vftox_f16_u32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f16[0] * 32;
        res.ui32[1] = a.f16[1] * 32;
        res.ui32[2] = a.f16[2] * 32;
        res.ui32[3] = a.f16[3] * 32;

        print_f32(res);

        res.ui32[0] = a.f16[4] * 32;
        res.ui32[1] = a.f16[5] * 32;
        res.ui32[2] = a.f16[6] * 32;
        res.ui32[3] = a.f16[7] * 32;

        print_f32(res);
}

void vftox_f32_s16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si16[0] = a.f32[0] * 32;
        res.si16[1] = a.f32[1] * 32;
        res.si16[2] = a.f32[2] * 32;
        res.si16[3] = a.f32[3] * 32;

        print_f16(res);
}

void vftox_f32_u16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f32[0] * 32;
        res.ui16[1] = a.f32[1] * 32;
        res.ui16[2] = a.f32[2] * 32;
        res.ui16[3] = a.f32[3] * 32;

        print_f16(res);
}

void vxtof_s32_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.si32[0] / 32.0;
        res.f32[1] = a.si32[1] / 32.0;
        res.f32[2] = a.si32[2] / 32.0;
        res.f32[3] = a.si32[3] / 32.0;

        print_f32(res);
}

void vxtof_u32_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.ui32[0] / 32.0;
        res.f32[1] = a.ui32[1] / 32.0;
        res.f32[2] = a.ui32[2] / 32.0;
        res.f32[3] = a.ui32[3] / 32.0;

        print_f32(res);
}

void vxtof_s16_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.si16[0] / 32.0;
        res.f16[1] = a.si16[1] / 32.0;
        res.f16[2] = a.si16[2] / 32.0;
        res.f16[3] = a.si16[3] / 32.0;
        res.f16[4] = a.si16[4] / 32.0;
        res.f16[5] = a.si16[5] / 32.0;
        res.f16[6] = a.si16[6] / 32.0;
        res.f16[7] = a.si16[7] / 32.0;

        print_f16(res);
}

void vxtof_u16_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.ui16[0] / 32.0;
        res.f16[1] = a.ui16[1] / 32.0;
        res.f16[2] = a.ui16[2] / 32.0;
        res.f16[3] = a.ui16[3] / 32.0;
        res.f16[4] = a.ui16[4] / 32.0;
        res.f16[5] = a.ui16[5] / 32.0;
        res.f16[6] = a.ui16[6] / 32.0;
        res.f16[7] = a.ui16[7] / 32.0;

        print_f16(res);
}

void vxtof_s16_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.si16[0] / 32.0;
        res.f32[1] = a.si16[1] / 32.0;
        res.f32[2] = a.si16[2] / 32.0;
        res.f32[3] = a.si16[3] / 32.0;

        print_f32(res);

        res.f32[0] = a.si16[4] / 32.0;
        res.f32[1] = a.si16[5] / 32.0;
        res.f32[2] = a.si16[6] / 32.0;
        res.f32[3] = a.si16[7] / 32.0;

        print_f32(res);
}

void vxtof_u16_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.ui16[0] / 32.0;
        res.f32[1] = a.ui16[1] / 32.0;
        res.f32[2] = a.ui16[2] / 32.0;
        res.f32[3] = a.ui16[3] / 32.0;

        print_f32(res);

        res.f32[0] = a.ui16[4] / 32.0;
        res.f32[1] = a.ui16[5] / 32.0;
        res.f32[2] = a.ui16[6] / 32.0;
        res.f32[3] = a.ui16[7] / 32.0;

        print_f32(res);
}

void vxtof_s32_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.si32[0] / 32.0;
        res.f16[1] = a.si32[1] / 32.0;
        res.f16[2] = a.si32[2] / 32.0;
        res.f16[3] = a.si32[3] / 32.0;

        print_f16(res);
}

void vxtof_u32_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.ui32[0] / 32.0;
        res.f16[1] = a.ui32[1] / 32.0;
        res.f16[2] = a.ui32[2] / 32.0;
        res.f16[3] = a.ui32[3] / 32.0;

        print_f16(res);
}




void vftoi_f32_s32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si32[0] = a.f32[0];
        res.si32[1] = a.f32[1];
        res.si32[2] = a.f32[2];
        res.si32[3] = a.f32[3];

        print_f32(res);
}

void vftoi_f32_u32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f32[0];
        res.ui32[1] = a.f32[1];
        res.ui32[2] = a.f32[2];
        res.ui32[3] = a.f32[3];

        print_f32(res);
}

void vftoi_f16_s16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si16[0] = a.f16[0];
        res.si16[1] = a.f16[1];
        res.si16[2] = a.f16[2];
        res.si16[3] = a.f16[3];
        res.si16[4] = a.f16[4];
        res.si16[5] = a.f16[5];
        res.si16[6] = a.f16[6];
        res.si16[7] = a.f16[7];

        print_f16(res);
}

void vftoi_f16_u16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f16[0];
        res.ui16[1] = a.f16[1];
        res.ui16[2] = a.f16[2];
        res.ui16[3] = a.f16[3];
        res.ui16[4] = a.f16[4];
        res.ui16[5] = a.f16[5];
        res.ui16[6] = a.f16[6];
        res.ui16[7] = a.f16[7];

        print_f16(res);
}

void vftoi_f16_s32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si32[0] = a.f16[0];
        res.si32[1] = a.f16[1];
        res.si32[2] = a.f16[2];
        res.si32[3] = a.f16[3];

        print_f32(res);

        res.si32[0] = a.f16[4];
        res.si32[1] = a.f16[5];
        res.si32[2] = a.f16[6];
        res.si32[3] = a.f16[7];

        print_f32(res);
}

void vftoi_f16_u32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui32[0] = a.f16[0];
        res.ui32[1] = a.f16[1];
        res.ui32[2] = a.f16[2];
        res.ui32[3] = a.f16[3];

        print_f32(res);

        res.ui32[0] = a.f16[4];
        res.ui32[1] = a.f16[5];
        res.ui32[2] = a.f16[6];
        res.ui32[3] = a.f16[7];

        print_f32(res);
}

void vftoi_f32_s16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.si16[0] = a.f32[0];
        res.si16[1] = a.f32[1];
        res.si16[2] = a.f32[2];
        res.si16[3] = a.f32[3];

        print_f16(res);
}

void vftoi_f32_u16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.ui16[0] = a.f32[0];
        res.ui16[1] = a.f32[1];
        res.ui16[2] = a.f32[2];
        res.ui16[3] = a.f32[3];

        print_f16(res);
}

void vitof_s32_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.si32[0];
        res.f32[1] = a.si32[1];
        res.f32[2] = a.si32[2];
        res.f32[3] = a.si32[3];

        print_f32(res);
}

void vitof_u32_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.ui32[0];
        res.f32[1] = a.ui32[1];
        res.f32[2] = a.ui32[2];
        res.f32[3] = a.ui32[3];

        print_f32(res);
}

void vitof_s16_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.si16[0];
        res.f16[1] = a.si16[1];
        res.f16[2] = a.si16[2];
        res.f16[3] = a.si16[3];
        res.f16[4] = a.si16[4];
        res.f16[5] = a.si16[5];
        res.f16[6] = a.si16[6];
        res.f16[7] = a.si16[7];

        print_f16(res);
}

void vitof_u16_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.ui16[0];
        res.f16[1] = a.ui16[1];
        res.f16[2] = a.ui16[2];
        res.f16[3] = a.ui16[3];
        res.f16[4] = a.ui16[4];
        res.f16[5] = a.ui16[5];
        res.f16[6] = a.ui16[6];
        res.f16[7] = a.ui16[7];

        print_f16(res);
}

void vitof_s16_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.si16[0];
        res.f32[1] = a.si16[1];
        res.f32[2] = a.si16[2];
        res.f32[3] = a.si16[3];

        print_f32(res);

        res.f32[0] = a.si16[4];
        res.f32[1] = a.si16[5];
        res.f32[2] = a.si16[6];
        res.f32[3] = a.si16[7];

        print_f32(res);
}

void vitof_u16_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = a.ui16[0];
        res.f32[1] = a.ui16[1];
        res.f32[2] = a.ui16[2];
        res.f32[3] = a.ui16[3];

        print_f32(res);

        res.f32[0] = a.ui16[4];
        res.f32[1] = a.ui16[5];
        res.f32[2] = a.ui16[6];
        res.f32[3] = a.ui16[7];

        print_f32(res);
}

void vitof_s32_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.si32[0];
        res.f16[1] = a.si32[1];
        res.f16[2] = a.si32[2];
        res.f16[3] = a.si32[3];

        print_f16(res);
}

void vitof_u32_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = a.ui32[0];
        res.f16[1] = a.ui32[1];
        res.f16[2] = a.ui32[2];
        res.f16[3] = a.ui32[3];

        print_f16(res);
}



void vmovi_f32(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f32[0] = -1.5;
        res.f32[1] = -1.5;
        res.f32[2] = -1.5;
        res.f32[3] = -1.5;

        print_f32(res);
}

void vmovi_f16(union reg128 a, union reg128 b, union reg128 c)
{
        union reg128 res;

        res.f16[0] = -1.5;
        res.f16[1] = -1.5;
        res.f16[2] = -1.5;
        res.f16[3] = -1.5;
        res.f16[4] = -1.5;
        res.f16[5] = -1.5;
        res.f16[6] = -1.5;
        res.f16[7] = -1.5;

        print_f16(res);
}


void do_f32_test(union reg128 a, union reg128 b, union reg128 c)
{
        printf("vadd\n");       vadd_f32(a, b, c);
        printf("vsub\n");       vsub_f32(a, b, c);
        printf("vpadd\n");      vpadd_f32(a, b, c);
        printf("vasx\n");       vasx_f32(a, b, c);
        printf("vsax\n");       vsax_f32(a, b, c);
        printf("vabs\n");       vabs_f32(a, b, c);
        printf("vsabs\n");      vsabs_f32(a, b, c);
        printf("vneg\n");       vneg_f32(a, b, c);
        printf("vmax\n");       vmax_f32(a, b, c);
        printf("vmin\n");       vmin_f32(a, b, c);
        printf("vmaxnm\n");     vmaxnm_f32(a, b, c);
        printf("vminnm\n");     vminnm_f32(a, b, c);
        printf("vpmax\n");      vpmax_f32(a, b, c);
        printf("vpmin\n");      vpmin_f32(a, b, c);
        printf("vcmpnez\n");    vcmpnez_f32(a, b, c);
        printf("vcmpne\n");     vcmpne_f32(a, b, c);
        printf("vcmphsz\n");    vcmphsz_f32(a, b, c);
        printf("vcmphs\n");     vcmphs_f32(a, b, c);
        printf("vcmpltz\n");    vcmpltz_f32(a, b, c);
        printf("vcmplt\n");     vcmplt_f32(a, b, c);
        printf("vcmphz\n");     vcmphz_f32(a, b, c);
        printf("vcmplsz\n");    vcmplsz_f32(a, b, c);
        printf("vmul\n");       vmul_f32(a, b, c);
        printf("vmuli\n");      vmuli_f32(a, b, c);
        printf("vmula\n");      vmula_f32(a, b, c);
        printf("vmulai\n");     vmulai_f32(a, b, c);
        printf("vmuls\n");      vmuls_f32(a, b, c);
        printf("vmulsi\n");     vmulsi_f32(a, b, c);
        printf("vfmula\n");     vfmula_f32(a, b, c);
        printf("vfmuls\n");     vfmuls_f32(a, b, c);
        printf("vfnmula\n");    vfnmula_f32(a, b, c);
        printf("vfnmuls\n");    vfnmuls_f32(a, b, c);
        printf("vfmulxaa\n");   vfmulxaa_f32(a, b, c);
        printf("vfmulxaai\n");  vfmulxaai_f32(a, b, c);
        printf("vfmulxas\n");   vfmulxas_f32(a, b, c);
        printf("vfmulxasi\n");  vfmulxasi_f32(a, b, c);
        printf("vfmulxsa\n");   vfmulxsa_f32(a, b, c);
        printf("vfmulxsai\n");  vfmulxsai_f32(a, b, c);
        printf("vfmulxss\n");   vfmulxss_f32(a, b, c);
        printf("vfmulxssi\n");  vfmulxssi_f32(a, b, c);
        printf("vfcmul\n");     vfcmul_f32(a, b, c);
        printf("vfcmula\n");    vfcmula_f32(a, b, c);
        printf("vfcmulc\n");    vfcmulc_f32(a, b, c);
        printf("vfcmulca\n");   vfcmulca_f32(a, b, c);
        printf("vfcmuln\n");    vfcmuln_f32(a, b, c);
        printf("vfcmulna\n");   vfcmulna_f32(a, b, c);
        printf("vfcmulcn\n");   vfcmulcn_f32(a, b, c);
        printf("vfcmulcna\n");  vfcmulcna_f32(a, b, c);
        printf("vrecpe\n");     vrecpe_f32(a, b, c);
        printf("vrecps\n");     vrecps_f32(a, b, c);
        printf("vrsqrte\n");    vrsqrte_f32(a, b, c);
        printf("vrsqrts\n");    vrsqrts_f32(a, b, c);
        printf("vexpe\n");      vexpe_f32(a, b, c);
}

void do_f16_test(union reg128 a, union reg128 b, union reg128 c)
{
        printf("vadd\n");       vadd_f16(a, b, c);
        printf("vsub\n");       vsub_f16(a, b, c);
        printf("vpadd\n");      vpadd_f16(a, b, c);
        printf("vasx\n");       vasx_f16(a, b, c);
        printf("vsax\n");       vsax_f16(a, b, c);
        printf("vabs\n");       vabs_f16(a, b, c);
        printf("vsabs\n");      vsabs_f16(a, b, c);
        printf("vneg\n");       vneg_f16(a, b, c);
        printf("vmax\n");       vmax_f16(a, b, c);
        printf("vmin\n");       vmin_f16(a, b, c);
        printf("vmaxnm\n");     vmaxnm_f16(a, b, c);
        printf("vminnm\n");     vminnm_f16(a, b, c);
        printf("vpmax\n");      vpmax_f16(a, b, c);
        printf("vpmin\n");      vpmin_f16(a, b, c);
        printf("vcmpnez\n");    vcmpnez_f16(a, b, c);
        printf("vcmpne\n");     vcmpne_f16(a, b, c);
        printf("vcmphsz\n");    vcmphsz_f16(a, b, c);
        printf("vcmphs\n");     vcmphs_f16(a, b, c);
        printf("vcmpltz\n");    vcmpltz_f16(a, b, c);
        printf("vcmplt\n");     vcmplt_f16(a, b, c);
        printf("vcmphz\n");     vcmphz_f16(a, b, c);
        printf("vcmplsz\n");    vcmplsz_f16(a, b, c);
        printf("vmul\n");       vmul_f16(a, b, c);
        printf("vmuli\n");      vmuli_f16(a, b, c);
        printf("vmula\n");      vmula_f16(a, b, c);
        printf("vmulai\n");     vmulai_f16(a, b, c);
        printf("vmuls\n");      vmuls_f16(a, b, c);
        printf("vmulsi\n");     vmulsi_f16(a, b, c);
        printf("vfmula\n");     vfmula_f16(a, b, c);
        printf("vfmuls\n");     vfmuls_f16(a, b, c);
        printf("vfnmula\n");    vfnmula_f16(a, b, c);
        printf("vfnmuls\n");    vfnmuls_f16(a, b, c);
        printf("vfmula.t.e\n"); vfmula_f16_e(a, b, c);
        printf("vfmulai.t.e\n");vfmulai_f16_e(a, b, c);
        printf("vfmuls.t.e\n"); vfmuls_f16_e(a, b, c);
        printf("vfmulsi.t.e\n");vfmulsi_f16_e(a, b, c);
        printf("vfmulxaa\n");   vfmulxaa_f16(a, b, c);
        printf("vfmulxaai\n");  vfmulxaai_f16(a, b, c);
        printf("vfmulxas\n");   vfmulxas_f16(a, b, c);
        printf("vfmulxasi\n");  vfmulxasi_f16(a, b, c);
        printf("vfmulxsa\n");   vfmulxsa_f16(a, b, c);
        printf("vfmulxsai\n");  vfmulxsai_f16(a, b, c);
        printf("vfmulxss\n");   vfmulxss_f16(a, b, c);
        printf("vfmulxssi\n");  vfmulxssi_f16(a, b, c);
        printf("vfcmul\n");     vfcmul_f16(a, b, c);
        printf("vfcmula\n");    vfcmula_f16(a, b, c);
        printf("vfcmulc\n");    vfcmulc_f16(a, b, c);
        printf("vfcmulca\n");   vfcmulca_f16(a, b, c);
        printf("vfcmuln\n");    vfcmuln_f16(a, b, c);
        printf("vfcmulna\n");   vfcmulna_f16(a, b, c);
        printf("vfcmulcn\n");   vfcmulcn_f16(a, b, c);
        printf("vfcmulcna\n");  vfcmulcna_f16(a, b, c);
        printf("vrecpe\n");     vrecpe_f16(a, b, c);
        printf("vrecps\n");     vrecps_f16(a, b, c);
        printf("vrsqrte\n");    vrsqrte_f16(a, b, c);
        printf("vrsqrts\n");    vrsqrts_f16(a, b, c);
        printf("vexpe\n");      vexpe_f16(a, b, c);
}

int main()
{
        union reg128 test_a0, test_b0, test_c0;
        union reg128 test_a1, test_b1, test_c1;

        test_c0.x32[0] = 0x47a9ac4e;
        test_c0.x32[1] = 0x47a16b54;
        test_c0.x32[2] = 0xc79573cb;
        test_c0.x32[3] = 0xc80fabbd;

        test_b0.x32[0] = 0xc843ca22;
        test_b0.x32[1] = 0x483c7bbf;
        test_b0.x32[2] = 0xc73b64a7;
        test_b0.x32[3] = 0x481eefee;

        test_a0.x32[0] = 0x483471f7;
        test_a0.x32[1] = 0x46f2e02b;
        test_a0.x32[2] = 0xc785dc35;
        test_a0.x32[3] = 0x47ad69d9;

        do_f32_test(test_a0, test_b0, test_c0);

        test_c1.x16[0] = 0x4684;
        test_c1.x16[1] = 0x4633;
        test_c1.x16[2] = 0xc5bd;
        test_c1.x16[3] = 0xc984;
        test_c1.x16[4] = 0x4604;
        test_c1.x16[5] = 0x45b9;
        test_c1.x16[6] = 0xc54c;
        test_c1.x16[7] = 0xc918;
        test_b1.x16[0] = 0xcb85;
        test_b1.x16[1] = 0x4b3d;
        test_b1.x16[2] = 0xc332;
        test_b1.x16[3] = 0x4a1a;
        test_b1.x16[4] = 0xcaf1;
        test_b1.x16[5] = 0x4aae;
        test_b1.x16[6] = 0xc2a4;
        test_b1.x16[7] = 0x49a2;
        test_a1.x16[0] = 0x4aee;
        test_a1.x16[1] = 0x40aa;
        test_a1.x16[2] = 0xc524;
        test_a1.x16[3] = 0x46a9;
        test_a1.x16[4] = 0x4a65;
        test_a1.x16[5] = 0x404e;
        test_a1.x16[6] = 0xc4bf;
        test_a1.x16[7] = 0x4626;

        do_f16_test(test_a1, test_b1, test_c1);

        printf("vhtos\n");          vhtos_f16(test_a1, test_b1, test_c1);
        printf("vstoh\n");          vstoh_f32(test_a0, test_b1, test_c1);
        //printf("vhtos\n");        vhtos_f16(test_a1, test_b1, test_c1);
        printf("vftox.f32.s32\n");  vftox_f32_s32(test_a0, test_b1, test_c1);
        printf("vftox.f32.u32\n");  vftox_f32_u32(test_a0, test_b1, test_c1);
        printf("vftox.f16.s16\n");  vftox_f16_s16(test_a1, test_b1, test_c1);
        printf("vftox.f16.u16\n");  vftox_f16_u16(test_a1, test_b1, test_c1);
        printf("vftox.f32.s16\n");  vftox_f32_s16(test_a0, test_b1, test_c1);
        printf("vftox.f32.u16\n");  vftox_f32_u16(test_a0, test_b1, test_c1);
        printf("vftox.f16.s32\n");  vftox_f16_s32(test_a1, test_b1, test_c1);
        printf("vftox.f16.u32\n");  vftox_f16_u32(test_a1, test_b1, test_c1);
        printf("vxtof.s32.f32\n");  vxtof_s32_f32(test_a0, test_b1, test_c1);
        printf("vxtof.u32.f32\n");  vxtof_u32_f32(test_a0, test_b1, test_c1);
        printf("vxtof.s16.f16\n");  vxtof_s16_f16(test_a0, test_b1, test_c1);
        printf("vxtof.u16.f16\n");  vxtof_u16_f16(test_a0, test_b1, test_c1);
        printf("vxtof.s32.f16\n");  vxtof_s32_f16(test_a0, test_b1, test_c1);
        printf("vxtof.u32.f16\n");  vxtof_u32_f16(test_a0, test_b1, test_c1);
        printf("vxtof.s16.f32\n");  vxtof_s16_f32(test_a0, test_b1, test_c1);
        printf("vxtof.u16.f32\n");  vxtof_u16_f32(test_a0, test_b1, test_c1);

        printf("vftoi.f32.s32\n");  vftoi_f32_s32(test_a0, test_b1, test_c1);
        printf("vftoi.f32.u32\n");  vftoi_f32_u32(test_a0, test_b1, test_c1);
        printf("vftoi.f16.s16\n");  vftoi_f16_s16(test_a1, test_b1, test_c1);
        printf("vftoi.f16.u16\n");  vftoi_f16_u16(test_a1, test_b1, test_c1);
        printf("vftoi.f32.s16\n");  vftoi_f32_s16(test_a0, test_b1, test_c1);
        printf("vftoi.f32.u16\n");  vftoi_f32_u16(test_a0, test_b1, test_c1);
        printf("vftoi.f16.s32\n");  vftoi_f16_s32(test_a1, test_b1, test_c1);
        printf("vftoi.f16.u32\n");  vftoi_f16_u32(test_a1, test_b1, test_c1);
        printf("vitof.s32.f32\n");  vitof_s32_f32(test_a0, test_b1, test_c1);
        printf("vitof.u32.f32\n");  vitof_u32_f32(test_a0, test_b1, test_c1);
        printf("vitof.s16.f16\n");  vitof_s16_f16(test_a0, test_b1, test_c1);
        printf("vitof.u16.f16\n");  vitof_u16_f16(test_a0, test_b1, test_c1);
        printf("vitof.s32.f16\n");  vitof_s32_f16(test_a0, test_b1, test_c1);
        printf("vitof.u32.f16\n");  vitof_u32_f16(test_a0, test_b1, test_c1);
        printf("vitof.s16.f32\n");  vitof_s16_f32(test_a0, test_b1, test_c1);
        printf("vitof.u16.f32\n");  vitof_u16_f32(test_a0, test_b1, test_c1);

        printf("vmovi\n");          vmovi_f32(test_a0, test_b1, test_c1);
        printf("vmovi\n");          vmovi_f16(test_a1, test_b1, test_c1);


        return 0;
}
