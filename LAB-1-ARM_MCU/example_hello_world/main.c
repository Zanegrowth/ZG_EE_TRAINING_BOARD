#include "board.h"
#include "drv_uart.h"
#include "string.h"


uart_t uart;

char uart_rx_buffer[ 1024 ];
char uart_tx_buffer[ 1024 ];


void application_init()
{
    uart_config_t uart_cfg;
    
    //uart_configure_default( &uart_cfg );
    
    /*UART module config*/
    uart_cfg.rx_pin = USB_UART_RX;  // UART RX pin. 
    uart_cfg.tx_pin = USB_UART_TX;  // UART TX pin. 
    uart_cfg.tx_ring_size = sizeof( uart_tx_buffer );  
    uart_cfg.rx_ring_size = sizeof( uart_tx_buffer );

    uart_open( &uart, &uart_cfg );
    uart_set_baud( &uart, 115200);
    uart_set_parity( &uart, UART_PARITY_DEFAULT);
    uart_set_stop_bits( &uart, UART_STOP_BITS_DEFAULT);  
    uart_set_data_bits( &uart, UART_DATA_BITS_DEFAULT);

    uart_set_blocking( &uart, false);

}


void application_task()
{

    char buf[32] = "Hello world";
    uart_write( &uart, buf, strlen(buf));
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
