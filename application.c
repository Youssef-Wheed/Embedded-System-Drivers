/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include <xc.h>
//#define _XTAL_FREQ 4000000

uint8 keypad_value = ZERO_INIT;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while (1) {
        ret = keypad_get_value(&keypad1,&keypad_value);
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
