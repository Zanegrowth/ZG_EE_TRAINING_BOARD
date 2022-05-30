/**
 * @file main.c
 * @brief MikroSDK base application.
 */

#include "board.h"
#include "log.h"
#include "string.h"
#include "drv_digital_out.h"

static digital_out_t output_pin;

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
    digital_out_init( &output_pin, PA0 );
    
}

/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example

    digital_out_write( &output_pin, 1 );

    Delay_ms(1000);
     
    digital_out_write( &output_pin, 0);

    Delay_ms(1000);
    
    //or
    /*
     digital_out_toggle( &output_pin);
     Delay_ms(1000);
     */
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
