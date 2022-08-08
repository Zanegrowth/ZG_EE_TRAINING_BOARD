/*!
 * @file main.c
 * @brief IrThermo3V3 Click example
 *
 * # Description
 * This application collects data from the sensor, and logs the results.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Initializes IrThermo 3V3 Driver.
 * 
 * ## Application Task  
 * Reading Ambient and Object Temperature and displaying the value periodically.
 *
 * @author Stefan Ilic
 *
 */

#include "board.h"
#include "log.h"
#include "irthermo3v3.h"
#include "wifi_to_platform.h"

static irthermo3v3_t irthermo3v3;
static log_t logger;

static float measured_temperature;
static float object_temperature;


static wifi_t wifi;
uint8_t len_out = 0;
uint8_t buf[256];
irthermo_click_t irthermo_data = {
    .id = IRHTERMO_CLICK_ID
};
    
void application_init ( void ) {
    log_cfg_t log_cfg;  /**< Logger config object. */
    irthermo3v3_cfg_t irthermo3v3_cfg;  /**< Click config object. */
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
    log_info( &logger, " Application Init \r\n " );
    log_printf( &logger, " -------------------------------\r\n " );
    Delay_ms( 100 );

    // Click initialization.
    
    wifi_cfg_setup( &cfg1 );
    WIFIBLE_MAP_MIKROBUS( cfg1, MIKROBUS_1 );
    wifi_init( &wifi, &cfg1 );
    
    irthermo3v3_cfg_setup( &irthermo3v3_cfg );
    IRTHERMO3V3_MAP_MIKROBUS( irthermo3v3_cfg, MIKROBUS_2 );
    err_t init_flag = irthermo3v3_init( &irthermo3v3, &irthermo3v3_cfg );
    if ( I2C_MASTER_ERROR == init_flag ) {
        log_error( &logger, " Application Init Error. " );
        log_info( &logger, " Please, run program again... " );

        for ( ; ; );
    }

    log_info( &logger, " Application Task \r\n" );
    log_printf( &logger, "------------------------------\r\n " );
    Delay_ms( 100 );
    
    
    uint8_t ssid_buf[64];
    uint8_t id_buf[32];

    len_out = pack_ssid_data("Zanegrowth1", "12345678", ssid_buf);
    wifi_generic_write(&wifi, ssid_buf, len_out);
    len_out = pack_device_id_data("TNB000016", id_buf);
    wifi_generic_write(&wifi, id_buf, len_out);
     
    Delay_ms(2000);

    
}

void application_task ( void ) {
    measured_temperature = irthermo3v3_get_t_ambient( &irthermo3v3 );
    object_temperature = irthermo3v3_get_t_object( &irthermo3v3 );
    log_printf( &logger, " Ambient Temperature: %.2f C\r\n ", measured_temperature );
    log_printf( &logger, " Object  Temperature: %.2f C\r\n ", object_temperature );
    log_printf( &logger, "------------------------------\r\n " );
    
    irthermo_data.ambient_temp = measured_temperature * 100;
    irthermo_data.object_temp =  object_temperature * 100;
    len_out = pack_sensors_data((uint8_t *)&irthermo_data, sizeof(irthermo_data), buf, 1);
    wifi_generic_write(&wifi, buf, len_out);
    
    Delay_ms( 1000 );
}

void main ( void ) {
    application_init( );

    for ( ; ; ) {
        application_task( );
    }
}

// ------------------------------------------------------------------------ END
