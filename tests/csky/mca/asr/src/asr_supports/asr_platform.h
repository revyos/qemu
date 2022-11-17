#ifndef __ASR_PLATFORM_H__
#define __ASR_PLATFORM_H__

#define BUS_WIDTH 0x10 // bytes.

#ifdef __CSKY__
#define ASR_CSKY

#if defined(__CK803__)
#define ASR_CK803
#elif defined(__CK805__)
#define ASR_CK805
#else
#pragma GCC error "No compatible C-Sky CPU defined."
#endif

// Switch for enabling MCA in YunVoice.
#define ASR_ENABLE_MCA 1

// Switch for enabling simulation of CK80X.
#define ASR_SIM_MODE 0

#if !ASR_SIM_MODE && ASR_ENABLE_MCA
	#if defined(ASR_CK803)
		#define ASR_MCA_1
	#elif defined(ASR_CK805)
		#define ASR_MCA_2
	#endif
#endif

#endif // __CSKY__

#endif // !__ASR_PLATFORM_H__
