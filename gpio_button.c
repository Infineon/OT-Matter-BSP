/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * GPIO-button implementation
 *
 */

#include "wiced.h"
#include "wiced_hal_gpio.h"
#include "wiced_rtos.h"
#include "gpio_button.h"
#include "wiced_platform.h"

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *               Static Function Declarations
 ******************************************************/

static void gpio_button_interrupt_handler( void* args, uint8_t pin );

/******************************************************
 *               Variable Definitions
 ******************************************************/

static gpio_button_state_change_callback_t button_state_change_callback;

/******************************************************
 *               Function Definitions
 ******************************************************/

wiced_result_t gpio_button_init( const gpio_button_t* button )
{
	if(button == NULL)
		return WICED_BADARG;
#ifndef USE_PLATFORM_BUTTON_CONFIG
	wiced_hal_gpio_configure_pin((uint32_t)button->gpio, (uint32_t)GPIO_INPUT_ENABLE,
			(uint32_t)(( button->polarity == WICED_ACTIVE_HIGH )? INPUT_PULL_UP: INPUT_PULL_DOWN));
#endif

    return WICED_SUCCESS;
}

wiced_result_t gpio_button_deinit( const gpio_button_t* button )
{
	if(button == NULL)
		return WICED_BADARG;
#ifndef USE_PLATFORM_BUTTON_CONFIG
	wiced_hal_gpio_configure_pin((uint32_t)button->gpio, (uint32_t)(GPIO_INPUT_DISABLE|GPIO_INTERRUPT_DISABLE),
			(uint32_t)(INPUT_PULL_DOWN));
#endif

    return WICED_SUCCESS;

}

wiced_result_t gpio_button_register_state_change_callback( gpio_button_state_change_callback_t callback )
{
    if ( !callback )
    {
        return WICED_BADARG;
    }

    button_state_change_callback = callback;

    return WICED_SUCCESS;
}

wiced_result_t gpio_button_enable( const gpio_button_t* button )
{
#ifndef USE_PLATFORM_BUTTON_CONFIG
    wiced_gpio_irq_trigger_t trigger;

	if(button == NULL)
		return WICED_BADARG;

    if ( button->trigger == 0 )
    {
        trigger = ( ( button->polarity == WICED_ACTIVE_LOW ) ? IRQ_TRIGGER_RISING_EDGE : IRQ_TRIGGER_FALLING_EDGE );
    }
    else
    {
        trigger = button->trigger;
    }

    wiced_hal_gpio_configure_pin( (uint32_t)button->gpio, WICED_GPIO_BUTTON_SETTINGS((uint32_t)trigger),
		(uint32_t)(( button->polarity == WICED_ACTIVE_HIGH )? INPUT_PULL_UP: INPUT_PULL_DOWN));
#endif

    wiced_hal_gpio_register_pin_for_interrupt((uint16_t) button->gpio,
		gpio_button_interrupt_handler, (void*)button);

    return WICED_SUCCESS;
}

wiced_result_t gpio_button_disable( const gpio_button_t* button )
{
	if(button == NULL)
		return WICED_BADARG;

#ifndef USE_PLATFORM_BUTTON_CONFIG
	wiced_hal_gpio_configure_pin((uint32_t)button->gpio, (uint32_t)(GPIO_INPUT_DISABLE|GPIO_INTERRUPT_DISABLE),
			(uint32_t)(INPUT_PULL_DOWN));
#endif

    return WICED_SUCCESS;
}

wiced_bool_t gpio_button_get_value( const gpio_button_t* button )
{
    wiced_bool_t value;

	if(button == NULL)
		return WICED_BADARG;

    value = (wiced_bool_t)wiced_hal_gpio_get_pin_input_status((uint32_t)button->gpio );
    return value;
}


static void gpio_button_interrupt_handler( void* args, uint8_t pin )
{
    const gpio_button_t* button = (const gpio_button_t*)args;
    wiced_bool_t   gpio_state;
    wiced_bool_t   is_pressed;
    (void)(pin);	//unused

    //WICED_BT_TRACE("%s - %d\n", __func__,pin);
    if( !button_state_change_callback || !button )
    {
        return;
    }

    gpio_state = (wiced_bool_t)wiced_hal_gpio_get_pin_input_status((uint32_t)button->gpio );

    is_pressed = ( button->polarity == WICED_ACTIVE_HIGH ) ? ( (gpio_state  == WICED_FALSE ) ? WICED_TRUE : WICED_FALSE ) : ( (gpio_state == WICED_FALSE ) ? WICED_FALSE : WICED_TRUE );

    button_state_change_callback( (void*)button, is_pressed );
}
