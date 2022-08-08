/*!
 * @file main.c
 * @brief Proximity15 Click example
 *
 * # Description
 * This example demonstrates the use of Proximity 15 click board.
 *
 * The demo application is composed of two sections :
 *
 * ## Application Init
 * Initializes the driver and performs the click default configuration which 
 * enables the sensor and sets it to long distance mode with 50ms timing budget and 100ms
 * inter measurement periods.
 *
 * ## Application Task
 * Reads the distance measured by the sensor in milimeters and displays the 
 * value on the USB UART approximately every 100ms.
 * 
 * @note 
 * In order to measure longer distance, increase the timing budget and inter measurement periods.
 *
 * @author Stefan Filipovic
 *
 */

#include "board.h"
#include "log.h"
#include "proximity15.h"
#include "wifi_to_platform.h"

static proximity15_t proximity15;
static log_t logger;


static wifi_t wifi;
uint8_t len_out = 0;
uint8_t buf[256];
proximity_15click_t proximity_data = {
    .id = PROXIMITY_15CLICK_ID,
};

void application_init ( void ) 
{
    log_cfg_t log_cfg;                  /**< Logger config object. */
    proximity15_cfg_t proximity15_cfg;  /**< Click config object. */
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
    log_info( &logger, " Application Init " );

    // Click initialization.
    wifi_cfg_setup( &cfg1 );
    WIFIBLE_MAP_MIKROBUS( cfg1, MIKROBUS_1 );
    wifi_init( &wifi, &cfg1 );
    
    
    proximity15_cfg_setup( &proximity15_cfg );
    PROXIMITY15_MAP_MIKROBUS( proximity15_cfg, MIKROBUS_1 );
    err_t init_flag = proximity15_init( &proximity15, &proximity15_cfg );
    if ( I2C_MASTER_ERROR == init_flag ) 
    {
        log_error( &logger, " Application Init Error. " );
        log_info( &logger, " Please, run program again... " );
        for ( ; ; );
    }

    init_flag = proximity15_default_cfg ( &proximity15 );
    if ( PROXIMITY15_ERROR == init_flag ) 
    {
        log_error( &logger, " Default Config Error. " );
        log_info( &logger, " Please, run program again... " );
        for ( ; ; );
    }
    
    log_info( &logger, " Application Task " );
    
    
    uint8_t ssid_buf[64];
    uint8_t id_buf[32];

    len_out = pack_ssid_data("Zanegrowth1", "12345678", ssid_buf);
    wifi_generic_write(&wifi, ssid_buf, len_out);
    len_out = pack_device_id_data("TNB000015", id_buf);
    wifi_generic_write(&wifi, id_buf, len_out);
     
    Delay_ms(2000);
}

void application_task ( void ) 
{
    uint16_t distance = 0;
    
    if ( PROXIMITY15_OK == proximity15_get_distance ( &proximity15, &distance ) )
    {
        log_printf( &logger, " Distance(mm): %u\r\n\n", distance );
         
        proximity_data.distance = distance;
        len_out = pack_sensors_data((uint8_t *)&proximity_data, sizeof(proximity_data), buf, 1);
        wifi_generic_write(&wifi, buf, len_out);
    }
    Delay_ms(1000);
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
