/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include <xc.h>
//#define _XTAL_FREQ 4000000

uint8 ones = 0;
uint8 tens = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while (1) {
        for (tens = 0; tens < 10; tens++) {
            ret = gpio_port_write_logic(PORTD_INDEX, tens);
            for (ones = 0; ones < 10; ones++) {
                ret = gpio_port_write_logic(PORTC_INDEX, ones);
                __delay_ms(250);
            }
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = gpio_port_direction_intialize(PORTC_INDEX, 0x80);
    ret = gpio_port_direction_intialize(PORTD_INDEX, 0x80);

}
