#ifndef __KWS_FXP_H__
#define __KWS_FXP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/////////////////////// KWS Essentials ///////////////////////

typedef enum {
	CHECKER_STATE_BREAK,    // stop the main loop and clean up;
	CHECKER_STATE_CONTINUE, // continue with the next frame;
	CHECKER_STATE_RESET     // will reset some status and continue;
} CHECKER_STATE;

// A callback for passing audio waves to the kws.
typedef size_t(*READER)(
	void *src,      // points to whatever user specified;
	size_t length,  // the length of audio data per frame;
	int16_t *wave); // fill audio data to this address;

// A callback method for passing out the kws result.
// Return a control flag.
typedef CHECKER_STATE(*CHECKER)(
	void *reference, // points to whatever user specified;
	int result);     // the keyword id if spotted, otherwise -1;

//////////////////////////////////////////////////////////////

/////////////////////// KWS Entrances ////////////////////////

void spot_two_keywords_with_ailab_dnn_fxp_batch(
	void *source,
	READER reader,
	void *reference,
	CHECKER checker,
	// The batch size indicates how many frames will be processed
	// together each time. Generally, larger batch_size may have
	// better performance but higher memory requirements.
	// For dnn or dfsmn models, set with 4 when using MCA.
	size_t batch_size);

void spot_multiple_keywords_with_big_dnn_fxp(
	void *source,
	READER reader,
	void *reference,
	CHECKER checker);

//////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif
