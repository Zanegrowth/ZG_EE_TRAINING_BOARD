#ifndef WIFI_TO_PLATFORM_H
#define WIFI_TO_PLATFORM_H

#include "drv_digital_out.h"
#include "drv_digital_in.h"
#include "drv_uart.h"

// #define RXD2_IO 23
// #define TXD2_IO 18

#define WIFI_OK           0x00
#define WIFI_INIT_ERROR   0xFF

#define WIFIBLE_MAP_MIKROBUS( cfg, mikrobus ) \
  cfg.tx_pin  = MIKROBUS( mikrobus, MIKROBUS_TX ); \
  cfg.rx_pin  = MIKROBUS( mikrobus, MIKROBUS_RX ); \
  cfg.rst = MIKROBUS( mikrobus, MIKROBUS_RST ); \
  cfg.en = MIKROBUS( mikrobus, MIKROBUS_CS )


#define DRV_RX_BUFFER_SIZE 1024
  
  
#define AIR_QUALITY_8CLICK_ID 0x01
#define ENVIRONMENT_3CLICK_ID 0x02
#define HEART_RATE_10CLICK_ID 0x03
#define OXIMETER_2CLICK_ID 0x04
#define PROXIMITY_15CLICK_ID 0x05
#define IRHTERMO_CLICK_ID 0x06
#define MICROWAVE_2CLICK_ID 0x07
#define HALL_CURRENT_4CLICK_ID 0x08
#define LOAD_CELL_5CLICK_ID 0x09
#define VIBRA_SENSE_CLICK_ID 0x0A
#define IR_GESTURE_CLICK_ID 0x0B
#define EARTHQUAKE_CLICK 0x0C
#define DOF_13CLICK_ID 0x0D

#define MESSAGE_MODE              0x01
#define SENSOR_MODE               0x02

// #define USER_SSID_TYPE            0x01
// #define PASS_SSID_TYPE            0x02
#define SSID_TYPE                 0x01
#define DEVICE_ID_TYPE            0x02
#define MAX_SENSORS               3

typedef struct
{
  /* data */
  uint8_t id;
  uint16_t temp; // temp * 100
  uint16_t humd; // humd * 100
  uint16_t pressure;
  uint16_t gasRes;
  uint16_t accel_x;
  uint16_t accel_y;
  uint16_t accel_z;
  uint16_t gyro_x;
  uint16_t gyro_y;
  uint16_t gyro_z;
  uint16_t mag_x;
  uint16_t mag_y;
  uint16_t mag_z;
}__attribute__((packed)) dof_13click;

typedef struct 
{
  /* data */
  uint8_t id;
  uint8_t aqi;
  uint16_t oZone;
  uint16_t humd;
}__attribute__((packed)) air_quality_8click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint16_t temp; //temp * 100 
  uint16_t humd; //humd * 100
  uint16_t pressure;
  uint16_t gasRes; 
}__attribute__((packed)) environment_3click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint16_t ir;
  uint16_t red;
  uint16_t green;
  uint16_t blue;
}__attribute__((packed)) heart_rate_10click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint8_t pulse;
}__attribute__((packed)) oximeter_2click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint16_t distance;
}__attribute__((packed)) proximity_15click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint16_t ambient_temp; // temp * 100
  uint16_t object_temp;  // temp * 100 
}__attribute__((packed)) irthermo_click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint8_t motion_detection;

}__attribute__((packed)) microwave_2click_t;

typedef struct
{
  /* data */
  uint8_t  id;
  uint16_t current;
}__attribute__((packed)) hall_carrent_4click_t;

typedef struct
{
  /* data */
  uint8_t  id;
  uint16_t weight;
}__attribute__((packed)) load_cell_5click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint8_t status;
}vibra_sense_click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint8_t gesture;
}ir_gesture_click_t;

typedef struct
{
  /* data */
  uint8_t id;
  uint16_t max_SI;
  uint16_t max_PGA;
}earthquake_click_t;
  

typedef struct
{
    // Output pins 

    digital_out_t rst;
    digital_out_t en;
    
    // Modules 

    uart_t uart;

    char uart_rx_buffer[ DRV_RX_BUFFER_SIZE ];
    char uart_tx_buffer[ DRV_RX_BUFFER_SIZE ];

} wifi_t;


typedef struct
{
    // Communication gpio pins 

    pin_name_t rx_pin;
    pin_name_t tx_pin;
    
    // Additional gpio pins 

    pin_name_t rst;
    pin_name_t en;

    // static variable 

    uint32_t          baud_rate;     // Clock speed.
    bool              uart_blocking;
    uart_data_bits_t  data_bit;      // Data bits.
    uart_parity_t     parity_bit;    // Parity bit.  
    uart_stop_bits_t  stop_bit;      // Stop bits.    

} wifi_cfg_t;


void wifi_cfg_setup ( wifi_cfg_t *cfg );

uint8_t wifi_init ( wifi_t *ctx, wifi_cfg_t *cfg );

void wifi_generic_write ( wifi_t *ctx, char *data_buf, uint16_t len );

int16_t wifi_generic_read ( wifi_t *ctx, char *data_buf, uint16_t max_len );

uint16_t pack_sensors_data(uint8_t *data_in, uint16_t len_in, uint8_t *data_out, uint8_t fist);

uint16_t pack_ssid_data(const char *ssid, const char *pass, uint8_t *data_out);

uint16_t pack_device_id_data(const char *ch, uint8_t *data_out);



#endif
