/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/**
 * @file
 *
 * GPIO-based Button APIs
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "wiced.h"
#include "wiced_rtos.h"
#include"wiced_hal_gpio.h"


/******************************************************
 *                     Macros
 ******************************************************/
#if BTSTACK_VER >= 0x01020000
/* Pin configuration */
#define GPIO_PULL_UP           WICED_GPIO_PULL_UP
#define GPIO_PULL_DOWN         WICED_GPIO_PULL_DOWN
#define GPIO_PULL_UP_DOWN_NONE WICED_GPIO_PULL_UP_DOWN_NONE
/* GPIO interrupt trigger */
#define GPIO_EN_INT_RISING_EDGE  WICED_GPIO_EN_INT_RISING_EDGE
#define GPIO_EN_INT_FALLING_EDGE WICED_GPIO_EN_INT_FALLING_EDGE
#define GPIO_EN_INT_BOTH_EDGE    WICED_GPIO_EN_INT_BOTH_EDGE
#define GPIO_EN_INT_LEVEL_HIGH   WICED_GPIO_EN_INT_LEVEL_HIGH
#define GPIO_EN_INT_LEVEL_LOW    WICED_GPIO_EN_INT_LEVEL_LOW
#endif


/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/
/**
 * Pin configuration
 */
typedef enum
{
    INPUT_PULL_UP = GPIO_PULL_UP,             /**< Input with an internal pull-up resistor - use with devices that actively drive the signal low - e.g. button connected to ground */
    INPUT_PULL_DOWN = GPIO_PULL_DOWN,           /**< Input with an internal pull-down resistor - use with devices that actively drive the signal high - e.g. button connected to a power rail */
    OUTPUT_PUSH_PULL= GPIO_PULL_UP_DOWN_NONE,          /**< Output actively driven high and actively driven low - must not be connected to other active outputs - e.g. LED output */
    INPUT_HIGH_IMPEDANCE = GPIO_PULL_UP_DOWN_NONE,      /**< Input - must always be driven, either actively or by an external pullup resistor */
} platform_pin_config_t;

/**
 * GPIO interrupt trigger
 */
typedef enum
{
    IRQ_TRIGGER_RISING_EDGE  = (GPIO_EN_INT_RISING_EDGE), /**< Interrupt triggered at input signal's rising edge  */
    IRQ_TRIGGER_FALLING_EDGE = (GPIO_EN_INT_FALLING_EDGE), /**< Interrupt triggered at input signal's falling edge */
    IRQ_TRIGGER_BOTH_EDGES   = (GPIO_EN_INT_BOTH_EDGE), /**< Interrupt triggered at input signal's rising and falling edge */
    IRQ_TRIGGER_LEVEL_HIGH   = (GPIO_EN_INT_LEVEL_HIGH), /**< Interrupt triggered when input signal's level is high */
    IRQ_TRIGGER_LEVEL_LOW    = (GPIO_EN_INT_LEVEL_LOW), /**< Interrupt triggered when input signal's level is low  */
} wiced_gpio_irq_trigger_t;

typedef enum
{
    WICED_ACTIVE_LOW   = 0,     /**< ACTIVE LOW    */
    WICED_ACTIVE_HIGH  = 1,     /**< ACTIVE HIGH   */
} wiced_active_state_t;

typedef struct
{
	wiced_bt_gpio_numbers_t		 gpio;
    wiced_active_state_t         polarity;
    wiced_gpio_irq_trigger_t     trigger;
} gpio_button_t;

typedef void (*gpio_button_state_change_callback_t)( gpio_button_t* button, wiced_bool_t new_state );

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/

wiced_result_t gpio_button_init     ( const gpio_button_t* button );
wiced_result_t gpio_button_deinit   ( const gpio_button_t* button );
wiced_result_t gpio_button_enable   ( const gpio_button_t* button );
wiced_result_t gpio_button_disable  ( const gpio_button_t* button );
wiced_bool_t   gpio_button_get_value( const gpio_button_t* button );
wiced_result_t gpio_button_register_state_change_callback( gpio_button_state_change_callback_t callback );

#ifdef __cplusplus
} /*extern "C" */
#endif
