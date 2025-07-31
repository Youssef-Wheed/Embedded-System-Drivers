/* 
 * File:   ecu_dc_motor.c
 * Author: Youssef Wheed Gendy 
 *
 * Created on July 30, 2025, 10:45 PM
 */
#include "ecu_dc_motor.h"

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t* _dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_intialize(&(_dc_motor->dc_motor_pin[0]));
        gpio_pin_intialize(&(_dc_motor->dc_motor_pin[1]));
    }
    return ret;
}

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t* _dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), GPIO_HIGH);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]), GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t* _dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), GPIO_LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[1]), GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param _dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_stop(const dc_motor_t* _dc_motor) {
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), GPIO_LOW);
        gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[0]), GPIO_LOW);
    }
    return ret;
}