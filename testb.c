// This program causes the LED to light up when an
// input voltage reaches a threshold.
//
// The A/D operates in automatic mode.
//
// Connections:
//      8:  Pot         (analog input -- AN14)
//      14: LED         (digital output -- RA6)
// File:    mech_ad_led_auto.c
// Author:  Mark Colton


#include <xc.h>

#pragma config FNOSC = FRCDIV   // 8 MHz FRC oscillator with postscaler
#pragma config OSCIOFNC = OFF   // Turn off clock output on pin 8
#pragma config SOSCSRC = DIG    // Turn off secondary oscillator on pins 9&10

void config_ad(void);

int main()
{    
    // Postscale oscillator
    _RCDIV = 0b011;             // Divide-by-8 postscaler
    
    // Configure pin 14 (RA6) as digital out for LED
    _TRISA6 = 0;
    _LATA6 = 0;
    
    // Configure pin 8 (RA3) as analog input for pot
    _TRISA3 = 1;
    _ANSA3 = 1;
       
    // Configure peripherals
    config_ad(); 

        
    while(1)
    {
        if (ADC1BUF14 >= 2048)
        {
            _LATA6 = 1;
        }
        else
        {
            _LATA6 = 0;
        }
    }
    
    return 0;
}
