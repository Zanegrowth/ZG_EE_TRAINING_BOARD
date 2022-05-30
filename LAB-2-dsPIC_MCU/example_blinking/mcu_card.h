/****************************************************************************
**
** Copyright (C) 2022 MikroElektronika d.o.o.
** Contact: https://www.mikroe.com/contact
**
** This file is part of the mikroSDK package
**
** Commercial License Usage
**
** Licensees holding valid commercial NECTO compilers AI licenses may use this
** file in accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The MikroElektronika Company.
** For licensing terms and conditions see
** https://www.mikroe.com/legal/software-license-agreement.
** For further information use the contact form at
** https://www.mikroe.com/contact.
**
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used for
** non-commercial projects under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** OF MERCHANTABILITY, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
** TO THE WARRANTIES FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
** DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
** OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
** OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/
/*!
 * @file  mcu_card.h
 * @brief MCU card connections mapping.
 */

#ifndef _MCU_CARD_H_
#define _MCU_CARD_H_

#ifdef __cplusplus
extern "C"{
#endif

// #include "hal_target.h"

// Hardware revision number
#define MCU_CARD_REV_MAJOR (0)
#define MCU_CARD_REV_MINOR (81)

#define NC HAL_PIN_NC 

    
// Left connector
#define LEFT_CN_PIN_001 RA0
#define LEFT_CN_PIN_002 RA1
#define LEFT_CN_PIN_003 RA2
#define LEFT_CN_PIN_004 RA3
#define LEFT_CN_PIN_005 RA4
#define LEFT_CN_PIN_006 RA5
#define LEFT_CN_PIN_007 RA6
#define LEFT_CN_PIN_008 RA7
#define LEFT_CN_PIN_009 NC
#define LEFT_CN_PIN_010 NC
#define LEFT_CN_PIN_011 NC
#define LEFT_CN_PIN_012 NC
#define LEFT_CN_PIN_013 RA9
#define LEFT_CN_PIN_014 NC
#define LEFT_CN_PIN_015 NC
#define LEFT_CN_PIN_016 NC
#define LEFT_CN_PIN_017 NC
#define LEFT_CN_PIN_018 RA14
#define LEFT_CN_PIN_019 RA15
#define LEFT_CN_PIN_020 NC
#define LEFT_CN_PIN_021 RJ13
#define LEFT_CN_PIN_022 RJ14
#define LEFT_CN_PIN_023 RJ15
#define LEFT_CN_PIN_024 RJ6
#define LEFT_CN_PIN_025 RB10
#define LEFT_CN_PIN_026 RK11
#define LEFT_CN_PIN_027 RB9
#define LEFT_CN_PIN_028 RK15
#define LEFT_CN_PIN_029 RK14
#define LEFT_CN_PIN_030 RH0
#define LEFT_CN_PIN_031 RH1
#define LEFT_CN_PIN_032 RH2
#define LEFT_CN_PIN_033 RH3
#define LEFT_CN_PIN_034 RH4
#define LEFT_CN_PIN_035 RH5
#define LEFT_CN_PIN_036 RH6
#define LEFT_CN_PIN_037 RH7
#define LEFT_CN_PIN_038 NC
#define LEFT_CN_PIN_039 NC
#define LEFT_CN_PIN_040 NC
#define LEFT_CN_PIN_041 NC
#define LEFT_CN_PIN_042 NC
#define LEFT_CN_PIN_043 NC
#define LEFT_CN_PIN_044 NC
#define LEFT_CN_PIN_045 NC
#define LEFT_CN_PIN_046 NC
#define LEFT_CN_PIN_047 NC
#define LEFT_CN_PIN_048 NC
#define LEFT_CN_PIN_049 NC
#define LEFT_CN_PIN_050 NC
#define LEFT_CN_PIN_051 NC
#define LEFT_CN_PIN_052 NC
#define LEFT_CN_PIN_053 NC
#define LEFT_CN_PIN_054 RD15
#define LEFT_CN_PIN_055 RD14
#define LEFT_CN_PIN_056 RF12
#define LEFT_CN_PIN_057 RF4
#define LEFT_CN_PIN_058 RA2
#define LEFT_CN_PIN_059 RA3
#define LEFT_CN_PIN_060 RB8
#define LEFT_CN_PIN_061 RB4
#define LEFT_CN_PIN_062 RB3
#define LEFT_CN_PIN_063 RB2
#define LEFT_CN_PIN_064 RB1
#define LEFT_CN_PIN_065 RB0
#define LEFT_CN_PIN_066 NC
#define LEFT_CN_PIN_067 NC
#define LEFT_CN_PIN_068 NC
#define LEFT_CN_PIN_069 RB0
#define LEFT_CN_PIN_070 RB1
#define LEFT_CN_PIN_071 RB2
#define LEFT_CN_PIN_072 RB3
#define LEFT_CN_PIN_073 RB4
#define LEFT_CN_PIN_074 RB5
#define LEFT_CN_PIN_075 RB6
#define LEFT_CN_PIN_076 RB7
#define LEFT_CN_PIN_077 RB8
#define LEFT_CN_PIN_078 RB9
#define LEFT_CN_PIN_079 RB10
#define LEFT_CN_PIN_080 RB11
#define LEFT_CN_PIN_081 RB12
#define LEFT_CN_PIN_082 RB13
#define LEFT_CN_PIN_083 RB14
#define LEFT_CN_PIN_084 RB15
#define LEFT_CN_PIN_085 RD9
#define LEFT_CN_PIN_086 RD10
#define LEFT_CN_PIN_087 RG13
#define LEFT_CN_PIN_088 RG12
#define LEFT_CN_PIN_089 RD11
#define LEFT_CN_PIN_090 RD7
#define LEFT_CN_PIN_091 RG8
#define LEFT_CN_PIN_092 RG7
#define LEFT_CN_PIN_093 RG6
#define LEFT_CN_PIN_094 RH15
#define LEFT_CN_PIN_095 RH14
#define LEFT_CN_PIN_096 RB15
#define LEFT_CN_PIN_097 RD9
#define LEFT_CN_PIN_098 RD10
#define LEFT_CN_PIN_099 RF8
#define LEFT_CN_PIN_100 RD12
#define LEFT_CN_PIN_101 RG1
#define LEFT_CN_PIN_102 RD1
#define LEFT_CN_PIN_103 RG8
#define LEFT_CN_PIN_104 RG7
#define LEFT_CN_PIN_105 RG6
#define LEFT_CN_PIN_106 RH11
#define LEFT_CN_PIN_107 RH10
#define LEFT_CN_PIN_108 RB14
#define LEFT_CN_PIN_109 RD9
#define LEFT_CN_PIN_110 RD10
#define LEFT_CN_PIN_111 RF2
#define LEFT_CN_PIN_112 RE2
#define LEFT_CN_PIN_113 RG9
#define LEFT_CN_PIN_114 RG0
#define LEFT_CN_PIN_115 RG8
#define LEFT_CN_PIN_116 RG7
#define LEFT_CN_PIN_117 RG6
#define LEFT_CN_PIN_118 RH9
#define LEFT_CN_PIN_119 RH8
#define LEFT_CN_PIN_120 RB13
#define LEFT_CN_PIN_121 RA3
#define LEFT_CN_PIN_122 RA2
#define LEFT_CN_PIN_123 RF13
#define LEFT_CN_PIN_124 RE4
#define LEFT_CN_PIN_125 RE3
#define LEFT_CN_PIN_126 RG14
#define LEFT_CN_PIN_127 RG8
#define LEFT_CN_PIN_128 RG7
#define LEFT_CN_PIN_129 RG6
#define LEFT_CN_PIN_130 RK1
#define LEFT_CN_PIN_131 RK0
#define LEFT_CN_PIN_132 RA7
#define LEFT_CN_PIN_133 RA3
#define LEFT_CN_PIN_134 RA2
#define LEFT_CN_PIN_135 RF1
#define LEFT_CN_PIN_136 RA15
#define LEFT_CN_PIN_137 RA14
#define LEFT_CN_PIN_138 RF0
#define LEFT_CN_PIN_139 RG8
#define LEFT_CN_PIN_140 RG7
#define LEFT_CN_PIN_141 RG6
#define LEFT_CN_PIN_142 RJ4
#define LEFT_CN_PIN_143 RJ5
#define LEFT_CN_PIN_144 RA6
#define LEFT_CN_PIN_145 RJ7
#define LEFT_CN_PIN_146 RC4
#define LEFT_CN_PIN_147 RC3
#define LEFT_CN_PIN_148 RC2
#define LEFT_CN_PIN_149 RC1
#define LEFT_CN_PIN_150 RJ12
#define LEFT_CN_PIN_151 RJ11
#define LEFT_CN_PIN_152 RJ10
#define LEFT_CN_PIN_153 RJ9
#define LEFT_CN_PIN_154 RJ8
#define LEFT_CN_PIN_155 NC
#define LEFT_CN_PIN_156 NC
#define LEFT_CN_PIN_157 NC
#define LEFT_CN_PIN_158 NC
#define LEFT_CN_PIN_159 NC
#define LEFT_CN_PIN_160 NC
#define LEFT_CN_PIN_161 NC
#define LEFT_CN_PIN_162 NC
#define LEFT_CN_PIN_163 NC
#define LEFT_CN_PIN_164 NC
#define LEFT_CN_PIN_165 NC
#define LEFT_CN_PIN_166 NC
#define LEFT_CN_PIN_167 NC
#define LEFT_CN_PIN_168 NC

// Right connector
#define RIGHT_CN_PIN_001 NC
#define RIGHT_CN_PIN_002 RC1
#define RIGHT_CN_PIN_003 RC2
#define RIGHT_CN_PIN_004 RC3
#define RIGHT_CN_PIN_005 RC4
#define RIGHT_CN_PIN_006 NC
#define RIGHT_CN_PIN_007 NC
#define RIGHT_CN_PIN_008 NC
#define RIGHT_CN_PIN_009 NC
#define RIGHT_CN_PIN_010 NC
#define RIGHT_CN_PIN_011 NC
#define RIGHT_CN_PIN_012 RD0
#define RIGHT_CN_PIN_013 RD1
#define RIGHT_CN_PIN_014 RD2
#define RIGHT_CN_PIN_015 RD3
#define RIGHT_CN_PIN_016 RD4
#define RIGHT_CN_PIN_017 RD5
#define RIGHT_CN_PIN_018 RD6
#define RIGHT_CN_PIN_019 RD7
#define RIGHT_CN_PIN_020 RE0
#define RIGHT_CN_PIN_021 RE1
#define RIGHT_CN_PIN_022 RE2
#define RIGHT_CN_PIN_023 RE3
#define RIGHT_CN_PIN_024 RE4
#define RIGHT_CN_PIN_025 RE5
#define RIGHT_CN_PIN_026 RE6
#define RIGHT_CN_PIN_027 RE7
#define RIGHT_CN_PIN_028 RF0
#define RIGHT_CN_PIN_029 RF1
#define RIGHT_CN_PIN_030 RF2
#define RIGHT_CN_PIN_031 RF3
#define RIGHT_CN_PIN_032 RF4
#define RIGHT_CN_PIN_033 RF5
#define RIGHT_CN_PIN_034 NC
#define RIGHT_CN_PIN_035 NC
#define RIGHT_CN_PIN_036 NC
#define RIGHT_CN_PIN_037 NC
#define RIGHT_CN_PIN_038 NC
#define RIGHT_CN_PIN_039 NC
#define RIGHT_CN_PIN_040 NC
#define RIGHT_CN_PIN_041 NC
#define RIGHT_CN_PIN_042 NC
#define RIGHT_CN_PIN_043 RE6
#define RIGHT_CN_PIN_044 RE5
#define RIGHT_CN_PIN_045 RG0
#define RIGHT_CN_PIN_046 RG1
#define RIGHT_CN_PIN_047 NC
#define RIGHT_CN_PIN_048 NC
#define RIGHT_CN_PIN_049 NC
#define RIGHT_CN_PIN_050 NC
#define RIGHT_CN_PIN_051 RG6
#define RIGHT_CN_PIN_052 RG7
#define RIGHT_CN_PIN_053 RH0
#define RIGHT_CN_PIN_054 RH1
#define RIGHT_CN_PIN_055 RH2
#define RIGHT_CN_PIN_056 RH3
#define RIGHT_CN_PIN_057 RH4
#define RIGHT_CN_PIN_058 RH5
#define RIGHT_CN_PIN_059 RH6
#define RIGHT_CN_PIN_060 RH7
#define RIGHT_CN_PIN_061 RK1
#define RIGHT_CN_PIN_062 RK0
#define RIGHT_CN_PIN_063 RK13
#define RIGHT_CN_PIN_064 RK12
#define RIGHT_CN_PIN_065 NC
#define RIGHT_CN_PIN_066 NC
#define RIGHT_CN_PIN_067 NC
#define RIGHT_CN_PIN_068 NC
#define RIGHT_CN_PIN_069 RK0
#define RIGHT_CN_PIN_070 RK1
#define RIGHT_CN_PIN_071 NC
#define RIGHT_CN_PIN_072 NC
#define RIGHT_CN_PIN_073 NC
#define RIGHT_CN_PIN_074 NC
#define RIGHT_CN_PIN_075 NC
#define RIGHT_CN_PIN_076 NC
#define RIGHT_CN_PIN_077 RJ0
#define RIGHT_CN_PIN_078 RJ1
#define RIGHT_CN_PIN_079 RJ2
#define RIGHT_CN_PIN_080 RJ3
#define RIGHT_CN_PIN_081 RJ4
#define RIGHT_CN_PIN_082 RJ5
#define RIGHT_CN_PIN_083 RJ6
#define RIGHT_CN_PIN_084 RJ7
#define RIGHT_CN_PIN_085 RJ15
#define RIGHT_CN_PIN_086 RJ14
#define RIGHT_CN_PIN_087 RJ13
#define RIGHT_CN_PIN_088 RJ12
#define RIGHT_CN_PIN_089 RJ11
#define RIGHT_CN_PIN_090 RJ10
#define RIGHT_CN_PIN_091 RJ9
#define RIGHT_CN_PIN_092 RJ8
#define RIGHT_CN_PIN_093 RK15
#define RIGHT_CN_PIN_094 RK14
#define RIGHT_CN_PIN_095 RK13
#define RIGHT_CN_PIN_096 RK12
#define RIGHT_CN_PIN_097 RK11
#define RIGHT_CN_PIN_098 NC
#define RIGHT_CN_PIN_099 NC
#define RIGHT_CN_PIN_100 NC
#define RIGHT_CN_PIN_101 RJ0
#define RIGHT_CN_PIN_102 RJ1
#define RIGHT_CN_PIN_103 RJ2
#define RIGHT_CN_PIN_104 RE1
#define RIGHT_CN_PIN_105 RJ4
#define RIGHT_CN_PIN_106 RG15
#define RIGHT_CN_PIN_107 RH12
#define RIGHT_CN_PIN_108 RH13
#define RIGHT_CN_PIN_109 RH15
#define RIGHT_CN_PIN_110 RH14
#define RIGHT_CN_PIN_111 RH13
#define RIGHT_CN_PIN_112 RH12
#define RIGHT_CN_PIN_113 RH11
#define RIGHT_CN_PIN_114 RH10
#define RIGHT_CN_PIN_115 RH9
#define RIGHT_CN_PIN_116 RH8
#define RIGHT_CN_PIN_117 RG15
#define RIGHT_CN_PIN_118 RG14
#define RIGHT_CN_PIN_119 RG13
#define RIGHT_CN_PIN_120 RG12
#define RIGHT_CN_PIN_121 NC
#define RIGHT_CN_PIN_122 NC
#define RIGHT_CN_PIN_123 RG9
#define RIGHT_CN_PIN_124 RG8
#define RIGHT_CN_PIN_125 RC4
#define RIGHT_CN_PIN_126 RE7
#define RIGHT_CN_PIN_127 RE8
#define RIGHT_CN_PIN_128 RE9
#define RIGHT_CN_PIN_129 RB5
#define RIGHT_CN_PIN_130 RF3
#define RIGHT_CN_PIN_131 NC
#define RIGHT_CN_PIN_132 NC
#define RIGHT_CN_PIN_133 NC
#define RIGHT_CN_PIN_134 NC
#define RIGHT_CN_PIN_135 NC
#define RIGHT_CN_PIN_136 RF13
#define RIGHT_CN_PIN_137 RF12
#define RIGHT_CN_PIN_138 NC
#define RIGHT_CN_PIN_139 NC
#define RIGHT_CN_PIN_140 NC
#define RIGHT_CN_PIN_141 RF8
#define RIGHT_CN_PIN_142 NC
#define RIGHT_CN_PIN_143 NC
#define RIGHT_CN_PIN_144 NC
#define RIGHT_CN_PIN_145 NC
#define RIGHT_CN_PIN_146 NC
#define RIGHT_CN_PIN_147 NC
#define RIGHT_CN_PIN_148 RE9
#define RIGHT_CN_PIN_149 RE8
#define RIGHT_CN_PIN_150 RD15
#define RIGHT_CN_PIN_151 RD14
#define RIGHT_CN_PIN_152 RD13
#define RIGHT_CN_PIN_153 RD12
#define RIGHT_CN_PIN_154 RD11
#define RIGHT_CN_PIN_155 RD10
#define RIGHT_CN_PIN_156 RD9
#define RIGHT_CN_PIN_157 RD8
#define RIGHT_CN_PIN_158 NC
#define RIGHT_CN_PIN_159 RG12
#define RIGHT_CN_PIN_160 RG13
#define RIGHT_CN_PIN_161 NC
#define RIGHT_CN_PIN_162 NC
#define RIGHT_CN_PIN_163 NC
#define RIGHT_CN_PIN_164 NC
#define RIGHT_CN_PIN_165 NC
#define RIGHT_CN_PIN_166 NC
#define RIGHT_CN_PIN_167 NC
#define RIGHT_CN_PIN_168 NC

#define LCD_TFT_8BIT_CH0 PORT_G
#define LCD_TFT_CH0_8BIT_MASK 0x00FF

#define LCD_TFT_16BIT_CH0 PORT_G
#define LCD_TFT_16BIT_CH0_MASK 0xFFFF

#define LCD_TFT_16BIT_CH1 HAL_PORT_NC
#define LCD_TFT_16BIT_CH1_MASK 0x0000

// Ethernet
#define ETH_RXD0   NC
#define ETH_RXD1   NC
#define ETH_TXD0   NC
#define ETH_TXD1   NC
#define ETH_TXEN   NC
#define ETH_CRS_DV NC
#define ETH_RXER   NC
#define ETH_MDIO   NC
#define ETH_MDC    NC
#define ETH_NINT   NC
#define ETH_CLK    NC
#define ETH_RST    NC


#ifdef __cplusplus
}
#endif

#endif // _MCU_CARD_H_
// ------------------------------------------------------------------------- END
