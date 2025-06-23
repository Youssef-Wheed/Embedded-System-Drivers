/* 
 * File:   ecu_button.h
 * Author: MC
 *
 * Created on February 1, 2025, 11:31 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H
 
/* Section : Includes */
#include"ecu_button_cfg.h"
#include"../Button/../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef enum {
    BUTTON_PRESSED,
    BUTTON_RELEASED
} button_state_t;

typedef enum {
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
} button_active_t;

typedef struct {
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/* Section: Function Declarations */

/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_read_state(const button_t *btn,button_state_t *btn_state);
#endif	/* ECU_BUTTON_H */

