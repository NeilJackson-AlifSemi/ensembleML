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
 * @file     Driver_Camera_Controller.h
 * @author   Tanay Rami
 * @email    tanay@alifsemi.com
 * @version  V1.0.0
 * @date     01-Sep-2021
 * @brief    Camera Controller Driver definitions.
 ******************************************************************************/

#ifndef DRIVER_CAMERA_CONTROLLER_H_
#define DRIVER_CAMERA_CONTROLLER_H_

#ifdef  __cplusplus
extern "C"
{
#endif

#include "Driver_Common.h"
#include "Camera_Common.h"

#define ARM_CAMERA_CONTROLLER_API_VERSION ARM_DRIVER_VERSION_MAJOR_MINOR(1,0)  /* API version */

/****** CAMERA_CONTROLLER Control Codes *****/
#define CAMERA_CONTROLLER_SOFTRESET                                (0x01UL)    ///< CAMERA CONTROLLER Software Reset; arg: 0=disable, 1=enable

/****** CAMERA_CONTROLLER Event *****/
#define ARM_CAMERA_CONTROLLER_EVENT_CAMERA_CAPTURE_STOPPED         (1UL << 0)  ///< Camera Capture Stopped
#define ARM_CAMERA_CONTROLLER_EVENT_CAMERA_FRAME_VSYNC_DETECTED    (1UL << 1)  ///< Camera Frame VSYNC Detected for incoming frame
#define ARM_CAMERA_CONTROLLER_EVENT_ERR_CAMERA_FIFO_OVERRUN        (1UL << 2)  ///< Camera FIFO over run Error
#define ARM_CAMERA_CONTROLLER_EVENT_ERR_CAMERA_FIFO_UNDERRUN       (1UL << 3)  ///< Camera FIFO under run Error
#define ARM_CAMERA_CONTROLLER_EVENT_ERR_HARDWARE                   (1UL << 4)  ///< Hardware Bus Error

// Function documentation
/**
  \fn          ARM_DRIVER_VERSION GetVersion (void)
  \brief       Get Camera Controller driver version.
  \return      \ref ARM_DRIVER_VERSION

  \fn          ARM_CAMERA_CONTROLLER_CAPABILITIES GetCapabilities (void)
  \brief       Get Camera Controller driver capabilities
  \return      \ref ARM_CAMERA_CONTROLLER_CAPABILITIES

  \fn          int32_t Initialize (CAMERA_RESOLUTION camera_resolution,
                                   ARM_CAMERA_CONTROLLER_SignalEvent_t cb_event)
  \brief       Initialize Camera Controller and Camera Sensor Device Interface.
  \param[in]   camera_resolution : \ref CAMERA_RESOLUTION from "Camera_Common.h"
  \param[in]   cb_event          : Pointer to \ref ARM_CAMERA_CONTROLLER_SignalEvent_t
  \return      \ref execution_status

  \fn          int32_t Uninitialize (void)
  \brief       De-initialize Camera Controller and Camera Sensor Device Interface.
  \return      \ref execution_status

  \fn          int32_t PowerControl (ARM_POWER_STATE state)
  \brief       Control Camera Controller Interface Power.
  \param[in]   state : Power state
  \return      \ref execution_status

  \fn          int32_t CaptureFrame (uint8_t *framebuffer_startaddr)
  \brief       Start Camera Controller in Snapshot mode and Camera Sensor Device Interface.
                In Snapshot mode, Camera Controller will capture one frame then it gets stop.
  \param[in]   framebuffer_startaddr : Pointer to frame buffer start address, where camera captured image will be stored.
  \return      \ref execution_status

  \fn          int32_t Stop (void)
  \brief       Stop Camera Controller and Camera Sensor Device Interface.
  \return      \ref execution_status

  \fn          int32_t Control (uint32_t control, uint32_t arg)
  \brief       Control Camera Controller and Camera Sensor Device Interface.
  \param[in]   control : Operation
  \param[in]   arg     : Argument of operation (optional)
  \return      common \ref execution_status
*/

typedef void (*ARM_CAMERA_CONTROLLER_SignalEvent_t) (uint32_t event);  ///< Pointer to \ref ARM_CAMERA_CONTROLLER_SignalEvent_t : Signal CAMERA CONTROLLER Event.

/**
\brief Camera Controller Driver Capabilities.
*/
typedef struct _ARM_CAMERA_CONTROLLER_CAPABILITIES {
  uint32_t snapshot           : 1;        ///< Supports Camera Controller Snapshot mode, In this mode Camera Controller will capture one frame then it gets stop.
  uint32_t reserved           : 31;       ///< Reserved (must be zero)
} ARM_CAMERA_CONTROLLER_CAPABILITIES;


/**
\brief Access structure of the Camera Controller Driver.
*/
typedef struct _ARM_DRIVER_CAMERA_CONTROLLER {
  ARM_DRIVER_VERSION                  (*GetVersion)      (void);                                           ///< Pointer to \ref CAMERA_GetVersion      : Get driver version.
  ARM_CAMERA_CONTROLLER_CAPABILITIES  (*GetCapabilities) (void);                                           ///< Pointer to \ref CAMERA_GetCapabilities : Get driver capabilities.
  int32_t                             (*Initialize)      (ARM_CAMERA_RESOLUTION camera_resolution,
                                                          ARM_CAMERA_CONTROLLER_SignalEvent_t cb_event);   ///< Pointer to \ref CAMERA_Initialize      : Initialize Camera Controller Interface.
  int32_t                             (*Uninitialize)    (void);                                           ///< Pointer to \ref CAMERA_Uninitialize    : De-initialize Camera Controller Interface.
  int32_t                             (*PowerControl)    (ARM_POWER_STATE state);                          ///< Pointer to \ref CAMERA_PowerControl    : Control Camera Controller Interface Power.
  int32_t                             (*CaptureFrame)    (uint8_t *framebuffer_startaddr);                 ///< Pointer to \ref CAMERA_StartSnapshot   : Start Camera Controller Interface in Snapshot mode.
  int32_t                             (*Stop)            (void);                                           ///< Pointer to \ref CAMERA_Stop            : Stop  Camera Controller Interface.
  int32_t                             (*Control)         (uint32_t control, uint32_t arg);                 ///< Pointer to \ref CAMERA_Control         : Control Camera Controller Interface.
} const ARM_DRIVER_CAMERA_CONTROLLER;

#ifdef  __cplusplus
}
#endif

#endif /* DRIVER_CAMERA_CONTROLLER_H_ */

/************************ (C) COPYRIGHT ALIF SEMICONDUCTOR *****END OF FILE****/
