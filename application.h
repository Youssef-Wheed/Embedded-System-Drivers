/* 
 * File:   application.h
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 9:53 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/Button/ecu_button.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/DC_Motor/ecu_dc_motor.h"
#include "ECU_Layer/7_Segment/ecu_seven_seg.h"
#include "ECU_Layer/KeyPad/ecu_keypad.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */
void application_intialize(void);

#define _XTAL_FREQ 8000000UL

#endif	/* APPLICATION_H */

