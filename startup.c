#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (20U * 1024U) // 20 KB for STM32F103C8
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)

void reset_handler(void);
void default_handler(void);

// Cortex-M system exceptions
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));

// STM32F103C8 interrupt handlers
void wwdg_handler(void) __attribute__((weak, alias("default_handler")));
void pvd_handler(void) __attribute__((weak, alias("default_handler")));
void tamper_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_handler(void) __attribute__((weak, alias("default_handler")));
void flash_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel1_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel2_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel3_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel5_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel6_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_channel7_handler(void) __attribute__((weak, alias("default_handler")));
void adc1_2_handler(void) __attribute__((weak, alias("default_handler")));
void usb_hp_can1_tx_handler(void) __attribute__((weak, alias("default_handler")));
void usb_lp_can1_rx0_handler(void) __attribute__((weak, alias("default_handler")));
void can1_rx1_handler(void) __attribute__((weak, alias("default_handler")));
void can1_sce_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_5_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_handler(void) __attribute__((weak, alias("default_handler")));
void usart3_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_10_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_alarm_handler(void) __attribute__((weak, alias("default_handler")));
void usb_wakeup_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_brk_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_trg_com_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_cc_handler(void) __attribute__((weak, alias("default_handler")));
void adc3_handler(void) __attribute__((weak, alias("default_handler")));
void fsmc_handler(void) __attribute__((weak, alias("default_handler")));
void sdio_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_handler(void) __attribute__((weak, alias("default_handler")));
void uart4_handler(void) __attribute__((weak, alias("default_handler")));
void uart5_handler(void) __attribute__((weak, alias("default_handler")));
void tim6_handler(void) __attribute__((weak, alias("default_handler")));
void tim7_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_channel1_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_channel2_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_channel3_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_channel4_5_handler(void) __attribute__((weak, alias("default_handler")));

__attribute__((section(".isr_vector"))) uint32_t isr_vector[] = {
    STACK_POINTER_INIT_ADDRESS,
    (uint32_t)reset_handler,
    (uint32_t)nmi_handler,
    (uint32_t)hard_fault_handler,
    (uint32_t)mem_manage_handler,
    (uint32_t)bus_fault_handler,
    (uint32_t)usage_fault_handler,
    0, 0, 0, 0,
    (uint32_t)svcall_handler,
    (uint32_t)debug_monitor_handler,
    0,
    (uint32_t)pendsv_handler,
    (uint32_t)systick_handler,
    (uint32_t)wwdg_handler,
    (uint32_t)pvd_handler,
    (uint32_t)tamper_handler,
    (uint32_t)rtc_handler,
    (uint32_t)flash_handler,
    (uint32_t)rcc_handler,
    (uint32_t)exti0_handler,
    (uint32_t)exti1_handler,
    (uint32_t)exti2_handler,
    (uint32_t)exti3_handler,
    (uint32_t)exti4_handler,
    (uint32_t)dma1_channel1_handler,
    (uint32_t)dma1_channel2_handler,
    (uint32_t)dma1_channel3_handler,
    (uint32_t)dma1_channel4_handler,
    (uint32_t)dma1_channel5_handler,
    (uint32_t)dma1_channel6_handler,
    (uint32_t)dma1_channel7_handler,
    (uint32_t)adc1_2_handler,
    (uint32_t)usb_hp_can1_tx_handler,
    (uint32_t)usb_lp_can1_rx0_handler,
    (uint32_t)can1_rx1_handler,
    (uint32_t)can1_sce_handler,
    (uint32_t)exti9_5_handler,
    (uint32_t)tim1_brk_handler,
    (uint32_t)tim1_up_handler,
    (uint32_t)tim1_trg_com_handler,
    (uint32_t)tim1_cc_handler,
    (uint32_t)tim2_handler,
    (uint32_t)tim3_handler,
    (uint32_t)tim4_handler,
    (uint32_t)i2c1_ev_handler,
    (uint32_t)i2c1_er_handler,
    (uint32_t)i2c2_ev_handler,
    (uint32_t)i2c2_er_handler,
    (uint32_t)spi1_handler,
    (uint32_t)spi2_handler,
    (uint32_t)usart1_handler,
    (uint32_t)usart2_handler,
    (uint32_t)usart3_handler,
    (uint32_t)exti15_10_handler,
    (uint32_t)rtc_alarm_handler,
    (uint32_t)usb_wakeup_handler,
    (uint32_t)tim8_brk_handler,
    (uint32_t)tim8_up_handler,
    (uint32_t)tim8_trg_com_handler,
    (uint32_t)tim8_cc_handler,
    (uint32_t)adc3_handler,
    (uint32_t)fsmc_handler,
    (uint32_t)sdio_handler,
    (uint32_t)tim5_handler,
    (uint32_t)spi3_handler,
    (uint32_t)uart4_handler,
    (uint32_t)uart5_handler,
    (uint32_t)tim6_handler,
    (uint32_t)tim7_handler,
    (uint32_t)dma2_channel1_handler,
    (uint32_t)dma2_channel2_handler,
    (uint32_t)dma2_channel3_handler,
    (uint32_t)dma2_channel4_5_handler,
};

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss, _sidata;

void main(void);
void __libc_init_array();

void reset_handler(void) {
    // Copy .data section from FLASH to SRAM
    uint32_t *pSrc = &_sidata;
    uint32_t *pDst = &_sdata;
    while (pDst < &_edata) {
        *pDst++ = *pSrc++;
    }

    // Initialize the .bss section to zero in SRAM
    pDst = &_sbss;
    while (pDst < &_ebss) {
        *pDst++ = 0;
    }

    // Call the application's entry point

    __libc_init_array();
    main();
}

void default_handler(void) {
    while (1);
}

