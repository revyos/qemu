#include "dw_timer.h"

extern void start_dma1_channel4(void *src, void *dst, size_t size);
extern void wait_for_dma1_channel4_idle();

// Called by parameter manager of nnet module.
void pm_dma_initialize() { /* do nothing. */ }

// Called by parameter manager of nnet module.
void pm_dma_fetch_async(void *src, void *dst, size_t size)
{
	start_dma1_channel4(src, dst, size);
}

// Called by parameter manager of nnet module.
void pm_dma_await_idle()
{
	wait_for_dma1_channel4_idle();
}

#define TIM2 ((dw_timer_reg_t *)CSKY_TIM2_BASE)

void timer_start()
{
	TIM2->TxControl &= ~DW_TIMER_TXCONTROL_ENABLE;      /* disable the timer */
	TIM2->TxLoadCount = 0xffffffff;
	TIM2->TxControl |= DW_TIMER_TXCONTROL_ENABLE;       /* enable the corresponding timer */
}

void timer_stop()
{
	TIM2->TxControl &= ~DW_TIMER_TXCONTROL_ENABLE;      /* disable the timer */
}

uint32_t timer_get_tick_count()
{
    return TIM2->TxCurrentValue;
}
