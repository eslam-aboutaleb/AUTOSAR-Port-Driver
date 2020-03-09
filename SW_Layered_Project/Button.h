/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *
 * * Author: Eslam Aboutaleb
 ******************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "Std_Types.h"

/* Button State according to its configuration PULL UP/Down */
#define BUTTON_PRESSED  STD_HIGH
#define BUTTON_RELEASED STD_LOW


/* Description: Read the Button state Pressed/NOT Pressed */
uint8 BUTTON_getState(void);

/* 
 * Description: This function is called every 20ms by Scheduler and it responsible for Updating 
 *              the BUTTON State. it should be in a PRESSED State if the button
 *				is pressed for 60ms. and it should be in a RELEASED State if the
 *				button is released for 60ms.
 */   
void BUTTON_refreshState(void);

#endif /* BUTTON_H */
