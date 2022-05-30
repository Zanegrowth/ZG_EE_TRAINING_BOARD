/**
 * @file main.c
 * @brief MikroSDK base application.
 */

#include "board.h"
#include "log.h"
#include "string.h"

static log_t logger;

/// @todo Include wanted Driver headers to use.
/// @example
///     #include "drv_digital_out.h"

/// @todo Define Driver objects.
/// @example
///     static digital_out_t led_pin;

/// @brief Application init function.
void application_init()
{
    /// @todo Initialize Driver objects.
    /// @example
    ///     digital_out_init(&led_pin, LED1);

    log_cfg_t log_cfg;
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );
}

/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example
    ///     digital_out_toggle(&led_pin);
    
    log_info( &logger, "Hello world");
    Delay_ms(1000);
     
     
}

/// @brief Application main function.
void main(void)
{
    application_init();
    while (1)
    {
        application_task();
    }
}
