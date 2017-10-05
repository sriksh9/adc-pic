/*
 * File:   acclero.c
 * Author: Srihari Koripalli
 *
 * Created on 17 June, 2017, 11:40 AM
 */


#define _XTAL_FREQ 16000000

#include <xc.h>
#include <Custom_Headers/config45k22.h> //if you configure you Microcontroller in MPLAB, this header is not required
#include <Custom_Headers/glcd.h>        //locate the header file on your PC
#include <Custom_Headers/adc45k22.h>    //locate the header file on your PC

void main(void) {
    unsigned int x, y, z;
    glcd_on();
    glcd_clear();
    adc_init();
    while(1)
    {
        glcd_clear();
        x = adc_read(0);
        y = adc_read(1);
        z = adc_read(2);
        goto_xy(0,0);
        glcd_string("X : ");
        goto_xy(70,0);
        glcd_num(x);
        
        goto_xy(0,10);
        glcd_string("Y : ");
        goto_xy(70,10);
        glcd_num(y);
        
        goto_xy(0,20);
        glcd_string("Z : ");
        goto_xy(70,20);
        glcd_num(z);
        
        __delay_ms(100);
        
    }
    return;
}
