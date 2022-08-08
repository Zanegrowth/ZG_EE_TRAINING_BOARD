/*!
 * \file 
 * \brief c13DOF Click example
 * 
 * # Description
 * This example displays values registered by sensors on click board.
 * 
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Initialization driver enables -
 * BME680 Low power gas, pressure, temperature & humidity sensor, 
 * BMI088 6-axis Motion Tracking Sensor and
 * BMM150 Geomagnetic Sensor, also write log.
 * 
 * ## Application Task  
 * This is a example which demonstrates the use of 13DOF Click board.
 * Measures and display temperature in degrees Celsius [ C ], humidity data [ % ], 
 * pressure [ mbar ] and gas resistance data from the BME680 sensor.
 * Measures and display Accel and Gyro data coordinates values 
 * for X-axis, Y-axis and Z-axis from the BMI088 sensor.
 * Measures and display Geomagnetic data coordinates values for 
 * X-axis, Y-axis and Z-axis from the BMM150 sensor.
 * Results are being sent to the Usart Terminal where you can track their changes.
 * All data logs write on usb uart changes for each second.
 * 
 * 
 * \author MikroE Team
 *
 */
// ------------------------------------------------------------------- INCLUDES

#include "board.h"
#include "log.h"
#include "c13dof.h"
#include "wifi_to_platform.h"

// ------------------------------------------------------------------ VARIABLES

static c13dof_t c13dof;
static log_t logger;
float temperature;
float pressure;
float humidity;
int32_t gas_res;
int16_t accel_x;
int16_t accel_y;
int16_t accel_z;
int16_t gyro_x;
int16_t gyro_y;
int16_t gyro_z;
int16_t mag_x;
int16_t mag_y;
int16_t mag_z;
uint16_t r_hall;
uint8_t ready_check;

static wifi_t wifi;
uint8_t len_out = 0;
uint8_t buf[256];
dof_13click dof_13_data = {
    .id = DOF_13CLICK_ID
};
// ------------------------------------------------------ APPLICATION FUNCTIONS

void application_init ( void )
{
    log_cfg_t log_cfg;
    wifi_cfg_t cfg1;
    c13dof_cfg_t cfg2;
  

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
    Delay_ms(2000);
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.
    
    wifi_cfg_setup( &cfg1 );
    WIFIBLE_MAP_MIKROBUS( cfg1, MIKROBUS_1 );
    wifi_init( &wifi, &cfg1 );

    c13dof_cfg_setup( &cfg2 );
    C13DOF_MAP_MIKROBUS( cfg2, MIKROBUS_2 );
    c13dof_init( &c13dof, &cfg2 );
    c13dof_default_cfg( &c13dof );
    
    uint8_t ssid_buf[64];
    uint8_t id_buf[32];

    len_out = pack_ssid_data("Zanegrowth1", "12345678", ssid_buf);
    wifi_generic_write(&wifi, ssid_buf, len_out);
    len_out = pack_device_id_data("TNB000023", id_buf);
    wifi_generic_write(&wifi, id_buf, len_out);
     
    Delay_ms(2000);

    
    
}

void application_task ( void )
{
    temperature = c13dof_bme680_get_temperature( &c13dof );

    log_printf( &logger, "----------------------------------------------------------\n");
    log_printf( &logger, "Temperature : %.2f C \r\n", temperature );
    dof_13_data.temp = temperature * 100; 

    humidity = c13dof_bme680_get_humidity( &c13dof );
    log_printf( &logger, "Humidity : %.2f %% \r\n", humidity );
    dof_13_data.humd = humidity * 100;

    pressure = c13dof_bme680_get_pressure( &c13dof );
    log_printf( &logger, "Pressure : %.2f mbar \r\n", pressure );
    dof_13_data.pressure = pressure;

    gas_res = c13dof_bme680_get_gas_resistance( &c13dof );
    log_printf( &logger, "Gas Resistance : %ld \r\n", gas_res );
//     dof_13_data.gasRes = gas_res / 100;
    
    ready_check = c13dof_bmm150_check_ready( &c13dof );

    while ( ready_check != C13DOF_BMM150_DATA_READY )
    {
        ready_check = c13dof_bmm150_check_ready( &c13dof );
    }
    
    c13dof_bmi088_read_accel( &c13dof, &accel_x, &accel_y, &accel_z );
    c13dof_bmi088_read_gyro( &c13dof, &gyro_x, &gyro_y, &gyro_z );
    c13dof_bmm150_read_geo_mag_data( &c13dof, &mag_x, &mag_y, &mag_z, &r_hall );
    
    log_printf( &logger, "Accel X : %d ", accel_x );
    log_printf( &logger, " Y : %d ", accel_y   );
    log_printf( &logger, " Z : %d \r\n", accel_z   );
    dof_13_data.accel_x  = accel_x ;
    dof_13_data.accel_y  = accel_y ;
    dof_13_data.accel_z  = accel_z ;

    
    log_printf( &logger, "Gyro X : %d ", gyro_x  );
    log_printf( &logger, " Y : %d ", gyro_y  );
    log_printf( &logger, " Z : %d \r\n", gyro_z  );
    dof_13_data.gyro_x = gyro_x ;
    dof_13_data.gyro_y = gyro_y ;
    dof_13_data.gyro_z = gyro_z ;
    
        
    log_printf( &logger, "Mag X : %d ", mag_x );
    log_printf( &logger, " Y : %d ", mag_y  );
    log_printf( &logger, " Z : %d \r\n", mag_z);
    dof_13_data.mag_x = mag_x ;
    dof_13_data.mag_y = mag_y ;
    dof_13_data.mag_z = mag_z ;
    
    
    len_out = pack_sensors_data((uint8_t *)&dof_13_data, sizeof(dof_13_data), buf, 1);
    wifi_generic_write(&wifi, buf, len_out);

    Delay_ms ( 2000 );
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
