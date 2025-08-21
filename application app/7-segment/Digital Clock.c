/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include <xc.h>
//#define _XTAL_FREQ 4000000

uint8 seconds = 55, minutes = 59, hours = 23;
uint8 counter = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while (1) {
        for (counter = 0; counter < 50; counter++) {
            ret = gpio_port_write_logic(PORTD_INDEX, 0x3E); // 0011 1110
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (hours / 10)));
            __delay_us(3333);
            ret = gpio_port_write_logic(PORTD_INDEX, 0x3D); // 0011 1101
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (hours % 10)));
            __delay_us(3333);
            ret = gpio_port_write_logic(PORTD_INDEX, 0x3B); // 0011 1011
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (minutes / 10)));
            __delay_us(3333);
            ret = gpio_port_write_logic(PORTD_INDEX, 0x37); // 0011 0111
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (minutes % 10)));
            __delay_us(3333);
            ret = gpio_port_write_logic(PORTD_INDEX, 0x2F); // 0010 1111
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (seconds / 10)));
            __delay_us(3333);
            ret = gpio_port_write_logic(PORTD_INDEX, 0x1E); // 0001 1111
            ret = gpio_port_write_logic(PORTC_INDEX, ((uint8) (seconds % 10)));
            __delay_us(3333);
        }
        seconds++;
        if(seconds == 60) {
            minutes++;
            seconds = 0;
        }
        if(minutes == 60){
            hours++;
            minutes = 0;
        }
        if (hours == 24)
        {
            hours++;
            hours = 0;
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = gpio_port_direction_intialize(PORTC_INDEX, 0xF0);
    ret = gpio_port_direction_intialize(PORTD_INDEX, 0xC0);
}
