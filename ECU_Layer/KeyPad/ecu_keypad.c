/* 
 * File:   ecu_keypad.c
 * Author: MC
 *
 * Created on September 4, 2025, 6:49 PM
 */

#include "ecu_keypad.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                "ecu_keypad.h"

static const uint8 btn_values [ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMNS] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'},
};

/**
 * 
 * @param _keypad_obj
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj) {
    Std_ReturnType ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;

    if (NULL == _keypad_obj) {
        ret = E_NOT_OK;
    } else {
        for (rows_counter = ZERO_INIT; rows_counter < ECU_KEYPAD_ROW; rows_counter++) {
            ret = gpio_pin_intialize(&(_keypad_obj->keypad_row_pins[rows_counter]));
        }

        for (columns_counter = ZERO_INIT; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++) {
            ret = gpio_pin_direction_intialize(&(_keypad_obj->keypad_columns_pins[rows_counter]));
        }
    }
    return ret;
}

/**
 * 
 * @param _keypad_obj
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value) {
    Std_ReturnType ret = E_OK;
    if ((NULL == _keypad_obj) || (NULL == value)) {
        ret = E_NOT_OK;
    } else {

    }
    return ret;
}