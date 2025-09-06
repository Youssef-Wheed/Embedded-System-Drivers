/* 
 * File:   application.h
 * Author: Ahmed.Elghafar
 * https://www.linkedin.com/in/ahmedabdelghafarmohammed/
 * Created on November 28, 2020, 9:53 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/ecu_layer_init.h"
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
extern keypad_t keypad1;
/* Section: Function Declarations */
void application_intialize(void);

#define _XTAL_FREQ 8000000UL

#endif	/* APPLICATION_H */

