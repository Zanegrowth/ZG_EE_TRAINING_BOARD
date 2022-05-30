/**
 * @file main.c
 * @brief MikroSDK base application.
 */

#include "board.h"
#include "log.h"
#include "string.h"
#include "drv_digital_out.h"
#include "drv_port.h"

// static digital_out_t output_pin;

static port_t port_a;
static port_t port_b;
static port_t port_c;
static port_t port_d;
static port_t port_e;
static port_t port_f;

uint16_t mask = 0xFFFF;
uint16_t value = 0;

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

    port_init( &port_a, PORT_A, mask, GPIO_DIGITAL_OUTPUT );
    port_init( &port_b, PORT_B, mask, GPIO_DIGITAL_OUTPUT );
    port_init( &port_c, PORT_C, mask, GPIO_DIGITAL_OUTPUT );
    port_init( &port_d, PORT_D, mask, GPIO_DIGITAL_OUTPUT );
    port_init( &port_e, PORT_E, mask, GPIO_DIGITAL_OUTPUT );
    port_init( &port_f, PORT_F, mask, GPIO_DIGITAL_OUTPUT );

}

/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example

    value = ~value;
    port_write( &port_a, value );
    port_write( &port_b, value );
    port_write( &port_c, value );
    port_write( &port_d, value );
    port_write( &port_e, value );
    port_write( &port_f, value );

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
