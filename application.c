/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include <xc.h>
//#define _XTAL_FREQ 4000000

keypad_t keypad1 = {
  .keypad_row_pins [0].port = PORTC_INDEX,
  .keypad_row_pins [0].pin = GPIO_PIN0,
  .keypad_row_pins [0].direction = GPIO_DIRECTION_OUTPUT,
  
  
};


int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while (1) {

    }
    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;

}
