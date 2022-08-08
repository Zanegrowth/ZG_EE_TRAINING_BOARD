/*!
 * \file 
 * \brief HallCurrent4 Click example
 * 
 * # Description
 * Demo application shows is reading current data in mA using Hall current 4 click.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Configuring clicks and log objects.
 * 
 * ## Application Task  
 * Reads Current value in mA and logs this data to USBUART every 1 sec.
 * 
 * \author Katarina Perendic
 *
 */
// ------------------------------------------------------------------- INCLUDES

#include "board.h"
#include "log.h"
#include "hallcurrent4.h"
#include "wifi_to_platform.h"

// ------------------------------------------------------------------ VARIABLES

static hallcurrent4_t hallcurrent4;
static log_t logger;

static wifi_t wifi;
uint8_t len_out = 0;
uint8_t buf[256];
hall_carrent_4click_t hal_data = {
    .id = HALL_CURRENT_4CLICK_ID
};
// ------------------------------------------------------ APPLICATION FUNCTIONS

void application_init ( void )
{
    log_cfg_t log_cfg;
    hallcurrent4_cfg_t cfg;
    wifi_cfg_t cfg1;
    /** 
     * Logger initialization.
     * Default baud rate: 115200
     * Default log level: LOG_LEVEL_DEBUG
     * @note If USB_UART_RX and USB_UART_TX 
     * are defined as HAL_PIN_NC, you will 
     * need to define them manually for log to work. 
     * See @b LOG_MAP_USB_UART macro definition for detailed explanation.
     */
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.
    
    wifi_cfg_setup( &cfg1 );
    WIFIBLE_MAP_MIKROBUS( cfg1, MIKROBUS_1 );
    wifi_init( &wifi, &cfg1 );

    hallcurrent4_cfg_setup( &cfg );
    HALLCURRENT4_MAP_MIKROBUS( cfg, MIKROBUS_2 );
    hallcurrent4_init( &hallcurrent4, &cfg );
    
    
    uint8_t ssid_buf[64];
    uint8_t id_buf[32];

    len_out = pack_ssid_data("Zanegrowth1", "12345678", ssid_buf);
    wifi_generic_write(&wifi, ssid_buf, len_out);
    len_out = pack_device_id_data("TNB000018", id_buf);
    wifi_generic_write(&wifi, id_buf, len_out);
     
    Delay_ms(2000);
}

void application_task ( void )
{
    float current;

    current = hallcurrent4_get_current_data( &hallcurrent4 );

    log_printf( &logger, " >> Current value: %.2f mA\r\n", current );
    log_printf( &logger, " ------------------------- \r\n" );
   
    hal_data.current = current;
    len_out = pack_sensors_data((uint8_t *)&hal_data, sizeof(hal_data), buf, 1);
    wifi_generic_write(&wifi, buf, len_out);

    Delay_ms( 1000 );
}

void main ( void )
{
    application_init( );

    for ( ; ; )
    {
        application_task( );
    }
}


// ------------------------------------------------------------------------ END
