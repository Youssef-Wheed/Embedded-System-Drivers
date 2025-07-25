/* 
 * File:   application.c
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"

led_t led1 = {.port_name = PORTC_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};

button_t btn_high = {
    .button_pin.port = PORTC_INDEX,
    .button_pin.pin = GPIO_PIN2,
    .button_pin.direction = GPIO_DIRECTION_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};

button_state_t btn_high_status = BUTTON_RELEASED;
button_state_t btn_high_valid_status = BUTTON_RELEASED;
button_state_t btn_high_last_valid_status = BUTTON_RELEASED;

led_status_t led1_status = LED_OFF;
         
uint32 btn_high_valid = 0;

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    
    application_intialize();
    
    ret = button_initialize(&btn_high);
    ret = led_initialize(&led1);

    while(1){
        ret = button_read_state(&btn_high, &btn_high_status);
        
        if(BUTTON_PRESSED == btn_high_status){
            btn_high_valid++;
            if(btn_high_valid > 500){
                btn_high_valid_status = BUTTON_PRESSED;
            }
        }
        else{
            btn_high_valid = 0;
            btn_high_valid_status = BUTTON_RELEASED;
        }
        
        if(btn_high_valid_status != btn_high_last_valid_status){
            btn_high_last_valid_status = btn_high_valid_status;
            if(BUTTON_PRESSED == btn_high_valid_status){
                if(LED_OFF == led1_status){
                    led_turn_on(&led1);
                    led1_status = LED_ON;
                }
                else{
                    led_turn_off(&led1);
                    led1_status = LED_OFF;
                }
            }
        }
        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}


