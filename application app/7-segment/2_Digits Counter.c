/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"
#include <xc.h>
//#define _XTAL_FREQ 4000000

pin_config_t seg1_enable = {
    .port = PORTD_INDEX,
    .pin = GPIO_PIN0,
    .logic = GPIO_LOW,
    .direction = GPIO_DIRECTION_OUTPUT,
};

pin_config_t seg2_enable = {
    .port = PORTD_INDEX,
    .pin = GPIO_PIN1,
    .logic = GPIO_LOW,
    .direction = GPIO_DIRECTION_OUTPUT,
};

segment_t seg1 = {
    // pin 1 
    .segment_pin[0].port = PORTC_INDEX,
    .segment_pin[0].pin = GPIO_PIN0,
    .segment_pin[0].logic = GPIO_LOW,
    .segment_pin[0].direction = GPIO_DIRECTION_OUTPUT,

    // pin 2 
    .segment_pin[1].port = PORTC_INDEX,
    .segment_pin[1].pin = GPIO_PIN1,
    .segment_pin[1].logic = GPIO_LOW,
    .segment_pin[1].direction = GPIO_DIRECTION_OUTPUT,

    // pin 3 
    .segment_pin[2].port = PORTC_INDEX,
    .segment_pin[2].pin = GPIO_PIN2,
    .segment_pin[2].logic = GPIO_LOW,
    .segment_pin[2].direction = GPIO_DIRECTION_OUTPUT,

    // pin 4 
    .segment_pin[3].port = PORTC_INDEX,
    .segment_pin[3].pin = GPIO_PIN3,
    .segment_pin[3].logic = GPIO_LOW,
    .segment_pin[3].direction = GPIO_DIRECTION_OUTPUT,

    //  seven_segment type
    .segment_type = SEGMENT_COMMON_ANODE

};

uint8 number = 48 , counter = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while (1) {


        for (counter = 0; counter <= 50; counter++) {
            ret = seven_segment_write_number(&seg1, (uint8) (number % 10));
            ret = gpio_pin_write_logic(&seg1_enable, GPIO_HIGH);
            __delay_ms(10);
            ret = gpio_pin_write_logic(&seg1_enable, GPIO_LOW);

            ret = seven_segment_write_number(&seg1, (uint8) (number / 10));
            ret = gpio_pin_write_logic(&seg2_enable, GPIO_HIGH);
            __delay_ms(10);
            ret = gpio_pin_write_logic(&seg2_enable, GPIO_LOW);
        }
        
        number++;
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = seven_segment_intialize(&seg1);
    ret = gpio_pin_intialize(&seg1_enable);
    ret = gpio_pin_intialize(&seg2_enable);

}
