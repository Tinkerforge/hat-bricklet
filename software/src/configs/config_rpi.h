/* hat-bricklet
 * Copyright (C) 2018 Olaf Lüke <olaf@tinkerforge.com>
 *
 * rpi.h: Config for Raspberry PI
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef CONFIG_RPI_H
#define CONFIG_RPI_H

#include "xmc_gpio.h"

#define RPI_BOOST_EN_PIN         P1_6 // MIC2253, powers bricklet and rpi
#define RPI_BRICKLET_EN_PIN      P4_7
#define RPI_RPI_EN_PIN           P4_6

#define RPI_LED_LOW_PIN          P0_12
#define RPI_LED_MID_PIN          P4_5
#define RPI_LED_HIGH_PIN         P2_1

#endif