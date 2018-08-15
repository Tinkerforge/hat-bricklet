/* hat-bricklet
 * Copyright (C) 2018 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config_voltage.h: Config for ADC measurements
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

#ifndef CONFIG_VOLTAGE_H
#define CONFIG_VOLTAGE_H

#include "xmc_vadc.h"
#include "xmc_gpio.h"

#define VOLTAGE_USB_ADC_PIN          P2_8
#define VOLTAGE_USB_ADC_CHANNEL      0
#define VOLTAGE_USB_ADC_RESULT_REG   7
#define VOLTAGE_USB_ADC_ALIAS        1

#define VOLTAGE_DC_ADC_PIN           P2_9
#define VOLTAGE_DC_ADC_CHANNEL       1
#define VOLTAGE_DC_ADC_RESULT_REG    9
#define VOLTAGE_DC_ADC_ALIAS         2

#define VOLTAGE_USB_ADC_IRQ          15
#define VOLTAGE_DC_ADC_IRQ           16

#define VOLTAGE_ADC_IRQ_PRIORITY     3

#endif