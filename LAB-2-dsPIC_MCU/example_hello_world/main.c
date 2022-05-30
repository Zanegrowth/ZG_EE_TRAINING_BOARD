/**
 * @file main.c
 * @brief Main function for Hello_world application.
 */

// char uart_rd;


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
    
 
}


/// @brief Application task.
void application_task()
{
    /// @todo Implement your application code here.
    /// @example

    UART1_Write_Text("Hello world\n\r");

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
