#include "wifi_to_platform.h"



uint16_t crc16(uint8_t *p_data, uint8_t length)
{
  uint8_t x;
  uint16_t crc16 = 0xFFFF;

  while (length--)
  {
    x = crc16 >> 8 ^ *p_data++;
    x ^= x >> 4;
    crc16 = (crc16 << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
  }
  return crc16;
}


void wifi_cfg_setup ( wifi_cfg_t *cfg )
{
    // Communication gpio pins 

    cfg->rx_pin = HAL_PIN_NC;
    cfg->tx_pin = HAL_PIN_NC;
    
    // Additional gpio pins

    cfg->rst = HAL_PIN_NC;
    cfg->en   = HAL_PIN_NC;

    cfg->baud_rate      = 9600;
    cfg->data_bit       = UART_DATA_BITS_DEFAULT;
    cfg->parity_bit     = UART_PARITY_DEFAULT;
    cfg->stop_bit       = UART_STOP_BITS_DEFAULT;
    cfg->uart_blocking  = false;
}


uint8_t wifi_init ( wifi_t *ctx, wifi_cfg_t *cfg )
{
    uart_config_t uart_cfg;
    
    uart_configure_default( &uart_cfg );

    // Ring buffer mapping
    ctx->uart.tx_ring_buffer = ctx->uart_tx_buffer;
    ctx->uart.rx_ring_buffer = ctx->uart_rx_buffer;

    // UART module config
    uart_cfg.rx_pin = cfg->rx_pin;  // UART RX pin. 
    uart_cfg.tx_pin = cfg->tx_pin;  // UART TX pin. 
    uart_cfg.tx_ring_size = sizeof( ctx->uart_tx_buffer );  
    uart_cfg.rx_ring_size = sizeof( ctx->uart_rx_buffer );

    uart_open( &ctx->uart, &uart_cfg );
    uart_set_baud( &ctx->uart, cfg->baud_rate );
    uart_set_parity( &ctx->uart, cfg->parity_bit );
    uart_set_stop_bits( &ctx->uart, cfg->stop_bit );  
    uart_set_data_bits( &ctx->uart, cfg->data_bit );

    uart_set_blocking( &ctx->uart, cfg->uart_blocking );

    // Output pins 

    digital_out_init( &ctx->rst, cfg->rst );
    digital_out_init( &ctx->en, cfg->en );

    return WIFI_OK;
}

void wifi_generic_write ( wifi_t *ctx, char *data_buf, uint16_t len )
{
    uart_write( &ctx->uart, data_buf, len );
}

int16_t wifi_generic_read ( wifi_t *ctx, char *data_buf, uint16_t max_len )
{
    return uart_read( &ctx->uart, data_buf, max_len );
}



uint16_t pack_sensors_data(uint8_t *data_in, uint16_t len_in, uint8_t *data_out, uint8_t fist)
{
  static uint16_t len_out = 0; //, len_all = 0;
  static uint8_t index = 0, number = 0;
  static uint8_t last_id[4] = {0}, id_cnt = 0;
  uint8_t data_len = 0;

  // data_len = sizeof(data_in);
  if(fist){
    id_cnt = 0;
    number = 1;
    index = 0;
    // len_all = len_in;
    data_out[index++] = '$';              // index[0] : header
    data_out[index++] = SENSOR_MODE;       // index[1] : mode
        // data_out[index++] = len_all; // index[1] : len
    data_out[index++] = number; // index[1] : Number of sensors
  }else {
    number++;
    for(uint8_t i=0; i<id_cnt; i++){
      if (last_id[i] == data_in[0]) //Check not double id.
      {
        number--;
        return len_out;
      }
    }

    if (number > MAX_SENSORS )
    {
      number--;
      return len_out;
    }
    index -= 4;            //With out CRC and footer
    // len_all += len_in;
    // data_out[1] = len_all; // index[1] : len
    data_out[2] = number;
  }

  memcpy(&data_out[index], data_in, len_in); // index[3] : fist byte of data
  index += len_in;

  uint16_t crc_checksum = crc16(data_out, index);
  // print_debugDEC_HEX("crc: ", crc_checksum);
  data_out[index++] = (uint8_t)(crc_checksum >> 8);
  data_out[index++] = (uint8_t)(crc_checksum & 0xFF);
  data_out[index++] = '\r';
  data_out[index++] = '\n';
  len_out = index;

  last_id[id_cnt++] = data_in[0];
  // last_id = data_in[0];
  return len_out;
}

uint16_t pack_ssid_data(const char *ssid, const char *pass, uint8_t *data_out)
{

  uint8_t index = 0;
  uint8_t len = 0;
  uint8_t ssid_len = strlen(ssid);
  uint8_t pass_len = strlen(pass);

  data_out[index++] = '$'; // index[0] : header
  data_out[index++] = MESSAGE_MODE; // index[3] : id = 0 is device id
  data_out[index++] = SSID_TYPE;
  data_out[index++] = ssid_len;
  memcpy(&data_out[index], ssid, ssid_len);
  index += ssid_len;
  data_out[index++] = pass_len;
  memcpy(&data_out[index], pass, pass_len);
  index += pass_len;

  uint16_t crc_checksum = crc16(data_out, index);
  // print_debugDEC_HEX("crc: ", crc_checksum);
  data_out[index++] = (uint8_t)(crc_checksum >> 8);
  data_out[index++] = (uint8_t)(crc_checksum & 0xFF);
  data_out[index++] = '\r';
  data_out[index++] = '\n';

  return index;
}

uint16_t pack_device_id_data(const char *ch, uint8_t *data_out)
{
  uint8_t index = 0;
  uint8_t len = strlen(ch);

  data_out[index++] = '$';     // index[0] : header
  data_out[index++] = MESSAGE_MODE; // index[3] : id = 0 is device id
  data_out[index++] = DEVICE_ID_TYPE;
  data_out[index++] = len;

  memcpy(&data_out[index], ch, len);
  index += len;

  uint16_t crc_checksum = crc16(data_out, index);
  // print_debugDEC_HEX("crc: ", crc_checksum);
  data_out[index++] = (uint8_t)(crc_checksum >> 8);
  data_out[index++] = (uint8_t)(crc_checksum & 0xFF);
  data_out[index++] = '\r';
  data_out[index++] = '\n';

  return index;
}
