/****************************************************************************
** Copyright (C) 2020 MikroElektronika d.o.o.
** Contact: https://www.mikroe.com/contact
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
** OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
** DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
** OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
**  USE OR OTHER DEALINGS IN THE SOFTWARE.
****************************************************************************/

/*!
 * @file irthermo3v3.c
 * @brief IrThermo 3V3 Click Driver.
 */

#include "irthermo3v3.h"

void irthermo3v3_cfg_setup ( irthermo3v3_cfg_t *cfg ) {
    // Communication gpio pins
    
    cfg->scl  = HAL_PIN_NC;
    cfg->sda  = HAL_PIN_NC;

    // Additional gpio pins
    
    cfg->pwm = HAL_PIN_NC;

    cfg->i2c_speed   = I2C_MASTER_SPEED_STANDARD;
    cfg->i2c_address = IRTHERMO3V3_SET_DEV_ADDR;
}

err_t irthermo3v3_init ( irthermo3v3_t *ctx, irthermo3v3_cfg_t *cfg ) {
    i2c_master_config_t i2c_cfg;

    i2c_master_configure_default( &i2c_cfg );

    i2c_cfg.scl = cfg->scl;
    i2c_cfg.sda = cfg->sda;

    ctx->slave_address = cfg->i2c_address;

    if ( i2c_master_open( &ctx->i2c, &i2c_cfg ) == I2C_MASTER_ERROR ) {
        return I2C_MASTER_ERROR;
    }

    if ( i2c_master_set_slave_address( &ctx->i2c, ctx->slave_address ) == I2C_MASTER_ERROR ) {
        return I2C_MASTER_ERROR;
    }

    if ( i2c_master_set_speed( &ctx->i2c, cfg->i2c_speed ) == I2C_MASTER_ERROR ) {
        return I2C_MASTER_ERROR;
    }

    digital_in_init( &ctx->pwm, cfg->pwm );
   
    return I2C_MASTER_SUCCESS;
}

float irthermo3v3_get_t_ambient ( irthermo3v3_t* ctx ) {
    uint8_t temp[ 1 ];
    uint8_t read_data[ 3 ];
    uint16_t value;
    float temperature;

    temp[ 0 ] = 0x06;

    i2c_master_write_then_read( &ctx->i2c, temp, 1, read_data, 3 );

    value = ( ( uint16_t )read_data[ 1 ] << 8 ) | ( read_data[ 0 ] );
    temperature = ( float )( value * 0.02 ) - 273.15;

    return temperature;
}

float irthermo3v3_get_t_object ( irthermo3v3_t* ctx ) {
    uint8_t temp[ 1 ];
    uint8_t read_data[ 3 ];
    uint16_t value;
    float temperature;

    temp[ 0 ] = 0x07;

    i2c_master_write_then_read( &ctx->i2c, temp, 1, read_data, 3 );

    value = ( ( uint16_t )read_data[ 1 ] << 8 ) | ( read_data[ 0 ] );
    temperature = ( float )( value * 0.02 ) - 273.15;

    return temperature;
}

uint16_t irthermo3v3_read_reg ( irthermo3v3_t* ctx, uint8_t address ) {
    uint8_t temp[ 1 ];
    uint8_t read_data[ 3 ];
    uint16_t value;

    temp[ 0 ] = address;

    i2c_master_write_then_read( &ctx->i2c, temp, 1, read_data, 3 );

    value = ( ( uint16_t )read_data[ 1 ] << 8 ) | ( read_data[ 0 ] );

    return value;
}

// ------------------------------------------------------------------------- END
