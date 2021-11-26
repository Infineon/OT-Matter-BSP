/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#pragma once

#include <stddef.h>
#include "data_types.h"
#include "wiced.h"
#include "wiced_bt_dev.h"
#include "wiced_hal_gpio.h"

//! Number of LEDs available on the platform.
typedef enum
{
    WICED_PLATFORM_LED_1,  //!< LED 1
    WICED_PLATFORM_LED_2,  //!< LED 2
    WICED_PLATFORM_LED_MAX //!< Max LED for error check
} wiced_platform_led_number_t;

//! Number of Buttons available on the platform.
typedef enum
{
    WICED_PLATFORM_BUTTON_1,  //!< BUTTON 1
    WICED_PLATFORM_BUTTON_MAX //!< Max button for error check
} wiced_platform_button_number_t;

#define WICED_PLATFORM_BUTTON_MAX_DEF     1   // define for preprocessor

//! Number of GPIO available on the platform.
// Configurable via SuperMux
typedef enum
{
    WICED_PLATFORM_GPIO_1,  //!< GPIO 1
    WICED_PLATFORM_GPIO_2,  //!< GPIO 2
    WICED_PLATFORM_GPIO_3,  //!< GPIO 3
    WICED_PLATFORM_GPIO_4,  //!< GPIO 4
    WICED_PLATFORM_GPIO_5,  //!< GPIO 5
    WICED_PLATFORM_GPIO_6,  //!< GPIO 6
    WICED_PLATFORM_GPIO_7,  //!< GPIO 7
    WICED_PLATFORM_GPIO_8,  //!< GPIO 8
    WICED_PLATFORM_GPIO_9,  //!< GPIO 9
    WICED_PLATFORM_GPIO_10,  //!< GPIO 10
    WICED_PLATFORM_GPIO_11,  //!< GPIO 11
    WICED_PLATFORM_GPIO_12,  //!< GPIO 12
    WICED_PLATFORM_GPIO_13,  //!< GPIO 13
    WICED_PLATFORM_GPIO_14,  //!< GPIO 14
    WICED_PLATFORM_GPIO_15,  //!< GPIO 15
    WICED_PLATFORM_GPIO_16,  //!< GPIO 16
    WICED_PLATFORM_GPIO_17,  //!< GPIO 17
    WICED_PLATFORM_GPIO_18,  //!< GPIO 18
    WICED_PLATFORM_GPIO_19,  //!< GPIO 19
    WICED_PLATFORM_GPIO_20,  //!< GPIO 20
    WICED_PLATFORM_GPIO_21,  //!< GPIO 21
    WICED_PLATFORM_GPIO_22,  //!< GPIO 22
    WICED_PLATFORM_GPIO_23,  //!< GPIO 23
    WICED_PLATFORM_GPIO_24,  //!< GPIO 24
    WICED_PLATFORM_GPIO_25,  //!< GPIO 25
    WICED_PLATFORM_GPIO_26,  //!< GPIO 26
    WICED_PLATFORM_GPIO_27,  //!< GPIO 27
    WICED_PLATFORM_GPIO_28,  //!< GPIO 28
    WICED_PLATFORM_GPIO_29,  //!< GPIO 29
    WICED_PLATFORM_GPIO_30,  //!< GPIO 30
    WICED_PLATFORM_GPIO_31,  //!< GPIO 31
    WICED_PLATFORM_GPIO_32,  //!< GPIO 32
    WICED_PLATFORM_GPIO_33,  //!< GPIO 33
    WICED_PLATFORM_GPIO_34,  //!< GPIO 34
    WICED_PLATFORM_GPIO_35,  //!< GPIO 35
    WICED_PLATFORM_GPIO_36,  //!< GPIO 36
    WICED_PLATFORM_GPIO_37,  //!< GPIO 37
    WICED_PLATFORM_GPIO_38,  //!< GPIO 38
    WICED_PLATFORM_GPIO_39,  //!< GPIO 39
    WICED_PLATFORM_GPIO_40,  //!< GPIO 40
    WICED_PLATFORM_GPIO_MAX //!< Max GPIO for error check
} wiced_platform_gpio_number_t;

//! Possible interrupt configuration for platform buttons
typedef enum
{
    WICED_PLATFORM_BUTTON_BOTH_EDGE = GPIO_EN_INT_BOTH_EDGE,   //!< indicates that app. should receive interrupt on both edges
    WICED_PLATFORM_BUTTON_RISING_EDGE = GPIO_EN_INT_RISING_EDGE, //!< indicates that app. should receive interrupt only for rising edge
    WICED_PLATFORM_BUTTON_FALLING_EDGE = GPIO_EN_INT_FALLING_EDGE,//!< indicates that app. should receive interrupt only for falling edge
} wiced_platform_button_interrupt_edge_t;

//! List of pins available on the platform
enum wiced_platform_pins
{
    PLATFORM_GPIO_0,
    PLATFORM_GPIO_1,
    PLATFORM_GPIO_2,
    PLATFORM_GPIO_3,
    PLATFORM_GPIO_4,
    PLATFORM_GPIO_5,
    PLATFORM_GPIO_6,
    PLATFORM_GPIO_7,
    PLATFORM_GPIO_8,
    PLATFORM_GPIO_9,
    PLATFORM_GPIO_10,
    PLATFORM_GPIO_11,
    PLATFORM_GPIO_12,
    PLATFORM_GPIO_13,
    PLATFORM_GPIO_14,
    PLATFORM_GPIO_15,
    PLATFORM_GPIO_16,
    PLATFORM_GPIO_17,
    PLATFORM_GPIO_18,
    PLATFORM_GPIO_19,
    PLATFORM_GPIO_20,
    PLATFORM_GPIO_21,
    PLATFORM_GPIO_22,
    PLATFORM_GPIO_23,
    PLATFORM_GPIO_24,
    PLATFORM_GPIO_25,
    PLATFORM_GPIO_26,
    PLATFORM_GPIO_27,
    PLATFORM_GPIO_28,
    PLATFORM_GPIO_29,
    PLATFORM_GPIO_30,
    PLATFORM_GPIO_31,
    PLATFORM_GPIO_32,
    PLATFORM_GPIO_33,
    PLATFORM_GPIO_34,
    PLATFORM_GPIO_35,
    PLATFORM_GPIO_36,
    PLATFORM_GPIO_37,
    PLATFORM_GPIO_38,
    PLATFORM_GPIO_39,
    PLATFORM_GPIO_40,
    PLATFORM_GPIO_MAX_PINS
};

/**
 * configuration for the platform GPIOs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t gpio_pin; /**< WICED GPIO pin */
    wiced_bt_gpio_function_t functionality; /**< chosen functionality for the pin */
}
wiced_platform_gpio_t;

/**
 * Configuration for platform LEDs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
}
wiced_platform_led_config_t;

/**
 * Configuration for platform Buttons
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., interrupt is configured through wiced_platform_register_button_callback(...) */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
    uint32_t button_pressed_value; /**< Button pressed value */
}
wiced_platform_button_config_t;

/**
 * Configuration for platform GPIOs
 */
typedef struct
{
    wiced_bt_gpio_numbers_t* gpio; /**< WICED GPIO pin */
    uint32_t config; /**< configuration like GPIO_PULL_DOWN,GPIO_PULL_UP etc., interrupt is configured through wiced_platform_register_button_callback(...) */
    uint32_t default_state; /**< GPIO_PIN_OUTPUT_HIGH/GPIO_PIN_OUTPUT_LOW */
}
wiced_platform_gpio_config_t;

/*! pin for button 1 */

/*! configuration settings for button, x can be GPIO_EN_INT_RISING_EDGE or GPIO_EN_INT_FALLING_EDGE or GPIO_EN_INT_BOTH_EDGE */
#define WICED_GPIO_BUTTON_SETTINGS(x)                       ( GPIO_INPUT_ENABLE | GPIO_PULL_UP | x )

/*! pin for LED 1 */
#define WICED_GPIO_PIN_LED_1    WICED_P34
/*! pin for LED 2 */
#define WICED_GPIO_PIN_LED_2    WICED_P38

#define WICED_PUART_TXD         WICED_P30
#define WICED_PUART_RXD         WICED_P37

#define WICED_BUTTON1           WICED_P00
#define WICED_RESET_PIN         WICED_P21
#define WICED_DEBUG_PIN         WICED_P33

/*! Pin state for the LED on. */
#ifndef LED_STATE_ON
#define LED_STATE_ON          (GPIO_PIN_OUTPUT_LOW)
#endif
/*! Pin state for the LED off. */
#ifndef LED_STATE_OFF
#define LED_STATE_OFF         (GPIO_PIN_OUTPUT_HIGH)
#endif

/*! Pin state for when a button is pressed. */
#ifndef BTN_PRESSED
#define BTN_PRESSED           (GPIO_PIN_OUTPUT_LOW)
#endif
/*! Pin state for when a button is released. */
#ifndef BTN_OFF
#define BTN_OFF               (GPIO_PIN_OUTPUT_HIGH)
#endif

/*! IEEE 802.15.4 PHY ED Threshold Value used for CCA. */
#define WICED_PLATFORM_I15DOT4_PHY_ED_THRESHOLD (-70)

#ifdef __cplusplus
extern "C" {
#endif


/* Platform function */
void     wiced_platform_init(void);
uint32_t wiced_platform_get_button_pressed_value(wiced_platform_button_number_t button);
wiced_bool_t wiced_platform_transport_init(void *p_rx_data_handler);

/* utility functions */
void     wiced_platform_register_button_callback(wiced_platform_button_number_t button, void (*userfn)(void*, uint8_t), void* userdata, wiced_platform_button_interrupt_edge_t trigger_edge);

/**
 * \brief prototype for application thread event handler
 */
typedef void (wiced_platform_application_thread_event_handler)(void);

/**
 * \brief prototype for application thread specific handler - used for user application
 */
typedef void (wiced_platform_application_thread_specific_handler)(void);

/**
 *  \brief Register the BT stack event handler.
 *
 *  \param [in] user specific handler (callback)
 *
 *  \return None
 *
 */
void wiced_platform_register_bt_management_callback(wiced_bt_management_cback_t *p_callback);

/**
 *  \brief Register the HCI VSE event handler
 *
 *  \param [in] HCI VSE event code
 *  \param [in] target event code handler (callback)
 *
 *  \return None
 *
 */
wiced_bool_t wiced_platform_register_hci_vse_callback(uint8_t evt_code, wiced_bt_dev_vse_callback_t *p_callback);

/**
 *  \brief Helper function to check if current utility is executed under application thread.
 *
 *  \return WICED_TRUE  : Current utility is executed under application thread.
 *          WICED_FALSE : Current utility is NOT executed under application thread.
 *
 */
wiced_bool_t wiced_platform_application_thread_check(void);

/**
 *  \brief Get application thread event code and the register the corresponding event handler if
 *         provided.
 *
 *  \param [out]    allocated event code
 *  \param [in]     user specified event handler
 *
 *  \return WICED_TRUE  : Success
 *          WICED_FALSE : Fail.
 *
 */
wiced_bool_t wiced_platform_application_thread_event_register(uint32_t *p_event_code,
        wiced_platform_application_thread_event_handler *p_event_handler);

/**
 *  \brief Wait an application thread event
 *
 *  \param [in] event code (get by register utility)
 *
 */
void wiced_platform_application_thread_event_wait(uint32_t event_code);

/**
 *  \brief Set an application thread event
 *
 *  \param [in] event code (get by register utility)
 *
 */
void wiced_platform_application_thread_event_set(uint32_t event_code);

/**
 * \brief This function waits and dispatches application events.
 */
void wiced_platform_application_thread_event_dispatch(void);

/**
 * \brief Register a user application periodical handler under application thread.
 *        The register handler will be executed periodically (defined in
 *        WICED_PLATFORM_APPLICATION_THREAD_EVENT_WAIT_TIME) if the application thread
 *        is id idle state.
 *
 * @param p_handler - user application handler
 *
 */
void wiced_platform_application_thread_specific_handler_register(wiced_platform_application_thread_specific_handler *p_handler);

/**
 * \brief This function use a true random number generator to fill the buffer with entropy.
 *
 * @param[out] output         A pointer to where the true random values are placed. Must not be NULL.
 * @param[in]  output_length  Size of the buffer.
 *
 * @retval WICED_SUCCESS  Successfully filled the buffer with true random values.
 * @retval WICED_ERROR    Failed to fill the buffer with true random values.
 * @retval WICED_BADARG   The buffer was set to NULL.
 */
wiced_result_t wiced_platform_entropy_get(uint8_t *output, uint16_t output_length);


/**
 * \brief Initialize PUART
 *
 * @param[in] puart_rx_cbk         Call back function to process rx bytes.
 *
 */
void wiced_platform_puart_init(void (*puart_rx_cbk)(void*));

#ifdef __cplusplus
} /* extern "C" */
#endif
