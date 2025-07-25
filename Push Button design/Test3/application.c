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
    
uint32 btn_high_valid = 0;
uint8 Program_Selected = 0;

void program_1(void){
    led_turn_on(&led1);
    __delay_ms(500);
    led_turn_off(&led1);
    __delay_ms(500);
}

void program_2(void){
    uint8 counter = 0;
    for(counter = 0; counter < 2; counter ++){
        led_turn_on(&led1);
        __delay_ms(500);
        led_turn_off(&led1);
        __delay_ms(500);
    }
}

void program_3(void){
    uint8 counter = 0;
    for(counter = 0; counter < 3; counter ++){
        led_turn_on(&led1);
        __delay_ms(500);
        led_turn_off(&led1);
        __delay_ms(500);
    }
}

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
                if(3 == Program_Selected){
                    Program_Selected = 0;
                }
                
                Program_Selected++;
                
                switch(Program_Selected){
                    case 1 : program_1(); break;
                    case 2 : program_2(); break;
                    case 3 : program_3(); break;
                    default : break; /* Nothing */
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


