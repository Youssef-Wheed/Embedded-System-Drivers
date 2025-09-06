/* 
 * File:   ecu_layer_init.h
 * Author: MC
 *
 * Created on September 6, 2025, 8:32 AM
 */

#include "ecu_layer_init.h"
keypad_t keypad1 = {
    // row pins
    .keypad_row_pins [0].port = PORTC_INDEX,
    .keypad_row_pins [0].pin = GPIO_PIN0,
    .keypad_row_pins [0].logic = GPIO_LOW,
    .keypad_row_pins [0].direction = GPIO_DIRECTION_OUTPUT,
    

    .keypad_row_pins [1].port = PORTC_INDEX,
    .keypad_row_pins [1].pin = GPIO_PIN1,
    .keypad_row_pins [1].logic = GPIO_LOW,
    .keypad_row_pins [1].direction = GPIO_DIRECTION_OUTPUT,
    

    .keypad_row_pins [2].port = PORTC_INDEX,
    .keypad_row_pins [2].pin = GPIO_PIN2,
    .keypad_row_pins [2].logic = GPIO_LOW,
    .keypad_row_pins [2].direction = GPIO_DIRECTION_OUTPUT,
    

    .keypad_row_pins [3].port = PORTC_INDEX,
    .keypad_row_pins [3].pin = GPIO_PIN3,
    .keypad_row_pins [3].logic = GPIO_LOW,
    .keypad_row_pins [3].direction = GPIO_DIRECTION_OUTPUT,
    

    // columns pins
    .keypad_columns_pins [0].port = PORTC_INDEX,
    .keypad_columns_pins [0].pin = GPIO_PIN4,
    .keypad_columns_pins [0].logic = GPIO_LOW,
    .keypad_columns_pins [0].direction = GPIO_DIRECTION_INPUT,
    

    .keypad_columns_pins [1].port = PORTC_INDEX,
    .keypad_columns_pins [1].pin = GPIO_PIN5,
    .keypad_columns_pins [1].logic = GPIO_LOW,
    .keypad_columns_pins [1].direction = GPIO_DIRECTION_INPUT,
    

    .keypad_columns_pins [2].port = PORTC_INDEX,
    .keypad_columns_pins [2].pin = GPIO_PIN6,
    .keypad_columns_pins [2].logic = GPIO_LOW,
    .keypad_columns_pins [2].direction = GPIO_DIRECTION_INPUT,
    

    .keypad_columns_pins [3].port = PORTC_INDEX,
    .keypad_columns_pins [3].pin = GPIO_PIN7,
    .keypad_columns_pins [3].logic = GPIO_LOW,
    .keypad_columns_pins [3].direction = GPIO_DIRECTION_INPUT,
    
};

void ecu_layer_intialize(void) {
    Std_ReturnType ret = E_NOT_OK;
    ret = keypad_initialize(&keypad1);
}

