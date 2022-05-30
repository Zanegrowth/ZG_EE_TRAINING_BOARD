/**
 * @file main.c
 * @brief Main function for Hello_world application.
 */

// #include "board.h"

// char uart_rd;


/// @brief Application init function.
void application_init()
{
    /// @todo Initialize Driver objects.
    /// @example
  
    //Setting freq to 140MHZ
    PLLFBD = 70;        // PLL multiplier M = 70
    CLKDIV = 0x0000;    // PLL prescaler N1=2, PLL postscaler N2=2
    
    
    ANSELA = 0x00;      //Convert all I/O pins to digital
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;
    ANSELG = 0x00;
    
    TRISA = 0;             // Initialize PORTA as output

 
 
}


/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example


    LATA.B0 = 1;
    Delay_ms(1000);
//     LATA = 0;
    LATA.B0 = 0;
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
