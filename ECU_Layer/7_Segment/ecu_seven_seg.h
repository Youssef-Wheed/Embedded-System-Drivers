/* 
 * File:   ecu_seven_seg.h
 * Author: MC
 *
 * Created on August 21, 2025, 2:59 PM
 */

#ifndef ECU_SEVEN_SEG_H
#define	ECU_SEVEN_SEG_H

#include "ecu_seven_seg_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macro Declarations */
#define SEGMENT_PIN0 0 
#define SEGMENT_PIN1 1 
#define SEGMENT_PIN2 2 
#define SEGMENT_PIN3 3 


/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE        
}segment_type_t;

typedef struct {
    pin_config_t segment_pin[4];
    segment_type_t segment_type;
}segment_t;

/* Section: Function Declarations */
Std_ReturnType seven_segment_intialize (const segment_t *seg);
Std_ReturnType seven_segment_write_number (const segment_t *seg, uint8 number);

#endif	/* ECU_SEVEN_SEG_H */

