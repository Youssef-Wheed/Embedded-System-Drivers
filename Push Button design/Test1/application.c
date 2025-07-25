/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"

led_t led1 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};
led_t led2 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN1, .led_status = GPIO_LOW};

button_t btn_high = {
    .button_pin.port = PORTC_INDEX,
    .button_pin.pin = GPIO_PIN2,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};

button_t btn_low = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = GPIO_PIN0,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = GPIO_HIGH,
    .button_connection = BUTTON_ACTIVE_LOW,
    .button_state = BUTTON_RELEASED
};

button_state_t btn_high_status = BUTTON_RELEASED;
button_state_t btn_low_status  = BUTTON_RELEASED;

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    ret = button_initialize(&btn_high);
    ret = button_initialize(&btn_low);
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);

    while(1){
        ret = button_read_state(&btn_high, &btn_high_status);
        ret = button_read_state(&btn_low, &btn_low_status);
        
        if(BUTTON_PRESSED == btn_high_status){
            led_turn_on(&led1);
        }
        else{
            led_turn_off(&led1);
        }
        
        if(BUTTON_PRESSED == btn_low_status){
            led_turn_on(&led2);
        }
        else{
            led_turn_off(&led2);
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}


