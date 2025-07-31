/* 
 * File:   ecu_ relay.h
 * Author: Youssef Wheed
 *
 * Created on February 10, 2025, 8:16 PM
 */

#ifndef ECU__RELAY_H
#define	ECU__RELAY_H

/* Section : Includes */
#include"ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macro Declarations */
#define RELAY_ON_STATUS  0x01U
#define RELAY_OFF_STATUS  0x00U

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef struct {
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
} relay_t;

/* Section: Function Declarations */
Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_trun_on(const relay_t *_relay);
Std_ReturnType relay_trun_off(const relay_t *_relay);

#endif	/* ECU__RELAY_H */

