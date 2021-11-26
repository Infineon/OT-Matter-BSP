/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 * Common Button implementation for platforms that only use GPIO buttons.
 * If a platform has other, non-GPIO based buttons it must override all the functions defined within this file.
 */

#include "platform_button.h"
#include "gpio_button.h"
#include "wiced_platform.h"
#include "wiced.h"

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

static void platform_button_state_change_callback( gpio_button_t* button, wiced_bool_t new_state );

/******************************************************
 *               Variable Definitions
 ******************************************************/

static platform_button_state_change_callback_t user_callback;

static const gpio_button_t platform_gpio_buttons[] =
{
    [PLATFORM_BUTTON_1] =
    {
        .polarity   = WICED_ACTIVE_HIGH,
        .gpio       = WICED_BUTTON1,
        .trigger    = IRQ_TRIGGER_BOTH_EDGES,
    },
#if WICED_PLATFORM_BUTTON_MAX_DEF >= 2
    [PLATFORM_BUTTON_2] =
    {
        .polarity   = WICED_ACTIVE_HIGH,
        .gpio       = WICED_BUTTON2,
        .trigger    = IRQ_TRIGGER_BOTH_EDGES,
    },
    [PLATFORM_BUTTON_3] =
    {
        .polarity   = WICED_ACTIVE_HIGH,
        .gpio       = WICED_BUTTON3,
        .trigger    = IRQ_TRIGGER_BOTH_EDGES,
    },
#if (WICED_PLATFORM_BUTTON_MAX_DEF >= 4)
    [PLATFORM_BUTTON_4] =
    {
        .polarity   = WICED_ACTIVE_HIGH,
        .gpio       = WICED_BUTTON4,
        .trigger    = IRQ_TRIGGER_BOTH_EDGES,
    },
#endif
#endif /* WICED_PLATFORM_BUTTON_MAX_DEF >= 2 */
};

/******************************************************
 *               Function Definitions
 ******************************************************/

wiced_result_t platform_button_init( platform_button_t button )
{
    return (wiced_result_t)gpio_button_init( &platform_gpio_buttons[ button ] );
}

wiced_result_t  platform_button_deinit( platform_button_t button )
{
    return (wiced_result_t)gpio_button_deinit( &platform_gpio_buttons[ button ] );
}

wiced_result_t platform_button_enable( platform_button_t button )
{
    return (wiced_result_t)gpio_button_enable( &platform_gpio_buttons[ button ] );
}

wiced_result_t platform_button_disable( platform_button_t button )
{
    return (wiced_result_t)gpio_button_disable( &platform_gpio_buttons[ button ] );
}

wiced_bool_t platform_button_get_value( platform_button_t button )
{
    return gpio_button_get_value( &platform_gpio_buttons[ button ] );
}

wiced_result_t platform_button_register_state_change_callback( platform_button_state_change_callback_t callback )
{
    user_callback = callback;
    return (wiced_result_t)gpio_button_register_state_change_callback( platform_button_state_change_callback );
}

static void platform_button_state_change_callback( gpio_button_t* button, wiced_bool_t new_state )
{
    user_callback( ( platform_button_t ) ARRAY_POSITION( platform_gpio_buttons, button ), new_state );
}
