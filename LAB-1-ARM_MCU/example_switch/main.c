/**
 * @file main.c
 * @brief MikroSDK base application.
 */

#include "board.h"
#include "log.h"
#include "string.h"
// #include "drv_digital_out.h"
#include "drv_digital_in.h"

static log_t logger;
static digital_in_t input_pin;

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
 
    log_cfg_t log_cfg;
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );
    
    
    digital_in_init( &input_pin, PA0 );
}

/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example
    
    uint8_t value;

    value = digital_in_read( &input_pin );   // Read digital input value.
    log_info( &logger, "value:: %d",value );
    Delay_ms(500);
    if(value == 1){
        log_info( &logger, "---- Pressed Button ----" );
    }
    //or
    /*
    //Switch debounce
    value = digital_in_read( &input_pin );   // Read digital input value.
    if(value == 0){
        value = digital_in_read( &input_pin );   // Read digital input value.
        if(value == 0){
            log_info( &logger, "---- Pressed ----" );
        }
    }
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
