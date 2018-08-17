/* hat-bricklet
 * Copyright (C) 2018 Olaf Lüke <olaf@tinkerforge.com>
 *
 * max17260.h: Driver for MAX17260 1-cell fuel gauge
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

#ifndef MAX17260_H
#define MAX17260_H

#include "bricklib2/hal/i2c_fifo/i2c_fifo.h"

#include <stdint.h>

typedef struct {
    I2CFifo i2c_fifo;

    uint32_t last_read;

    uint8_t current_read_index;

    int32_t status;

    int32_t capacity_full;
    int32_t capacity_nominal;
    int32_t capacity_remaining;

    int32_t percentage_charge;

    int32_t time_to_emtpy;
    int32_t time_to_full;

    int32_t voltage_battery;

    int32_t current_flow;

    int32_t temperature_battery;

    bool battery_connected;
    bool fully_qualified;
} MAX17260;

extern MAX17260 max17260;


#define MAX17260_REG_DESIGN_CAP   0x18
#define MAX17260_REG_VEMPTY       0x3A
#define MAX17260_REG_MODEL_CFG    0xDB
#define MAX17260_REG_ICH_G_TERM   0x1E
#define MAX17260_REG_CONFIG1      0x1D
#define MAX17260_REG_CONFIG2      0xBB
#define MAX17260_REG_REP_CAP      0x05
#define MAX17260_REG_REP_SOC      0x06
#define MAX17260_REG_FULL_CAP_REP 0x10
#define MAX17260_REG_TTE          0x11
#define MAX17260_REG_TTF          0x20
#define MAX17260_REG_CYCLES       0x17
#define MAX17260_REG_STATUS       0x00
#define MAX17260_REG_V_CELL       0x09
#define MAX17260_REG_AVG_V_CELL   0x19
#define MAX17260_REG_MAX_MIN_VOLT 0x1B
#define MAX17260_REG_CURRENT      0x0A
#define MAX17260_REG_AVG_CURRENT  0x0B
#define MAX17260_REG_MAX_MIN_CURR 0x1C
#define MAX17260_REG_TEMP         0x08
#define MAX17260_REG_AVT_TA       0x16
#define MAX17260_REG_MAX_MIN_TEMP 0x1A
#define MAX17260_REG_DIE_TEMP     0x34
#define MAX17260_REG_POWER        0xB1
#define MAX17260_REG_AVG_POWER    0xBE
#define MAX17260_REG_V_ALRT_TH    0x01
#define MAX17260_REG_T_ALRT_TH    0x02
#define MAX17260_REG_S_ALRT_TH    0x03
#define MAX17260_REG_L_ALRT_TH    0xB4
#define MAX17260_REG_FSTAT        0x3D // TODO:This is only in software implementation guide, not in datasheet. Is it OK?


// Default configuration

#define MAX17260_CONFIG1_TSEL     1
#define MAX17260_CONFIG1_SS       0
#define MAX17260_CONFIG1_TS       0
#define MAX17260_CONFIG1_VS       0
#define MAX17260_CONFIG1_IS       0
#define MAX17260_CONFIG1_THSH     0
#define MAX17260_CONFIG1_TEN      1
#define MAX17260_CONFIG1_TEX      0
#define MAX17260_CONFIG1_SHDN     0
#define MAX17260_CONFIG1_COMMSH   0
#define MAX17260_CONFIG1_D5       0
#define MAX17260_CONFIG1_ETHRM    1
#define MAX17260_CONFIG1_FTHRM    0
#define MAX17260_CONFIG1_AEN      0
#define MAX17260_CONFIG1_BEI      0
#define MAX17260_CONFIG1_BER      0

#define MAX17260_CONFIG2_D15      0
#define MAX17260_CONFIG2_D14      0
#define MAX17260_CONFIG2_ATRATEEN 1
#define MAX17260_CONFIG2_DPEN     1
#define MAX17260_CONFIG2_PWR      0b0110
#define MAX17260_CONFIG2_DSOCEN   0
#define MAX17260_CONFIG2_TAIRTEN  0
#define MAX17260_CONFIG2_LDMDI    0
#define MAX17260_CONFIG2_D4       1
#define MAX17260_CONFIG2_DRCFG    0b10
#define MAX17260_CONFIG2_CPMODE   0
#define MAX17260_CONFIG2_D0       0

#define MAX17260_MODEL_REFRESH    0
#define MAX17260_MODEL_D14        0
#define MAX17260_MODEL_R100       1 // TODO: ???
#define MAX17260_MODEL_D12        0
#define MAX17260_MODEL_D11        0
#define MAX17260_MODEL_VCHG       0
#define MAX17260_MODEL_D9         0
#define MAX17260_MODEL_D8         0
#define MAX17260_MODEL_MODELLID   0b0000
#define MAX17260_MODEL_D3         0
#define MAX17260_MODEL_CSEL       0
#define MAX17260_MODEL_D1         0
#define MAX17260_MODEL_D0         0

#define MAX17260_STATUS_POR       0x0002

#define MAX17260_FSTAT_DNR        0x0001
#define MAX17260_FSTAT_FQ         0x0080

#define MAX17260_DESIGN_CAP       0x1F40 // 0x0BB8 // TODO: ?
#define MAX17260_VEMPTY           0xA561 // TODO: ?
#define MAX17260_ICH_G_TERM       0x0640 // TODO: ?

void max17260_init(void);
void max17260_tick(void);

#endif