/*
 * KEYPAD.h
 *
 *  Created on: Feb 13, 2024
 *      Author: Admin
 */
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STANDS.h"
#include <util/delay.h>
#include "MACROS.h"
#include "GPIO2.h"

#define ROW_INIT_PIN 4
#define COL_INIT_PIN 2

#define ROW_NUM 4
#define COL_NUM 4

uint8 KEYPAD();
uint8 K_P_4X4(uint8 num);

#endif
