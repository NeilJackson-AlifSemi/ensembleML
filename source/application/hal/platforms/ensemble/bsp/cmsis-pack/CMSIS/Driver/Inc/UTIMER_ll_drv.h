/* Copyright (c) 2021 ALIF SEMICONDUCTOR

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ALIF SEMICONDUCTOR nor the names of its contributors
     may be used to endorse or promote products derived from this software
     without specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

/**************************************************************************//**
 * @file     UTIMER_ll_drv.c
 * @author   Girish BN
 * @email    girish.bn@alifsemi.com
 * @version  V1.0.0
 * @date     21-Aug-2020
 * @brief    CMSIS-Driver for UTIMER.
 * @bug      None.
 * @Note     None
 ******************************************************************************/

#ifndef __UTIMER_LL_DRIVER_H__
#define __UTIMER_LL_DRIVER_H__

#include "Driver_UTIMER.h"
#include "RTE_Device.h"
#include "RTE_Components.h"
#include CMSIS_device_header

/*****************  Bit definition for TIMER_RegInfo:cntr_ctrl register  ******************/
#define CNTR_CTRL_EN                                ((uint32_t)0x00000001)
#define CNTR_CTRL_START                             ((uint32_t)0x00000002)
#define CNTR_CTRL_TYPE0                             ((uint32_t)0x00000004)
#define CNTR_CTRL_TYPE1                             ((uint32_t)0x00000008)
#define CNTR_CTRL_TYPE2                             ((uint32_t)0x00000010)
#define CNTR_CTRL_TYPE                              ((uint32_t)(CNTR_CTRL_TYPE0|CNTR_CTRL_TYPE1|CNTR_CTRL_TYPE2))
#define CNTR_CTRL_DIR                               ((uint32_t)0x00000100)

/*****************  Bit definition for TIMER_RegInfo:cntr_start_src register  ******************/
#define CNTR_SRC_TRIG0_RISING                       ((uint32_t)0x00000001)
#define CNTR_SRC_TRIG0_FALLING                      ((uint32_t)0x00000002)
#define CNTR_SRC_TRIG1_RISING                       ((uint32_t)0x00000004)
#define CNTR_SRC_TRIG1_FALLING                      ((uint32_t)0x00000008)
#define CNTR_SRC_TRIG2_RISING                       ((uint32_t)0x00000010)
#define CNTR_SRC_TRIG2_FALLING                      ((uint32_t)0x00000020)
#define CNTR_SRC_TRIG3_RISING                       ((uint32_t)0x00000040)
#define CNTR_SRC_TRIG3_FALLING                      ((uint32_t)0x00000080)
#define CNTR_SRC_DRIVE_A_RISING_B_0                 ((uint32_t)0x00000100)
#define CNTR_SRC_DRIVE_A_RISING_B_1                 ((uint32_t)0x00000200)
#define CNTR_SRC_DRIVE_A_FALLING_B_0                ((uint32_t)0x00000400)
#define CNTR_SRC_DRIVE_A_FALLING_B_1                ((uint32_t)0x00000800)
#define CNTR_SRC_DRIVE_B_RISING_A_0                 ((uint32_t)0x00001000)
#define CNTR_SRC_DRIVE_B_RISING_A_1                 ((uint32_t)0x00002000)
#define CNTR_SRC_DRIVE_B_FALLING_A_0                ((uint32_t)0x00004000)
#define CNTR_SRC_DRIVE_B_FALLING_A_1                ((uint32_t)0x00008000)
#define CNTR_SRC_ELC0_EVENT                         ((uint32_t)0x00010000)
#define CNTR_SRC_ELC1_EVENT                         ((uint32_t)0x00020000)
#define CNTR_SRC_ELC2_EVENT                         ((uint32_t)0x00040000)
#define CNTR_SRC_ELC3_EVENT                         ((uint32_t)0x00080000)
#define CNTR_SRC_ELC4_EVENT                         ((uint32_t)0x00100000)
#define CNTR_SRC_ELC5_EVENT                         ((uint32_t)0x00200000)
#define CNTR_SRC_ELC6_EVENT                         ((uint32_t)0x00400000)
#define CNTR_SRC_ELC7_EVENT                         ((uint32_t)0x00800000)
#define CNTR_SRC_PGM_EN                             ((uint32_t)0x80000000)

/*****************  Bit definition for TIMER_RegInfo:buf_compare_ctrl register  ******************/
#define COMPARE_CTRL_DRV_MATCH_0                    (uint32_t) (0x00000001)
#define COMPARE_CTRL_DRV_MATCH_1                    (uint32_t) (0x00000002)
#define COMPARE_CTRL_DRV_MATCH                      (uint32_t) (COMPARE_CTRL_DRV_MATCH_1|COMPARE_CTRL_DRV_MATCH_0)
#define COMPARE_CTRL_DRV_CYCLE_END_0                (uint32_t) (0x00000004)
#define COMPARE_CTRL_DRV_CYCLE_END_1                (uint32_t) (0x00000008)
#define COMPARE_CTRL_DRV_CYCLE_END                  (uint32_t) (COMPARE_CTRL_DRV_CYCLE_END_1|COMPARE_CTRL_DRV_CYCLE_END_0)
#define COMPARE_CTRL_DRV_START_VAL                  (uint32_t) (0x00000010)
#define COMPARE_CTRL_DRV_STOP_VAL                   (uint32_t) (0x00000040)
#define COMPARE_CTRL_DRV_START_STOP_LEVEL           (uint32_t) (0x00000080)
#define COMPARE_CTRL_DRV_DRIVER_EN                  (uint32_t) (0x00000100)
#define COMPARE_CTRL_DRV_DISABLE_VAL                (uint32_t) (0x00000200)
#define COMPARE_CTRL_DRV_COMPARE_EN                 (uint32_t) (0x00000800)
#define COMPARE_CTRL_DRV_COMPARE_TRIG_EN            (uint32_t) (0x00001000)
#define COMPARE_CTRL_DRV_DMA_CLEAR_EN               (uint32_t) (0x00002000)

/*****************  Bit definition for TIMER_RegInfo:buf_op_ctrl register  ******************/
#define BUF_OP_CTRL_CAPTURE_BUF_DISABLE             ((uint32_t)0x00000001)
#define BUF_OP_CTRL_CNTR_BUF_DISABLE                ((uint32_t)0x00000002)
#define BUF_OP_CTRL_COMPARE_BUF_DISABLE             ((uint32_t)0x00000004)
#define BUF_OP_CTRL_DUTY_CYCLE_OP_DISABLE           ((uint32_t)0x00000008)
#define BUF_OP_CTRL_CAPTURE_A_BUF_OP_BIT0           ((uint32_t)0x00010000)
#define BUF_OP_CTRL_CAPTURE_A_BUF_OP_BIT1           ((uint32_t)0x00020000)
#define BUF_OP_CTRL_CAPTURE_A_BUF_OP                ((uint32_t)(BUF_OP_CTRL_CAPTURE_A_BUF_OP_BIT0|BUF_OP_CTRL_CAPTURE_A_BUF_OP_BIT1))
#define BUF_OP_CTRL_CAPTURE_B_BUF_OP_BIT0           ((uint32_t)0x00040000)
#define BUF_OP_CTRL_CAPTURE_B_BUF_OP_BIT1           ((uint32_t)0x00080000)
#define BUF_OP_CTRL_CAPTURE_B_BUF_OP                ((uint32_t)(BUF_OP_CTRL_CAPTURE_B_BUF_OP_BIT0|BUF_OP_CTRL_CAPTURE_B_BUF_OP_BIT1))
#define BUF_OP_CTRL_CNTR_BUF_OP_BIT0                ((uint32_t)0x00100000)
#define BUF_OP_CTRL_CNTR_BUF_OP_BIT1                ((uint32_t)0x00200000)
#define BUF_OP_CTRL_CNTR_BUF_OP                     ((uint32_t)(BUF_OP_CTRL_CNTR_BUF_OP_BIT0|BUF_OP_CTRL_CNTR_BUF_OP_BIT1))
#define BUF_OP_CTRL_FORCE_COMPARE_BUF_OP            ((uint32_t)0x00400000)
#define BUF_OP_CTRL_COMPARE_A_BUF_EVENT_BIT0        ((uint32_t)0x01000000)
#define BUF_OP_CTRL_COMPARE_A_BUF_EVENT_BIT1        ((uint32_t)0x02000000)
#define BUF_OP_CTRL_COMPARE_A_BUF_EVENT             ((uint32_t)(BUF_OP_CTRL_COMPARE_A_BUF_EVENT_BIT0|BUF_OP_CTRL_COMPARE_A_BUF_EVENT_BIT1))
#define BUF_OP_CTRL_COMPARE_A_BUF_OP                ((uint32_t)0x04000000)
#define BUF_OP_CTRL_COMPARE_B_BUF_EVENT_BIT0        ((uint32_t)0x10000000)
#define BUF_OP_CTRL_COMPARE_B_BUF_EVENT_BIT1        ((uint32_t)0x20000000)
#define BUF_OP_CTRL_COMPARE_B_BUF_EVENT             ((uint32_t)(BUF_OP_CTRL_COMPARE_B_BUF_EVENT_BIT0|BUF_OP_CTRL_COMPARE_B_BUF_EVENT_BIT1))
#define BUF_OP_CTRL_COMPARE_B_BUF_OP                ((uint32_t)0x40000800)

/*****************  Bit definition for TIMER_RegInfo:chan_interrupt register  ******************/
#define CHAN_INTERRUPT_CAPTURE_A                    ((uint32_t)0x00000001)
#define CHAN_INTERRUPT_CAPTURE_B                    ((uint32_t)0x00000002)
#define CHAN_INTERRUPT_COMPARE_A                    CHAN_INTERRUPT_CAPTURE_A
#define CHAN_INTERRUPT_COMPARE_B                    CHAN_INTERRUPT_CAPTURE_B
#define CHAN_INTERRUPT_COMPARE_C                    ((uint32_t)0x00000004)
#define CHAN_INTERRUPT_COMPARE_D                    ((uint32_t)0x00000008)
#define CHAN_INTERRUPT_COMPARE_E                    ((uint32_t)0x00000010)
#define CHAN_INTERRUPT_COMPARE_F                    ((uint32_t)0x00000020)
#define CHAN_INTERRUPT_UNDER_FLOW                   ((uint32_t)0x00000040)
#define CHAN_INTERRUPT_OVER_FLOW                    ((uint32_t)0x00000080)

/*****************  Bit definition for TIMER_RegInfo:duty_cycle_ctrl register  ******************/
#define DUTY_CYCLE_CTRL_DC_ENABLE_A                 ((uint32_t)0x00000001)
#define DUTY_CYCLE_CTRL_DC_FORCE_A                  ((uint32_t)0x00000002)
#define DUTY_CYCLE_CTRL_DC_SETTING_A                ((uint32_t)0x0000000A)
#define DUTY_CYCLE_CTRL_DC_OVERFLOW_A               ((uint32_t)0x00000010)
#define DUTY_CYCLE_CTRL_DC_UNDERFLOW_A              ((uint32_t)0x00000020)
#define DUTY_CYCLE_CTRL_DC_ENABLE_B                 ((uint32_t)0x00000100)
#define DUTY_CYCLE_CTRL_DC_FORCE_B                  ((uint32_t)0x00000200)
#define DUTY_CYCLE_CTRL_DC_SETTING_B                ((uint32_t)0x00000A00)
#define DUTY_CYCLE_CTRL_DC_OVERFLOW_B               ((uint32_t)0x00001000)
#define DUTY_CYCLE_CTRL_DC_UNDERFLOW_B              ((uint32_t)0x00002000)

/*****************  Bit definition for TIMER_RegInfo:dead_time_ctrl register  ******************/
#define DEAD_TIME_CTRL_DT_EN                        ((uint32_t)0x00000001)
#define DEAD_TIME_CTRL_DT_BUF_EN                    ((uint32_t)0x00000002)

/*****************  Bit definition for TIMER_RegInfo:glb_cntr_start register  ******************/
#define GLB_CNTR_START                              ((uint32_t)0x000007FF)

/*****************  Bit definition for TIMER_RegInfo:glb_cntr_stop register  ******************/
#define GLB_CNTR_STOP                               ((uint32_t)0x000007FF)

/*****************  Bit definition for TIMER_RegInfo:glb_cntr_clear register  ******************/
#define GLB_CNTR_CLEAR                              ((uint32_t)0x000007FF)

/*****************  Bit definition for TIMER_RegInfo:glb_cntr_running register  ******************/
#define GLB_CNTR_RUNNING                            ((uint32_t)0x000007FF)

/*****************  Bit definition for TIMER_RegInfo:glb_driver_oen register  ******************/
#define GLB_DRIVER_CHAN0_A_OEN                      ((uint32_t)0x00000001)
#define GLB_DRIVER_CHAN0_B_OEN                      ((uint32_t)0x00000002)
#define GLB_DRIVER_CHAN1_A_OEN                      ((uint32_t)0x00000004)
#define GLB_DRIVER_CHAN1_B_OEN                      ((uint32_t)0x00000008)
#define GLB_DRIVER_CHAN2_A_OEN                      ((uint32_t)0x00000010)
#define GLB_DRIVER_CHAN2_B_OEN                      ((uint32_t)0x00000020)
#define GLB_DRIVER_CHAN3_A_OEN                      ((uint32_t)0x00000040)
#define GLB_DRIVER_CHAN3_B_OEN                      ((uint32_t)0x00000080)
#define GLB_DRIVER_CHAN4_A_OEN                      ((uint32_t)0x00000100)
#define GLB_DRIVER_CHAN4_B_OEN                      ((uint32_t)0x00000200)
#define GLB_DRIVER_CHAN5_A_OEN                      ((uint32_t)0x00000400)
#define GLB_DRIVER_CHAN5_B_OEN                      ((uint32_t)0x00000800)
#define GLB_DRIVER_CHAN6_A_OEN                      ((uint32_t)0x00001000)
#define GLB_DRIVER_CHAN6_B_OEN                      ((uint32_t)0x00002000)
#define GLB_DRIVER_CHAN7_A_OEN                      ((uint32_t)0x00004000)
#define GLB_DRIVER_CHAN7_B_OEN                      ((uint32_t)0x00008000)
#define GLB_DRIVER_CHAN8_A_OEN                      ((uint32_t)0x00010000)
#define GLB_DRIVER_CHAN8_B_OEN                      ((uint32_t)0x00020000)
#define GLB_DRIVER_CHAN9_A_OEN                      ((uint32_t)0x00040000)
#define GLB_DRIVER_CHAN9_B_OEN                      ((uint32_t)0x00080000)
#define GLB_DRIVER_CHAN10_A_OEN                     ((uint32_t)0x00100000)
#define GLB_DRIVER_CHAN10_B_OEN                     ((uint32_t)0x00200000)
#define GLB_DRIVER_CHAN11_A_OEN                     ((uint32_t)0x00400000)
#define GLB_DRIVER_CHAN12_B_OEN                     ((uint32_t)0x00800000)

#define ARM_UTIMER_TRIG0_RISING                     ((uint32_t)0x00000001)
#define ARM_UTIMER_TRIG0_FALLING                    ((uint32_t)0x00000002)
#define ARM_UTIMER_TRIG1_RISING                     ((uint32_t)0x00000004)
#define ARM_UTIMER_TRIG1_FALLING                    ((uint32_t)0x00000008)
#define ARM_UTIMER_TRIG2_RISING                     ((uint32_t)0x00000010)
#define ARM_UTIMER_TRIG2_FALLING                    ((uint32_t)0x00000020)
#define ARM_UTIMER_TRIG3_RISING                     ((uint32_t)0x00000040)

#define ARM_UTIMER_CHANNEL_RUNNING                  (1)
#define ARM_UTIMER_CHANNEL_STOPED                   (!ARM_UTIMER_CHANNEL_RUNNING)

#define ARM_UTIMER_DIRECTION_DOWN                   (1)
#define ARM_UTIMER_DIRECTION_UP                     (!ARM_UTIMER_DIRECTION_DOWN)

#define ARM_UTIMER_INTRRUPT_UNMASK                  (uint32_t)0x00000000
#define ARM_UTIMER_INTRRUPT_MASK                    (uint32_t)0x000000FF

#define ARM_UTIMER_IRQ_TYPE_CAPTURE_A               (1)  // A - compare_a match
#define ARM_UTIMER_IRQ_TYPE_CAPTURE_B               (2)  // B - compare_b match
#define ARM_UTIMER_IRQ_TYPE_CAPTURE_C               (3)  // C - compare_a_buf1 match
#define ARM_UTIMER_IRQ_TYPE_CAPTURE_D               (4)  // D - compare_a_buf2 match
#define ARM_UTIMER_IRQ_TYPE_CAPTURE_E               (5)  // E - compare_b_buf1 match
#define ARM_UTIMER_IRQ_TYPE_CAPTURE_F               (6)  // F - compare_b_buf2 match
#define ARM_UTIMER_IRQ_TYPE_UNDER_FLOW              (7)  //   - UNDER FLOW
#define ARM_UTIMER_IRQ_TYPE_OVER_FLOW               (8)  //   - OVER FLOW

#define UTIMER_CAPTURE_A_IRQ_BASE                   (UTIMER0_IRQ + 0)
#define UTIMER_CAPTURE_B_IRQ_BASE                   (UTIMER0_IRQ + 1)
#define UTIMER_CAPTURE_C_IRQ_BASE                   (UTIMER0_IRQ + 2)
#define UTIMER_CAPTURE_D_IRQ_BASE                   (UTIMER0_IRQ + 3)
#define UTIMER_CAPTURE_E_IRQ_BASE                   (UTIMER0_IRQ + 4)
#define UTIMER_CAPTURE_F_IRQ_BASE                   (UTIMER0_IRQ + 5)
#define UTIMER_UNDERFLOW_IRQ_BASE                   (UTIMER0_IRQ + 6)
#define UTIMER_OVERFLOW_IRQ_BASE                    (UTIMER0_IRQ + 7)

#define UTIMER_CAPTURE_A_IRQ(channel)               (UTIMER_CAPTURE_A_IRQ_BASE + (channel*8))
#define UTIMER_CAPTURE_B_IRQ(channel)               (UTIMER_CAPTURE_B_IRQ_BASE + (channel*8))
#define UTIMER_CAPTURE_C_IRQ(channel)               (UTIMER_CAPTURE_C_IRQ_BASE + (channel*8))
#define UTIMER_CAPTURE_D_IRQ(channel)               (UTIMER_CAPTURE_D_IRQ_BASE + (channel*8))
#define UTIMER_CAPTURE_E_IRQ(channel)               (UTIMER_CAPTURE_E_IRQ_BASE + (channel*8))
#define UTIMER_CAPTURE_F_IRQ(channel)               (UTIMER_CAPTURE_F_IRQ_BASE + (channel*8))
#define UTIMER_UNDERFLOW_IRQ(channel)               (UTIMER_UNDERFLOW_IRQ_BASE + (channel*8))
#define UTIMER_OVERFLOW_IRQ(channel)                (UTIMER_OVERFLOW_IRQ_BASE + (channel*8))

#define ARM_UTIMER_TRIGGER_FOR_START                (1)
#define ARM_UTIMER_TRIGGER_FOR_STOP                 (2)
#define ARM_UTIMER_TRIGGER_FOR_CLEAR                (3)
#define ARM_UTIMER_TRIGGER_FOR_UPCOUNT              (4)
#define ARM_UTIMER_TRIGGER_FOR_DOWNCOUNT            (5)
#define ARM_UTIMER_TRIGGER_FOR_CAPTURE_A            (6)
#define ARM_UTIMER_TRIGGER_FOR_CAPTURE_B            (7)

#define ARM_UTIMER_MAX_CHANNEL                      (16)
#define ARM_UTIMER_MAX_SUPPORTING_CHANNEL           (12)

typedef struct
{
    __IOM uint32_t cntr_ctrl;                           /**< Counter Control Register >*/
    __IOM uint32_t cntr_start_src;                      /**< Counter Start Source Register >*/
    __IOM uint32_t cntr_stop_src;                       /**< Counter Stop Source Register >*/
    __IOM uint32_t cntr_clear_src;                      /**< Counter Clear Source Register >*/
    __IOM uint32_t cntr_up_src;                         /**< Counter Up Source Register >*/
    __IOM uint32_t cntr_down_src;                       /**< Counter Down Source Register >*/
    __IM  uint32_t reserved1[6];                        /**< Reserved Registers >*/
    __IOM uint32_t trig_capture_src_a;                  /**< Trigger Capture Source A Register >*/
    __IOM uint32_t trig_capture_src_b;                  /**< Trigger Capture Source B Register >*/
    __IM  uint32_t reserved2[6];                        /**< Reserved Registers >*/
    __IOM uint32_t compare_ctrl_a;                      /**< Compare Control A Register >*/
    __IOM uint32_t compare_ctrl_b;                      /**< Compare Control B Register >*/
    __IOM uint32_t buf_op_ctrl;                         /**< Buffer Op Control Register >*/
    __IM  uint32_t reserved3[9];                        /**< Reserved Registers >*/
    __IOM uint32_t cntr;                                /**< Counter Register >*/
    __IOM uint32_t cntr_ptr;                            /**< Counter Pointer Register >*/
    __IOM uint32_t cntr_ptr_buf1;                       /**< Counter Pointer Buffer 1 Register >*/
    __IOM uint32_t cntr_ptr_buf2;                       /**< Counter Pointer Buffer 2 Register >*/
    __IOM uint32_t capture_a;                           /**< Capture A Register >*/
    __IOM uint32_t capture_a_buf1;                      /**< Capture A Buffer 1 Register >*/
    __IOM uint32_t capture_a_buf2;                      /**< Capture A Buffer 2 Register >*/
    __IM  uint32_t reserved4;                           /**< Reserved Registers >*/
    __IOM uint32_t capture_b;                           /**< Capture B Register >*/
    __IOM uint32_t capture_b_buf1;                      /**< Capture B Buffer 1 Register >*/
    __IOM uint32_t capture_b_buf2;                      /**< Capture B Buffer 2 Register >*/
    __IM  uint32_t reserved5;                           /**< Reserved Registers >*/
    __IOM uint32_t compare_a;                           /**< Compare A Register >*/
    __IOM uint32_t compare_a_buf1;                      /**< Compare A Buffer 1 Register >*/
    __IOM uint32_t compare_a_buf2;                      /**< Compare A Buffer 2 Register >*/
    __IM  uint32_t reserved6;                           /**< Reserved Registers >*/
    __IOM uint32_t compare_b;                           /**< Compare B Register >*/
    __IOM uint32_t compare_b_buf1;                      /**< Compare B Buffer 1 Register >*/
    __IOM uint32_t compare_b_buf2;                      /**< Compare B Buffer 2 Register >*/
    __IM  uint32_t reserved7;                           /**< Reserved Registers >*/
    __IOM uint32_t dead_time_up;                        /**< Dead time up Register >*/
    __IOM uint32_t dead_time_up_buf;                    /**< Dead time up Buffer Register >*/
    __IOM uint32_t dead_time_down;                      /**< Dead time down Register >*/
    __IOM uint32_t dead_time_down_buf;                  /**< Dead time up Buffer Register >*/
    __IM  uint32_t reserved8[5];                        /**< Reserved Registers >*/
    __IOM uint32_t chan_status;                         /**< Channel Status Register >*/
    __IOM uint32_t chan_interrupt;                      /**< Channel interrupt Control >*/
    __IOM uint32_t chan_interrupt_mask;                 /**< Channel Interrupt Mask Register >*/
    __IOM uint32_t duty_cycle_ctrl;                     /**< Duty cycle control register >*/
    __IOM uint32_t dead_time_ctrl;                      /**< Dead Control Register >*/
    __IM  uint32_t reserved9[958];                      /**< Reserved Registers >*/
} _TIMER_Channel_RegInfo;

typedef struct {
    __IOM uint32_t glb_cntr_start;                      /**< Global Counter Start Register >*/
    __IOM uint32_t glb_cntr_stop;                       /**< Global Counter Stop Register >*/
    __IOM uint32_t glb_cntr_clear;                      /**< Global Counter Clear Register >*/
    __IOM uint32_t glb_cntr_running;                    /**< Global Counter Running Status Register >*/
    __IM uint32_t reserved[2];                          /**< Reserved Registers >*/
    __IOM uint32_t glb_driver_oen;                      /**< Channel Driver oen Register >*/
} _TIMER_Glb_RegInfo;

typedef struct {
    __IM uint32_t reserved1[68];                        /**< Reserved Registers >*/
    _TIMER_Glb_RegInfo TIMER_Glb_RegInfo;               /**< Timer Global Registers >*/
    __IM uint32_t reserved2[949];                       /**< Reserved Registers >*/
    _TIMER_Channel_RegInfo TIMER_Channel_RegInfo[ARM_UTIMER_MAX_CHANNEL];   /**< Timer Channel Registers >*/
} TIMER_RegInfo;

typedef struct _UTIMER_TIMER_INFO
{
    uint32_t timer_cycle:1;                             /**< channel counting cycle, SET: 1 Iteration, CLEAR: multiple Iteration >*/
    uint32_t buf_trough_n_crest:2;                      /**< configuring buffering for triangle timer at trough or trough and crest or fixed op >*/
    uint32_t driver_A:1;                                /**< output drive type A, SET: enabled, CLEAR: disbled>*/
    uint32_t driver_B:1;                                /**< output drive type B, SET: enabled, CLEAR: disabled>*/
    uint32_t cmp_drive_start_state:1;                   /**< COMPARE: output drive start state, SET: Driver state is HIGH, CLEAR: Driver state is LOW >*/
    uint32_t cmp_drive_stop_state:1;                    /**< COMPARE: output drive stop  state, SET: Driver state is HIGH, CLEAR: Driver state is LOW >*/
    uint32_t drive_op_at_match_count:2;                 /**< COMPARE: state of driver out-put on count matches with compare buffer values >*/
    uint32_t drive_op_at_cycle_end:2;                   /**< COMPARE: state of driver out-put on end of cycle, counter_overflow/counter_underflow >*/
    uint32_t buffering_type:1;                          /**< Buffering type Single or Double>*/
    uint32_t buffering_event_at_crest:1;                /**< buffering at crest transfer>*/
    uint32_t buffering_event_at_trough:1;               /**< buffering at trough transfer>*/
    uint32_t buffering_type_A:1;                        /**< Only for Capture mode: Buffering type for Drive A Single or Double>*/
    uint32_t buffering_type_B:1;                        /**< Only for Capture mode: Buffering type for Drive B Single or Double>*/
    IRQn_Type capture_A_irq_priority;                   /**< IRQ Priority for Compare/Capture A match event>*/
    IRQn_Type capture_B_irq_priority;                   /**< IRQ Priority for Compare/Capture B match event>*/
    IRQn_Type capture_C_irq_priority;                   /**< IRQ Priority for Compare/Capture A Buffer 1 match event */
    IRQn_Type capture_D_irq_priority;                   /**< IRQ Priority for Compare/Capture A Buffer 2 match event>*/
    IRQn_Type capture_E_irq_priority;                   /**< IRQ Priority for Compare/Capture B Buffer 1 match event>*/
    IRQn_Type capture_F_irq_priority;                   /**< IRQ Priority for Compare/Capture B Buffer 2 match event>*/
    IRQn_Type over_flow_irq_priority;                   /**< IRQ Priority for Over Flow event>*/
    IRQn_Type under_flow_irq_priority;                  /**< IRQ Priority for Under Flow event>*/
    uint32_t flag;                                      /**< UTIMER channel status flag >*/
    uint32_t channel_mode_backup;                       /**< UTIMER Channel mode back up >*/
    uint32_t channel_direction_backup;                  /**< UTIMER Channel mode back up >*/
    ARM_UTIMER_SignalEvent_t CB_function_ptr;           /**< Holding CB functions >*/
} UTIMER_TIMER_INFO;

typedef struct UTIMER_resources {
    uint32_t reg_base;                                  /**< UTMER register base address >*/
    UTIMER_TIMER_INFO *info;                            /**< UTIMER info structure base address >*/
} UTIMER_resources_t;

int32_t UTIMER_ll_PowerOff                      (UTIMER_resources_t *UTIMER, uint8_t channel);
int32_t UTIMER_ll_PowerFull                     (UTIMER_resources_t *UTIMER, uint8_t channel);
int32_t UTIMER_ll_Mode_Config                   (UTIMER_resources_t *UTIMER, uint8_t channel, UTIMER_MODE_CONFIG *arg);
int32_t UTIMER_ll_Set_Count                     (UTIMER_resources_t *UTIMER, uint8_t channel, UTIMER_SET_OPERATION_CONFIG *arg);
int32_t UTIMER_ll_Get_Count                     (UTIMER_resources_t *UTIMER, uint8_t channel, UTIMER_GET_OPERATION_CONFIG *arg);
int32_t UTIMER_ll_Get_Direction                 (UTIMER_resources_t *UTIMER, uint8_t channel, uint32_t *arg);
int32_t UTIMER_ll_Configure_Trigger             (UTIMER_resources_t *UTIMER, uint8_t channel, uint8_t triggerFor, uint32_t triggerType);
int32_t UTIMER_ll_Start                         (UTIMER_resources_t *UTIMER, uint8_t channel);
int32_t UTIMER_ll_Stop                          (UTIMER_resources_t *UTIMER, uint8_t channel, bool count_clear_option);
int32_t UTIMER_ll_Uninitialize                  (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_A          (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_B          (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_C          (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_D          (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_E          (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_F          (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_OverFlow   (UTIMER_resources_t *UTIMER, uint8_t channel);
void    UTIMER_ll_IRQHandler_Compare_UnderFlow  (UTIMER_resources_t *UTIMER, uint8_t channel);

#endif /*__UTIMER_LL_DRIVER_H__ */
