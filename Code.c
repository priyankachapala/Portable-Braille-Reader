// CONFIG
#pragma config FOSC = HS       // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF        // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
//End of CONFIG registers


#define _XTAL_FREQ 20000000
#include<xc.h>

//******Initialize Bluetooth using USART********//
void Initialize_Bluetooth()
{
   
   //Set the pins of RX and TX//
    TRISC6=1;
    TRISC7=1;
    
  
    BRGH  = 1;  // for high baud_rate
    SPBRG = 129;
    
    //Turn on Asyc. Serial Port//
    SYNC=0;
    SPEN=1;
    
    //Set 8-bit reception and transmission
    RX9=0;
    TX9=0;

   //Enable transmission and reception//
    TXEN=1; 
    CREN=1; 
    
   /* //Enable global and ph. interrupts//
    GIE = 1;
    PEIE= 1;
  */
    //Enable interrupts for Tx. and Rx.//
    RCIE=1;
    TXIE=1;
}
//___________BT initialized_____________//

//Function to load the Bluetooth Rx. buffer with one char.//
void BT_load_char(char byte)  
{
    TXREG = byte;
    while(!TXIF); 
    __delay_ms(10);
    while(!TRMT);
    __delay_ms(10);
}
//End of function//
void clear_tx_read(void){
    TXREG=0;
    
}
//Function to Load Bluetooth Rx. buffer with string//
void BT_load_string(char* string)
{
    while(*string)
    BT_load_char(*string++);
    clear_tx_read();
}
//End of function//

//Function to broadcast data from RX. buffer//
void BT()
{
  TXREG=13; 
  __delay_ms(500); 
  }
//End of function//

//Function to get a char from Rx.buffer of BT//
char BT_get_char(void)   
{
    if(OERR) // check for over run error 
    {
        CREN = 0;
        CREN = 1; //Reset CREN
    }
    
    if(RCIF==1) //if the user has sent a char return the char (ASCII value)
    {
    while(!RCIF);
    RCIF=0;
    return RCREG;
    
    }
    else //if user has sent no message return 0
        return 0;
}

void clear_bt_read(void){
    if(RCIF==1) //if the user has sent a char return the char (ASCII value)
    {
    while(!RCIF);
    RCIF=0;
    RCREG=0;
    
    
    }
    
}
//End of function/

void main(void)
{ 
    //Scope variable declarations//
    int p;
    char get_value[10];
    int array[26]={0x20, 0x28, 0x30, 0x34, 0x24, 0x38, 0x3C, 0x2C, 0x18, 0x1C, 0x22, 0x2A, 0x32, 0x36, 0x26, 0x3A, 0x3E, 0x2E, 0x1A, 0x1E, 0x23, 0x2B, 0x1D, 0x33, 0x37, 0x27};
    //End of variable declaration//
   
    //I/O Declarations//
    TRISB=0;
    __delay_ms(100);
   // __delay_ms(500);
    //End of I/O declaration//
   
   Initialize_Bluetooth(); //lets get our bluetooth ready for action
   
   //Show some introductory message once on power up//
   BT_load_string("Bluetooth Initialized and Ready");
   BT();
    clear_tx_read();
 
   //End of message//
    
    while(1) //The infinite lop
    { 
       
     for(int i=0; i<10; i++) { 
    get_value[i]= BT_get_char(); //Read the char. received via BT
    
     int j,k;
        j=(int)get_value[i];
        k=((int)get_value[i])-97;
        PORTB=array[k];
        __delay_ms(500);
        PORTB=0x00;
        BT_load_char(j);
        BT();
        
     } 
          }
    } 

