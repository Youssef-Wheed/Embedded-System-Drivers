/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include <xc.h>
//#define _XTAL_FREQ 4000000

relay_t relay_1 = {
  .relay_port = PORTC_INDEX,
  .relay_pin = GPIO_PIN0,
  .relay_status = RELAY_OFF_STATUS
};

int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while (1) {
        ret = relay_trun_on(&relay_1);
        __delay_ms(3000);
        ret = relay_trun_off(&relay_1);
        __delay_ms(3000);
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = relay_initialize(&relay_1);
}
