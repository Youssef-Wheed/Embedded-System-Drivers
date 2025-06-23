/* 
 * File:   ecu_ relay.c
 * Author: Youssef Wheed 
 *
 * Created on February 10, 2025, 8:16 PM
 */

#include "ecu_relay.h"

Std_ReturnType relay_initialize(const relay_t *_relay) {
    Std_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {.port = _relay->relay_port, .pin = _relay->relay_pin,
            .direction = GPIO_DIRECTION_OUTPUT, .logic = _relay->relay_status};
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}

Std_ReturnType relay_trun_on(const relay_t *_relay) {
    Std_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {.port = _relay->relay_port, .pin = _relay->relay_pin,
            .direction = GPIO_DIRECTION_OUTPUT, .logic = _relay->relay_status};
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;
}

Std_ReturnType relay_trun_off(const relay_t *_relay) {
    Std_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOT_OK;
    } else {
        pin_config_t pin_obj = {.port = _relay->relay_port, .pin = _relay->relay_pin,
            .direction = GPIO_DIRECTION_OUTPUT, .logic = _relay->relay_status};
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;
}
