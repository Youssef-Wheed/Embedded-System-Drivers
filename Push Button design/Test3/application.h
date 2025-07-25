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
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
extern keypad_t keypad1;
extern led_t led1;
extern chr_lcd_8bit_t lcd_2;
extern chr_lcd_4bit_t lcd_1;

/* Section: Function Declarations */
void application_intialize(void);

#endif	/* APPLICATION_H */

