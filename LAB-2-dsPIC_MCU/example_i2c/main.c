/**
 * @file main.c
 * @brief Main function for Hello_world application.
 */

// char uart_rd;
#include <stdint.h>


uint8_t err = 1;
uint8_t reslt = 0;
unsigned char buf[255];
char rdData[255];


void read_sensor(uint8_t addr, char *rd){
    
     uint8_t addr_w = addr << 1 | 0x00;
     uint8_t addr_r = addr << 1 | 0x01;
    
    I2C2_Start();  
    
    err = I2C2_Write(addr_w); 
    err = I2C2_Write(0x06); 
    I2C2_Restart();
    err = I2C2_Write(addr_r); 
    uint8_t j = 0;
    while (j< 3) {
        rd[j] = I2C2_Read(0);  // read data (YES acknowledge)
        while (!I2C2_Is_Idle())
            asm nop;  
        j++ ;
    }

    // Read the data (NO acknowledge)
    
    I2C2_Stop();
    

}

/// @brief Application init function.
void application_init()
{
    /// @todo Initialize Driver objects.
    /// @example
  
        // Setting output frequency to 140MHz
    PLLFBD = 70;             // PLL multiplier M=70
    CLKDIV = 0x0000;         // PLL prescaler N1=2, PLL postscaler N2=2
        
    
    ANSELA = 0x00;      //Convert all I/O pins to digital
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;
    ANSELG = 0x00;

    PPS_Mapping(124, _INPUT,  _U1RX);    //Sets pin PR100 to be Input, and maps U1RX to it
    PPS_Mapping(125, _OUTPUT, _U1TX);   //Sets pin PR101 to be Input, and maps U1RX to it
    
    UART1_Init_Advanced(115200,_UART_8BIT_NOPARITY, _UART_ONE_STOPBIT, _UART_HI_SPEED); //If want to use high UART hi speed
    Delay_ms(100);
    
    TRISF.B0 = 1;
    
    I2C2_Init(100000);
    UART1_Write_Text("Program Start\n\r");
 
}


/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example

  read_sensor(0x5A, rdData);
   
  uint16_t value;
  float temperature;
    value = ( ( uint16_t )rdData[ 1 ] << 8 ) | ( rdData[ 0 ] );
    temperature = ( float )( value * 0.02 ) - 273.15;
    sprintf(buf, "Temperature:: %.2f\r\n ", temperature);
    UART1_Write_Text(buf);
    Delay_ms(1000);
}

void main(void)
{
    application_init();
    /* Replace with your application code */
    while (1)
    {
        application_task();
    }
}
