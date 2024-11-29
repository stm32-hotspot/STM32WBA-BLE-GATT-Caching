/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    service1_app.h
  * @author  MCD Application Team
  * @brief   Header for service1_app.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SERV1_APP_H
#define SERV1_APP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  SERV1_CONN_HANDLE_EVT,
  SERV1_DISCON_HANDLE_EVT,

  /* USER CODE BEGIN Service1_OpcodeNotificationEvt_t */

  /* USER CODE END Service1_OpcodeNotificationEvt_t */

  SERV1_LAST_EVT,
} SERV1_APP_OpcodeNotificationEvt_t;

typedef struct
{
  SERV1_APP_OpcodeNotificationEvt_t          EvtOpcode;
  uint16_t                                 ConnectionHandle;

  /* USER CODE BEGIN SERV1_APP_ConnHandleNotEvt_t */

  /* USER CODE END SERV1_APP_ConnHandleNotEvt_t */
} SERV1_APP_ConnHandleNotEvt_t;
/* USER CODE BEGIN ET */
typedef struct
{
  uint16_t Serv1Handle;
  uint16_t Serv1Char1Handle;
  uint16_t Serv1Char2Handle;
  uint16_t Serv1Char3Handle;
  uint16_t ConnectionHandle;
} SERVICE1_APP_Context_t;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macros -----------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void SERV1_APP_Init(void);
void SERV1_APP_EvtRx(SERV1_APP_ConnHandleNotEvt_t *p_Notification);
/* USER CODE BEGIN EFP */
void GCS_Button1TriggerReceived(void);
void GCS_Button2TriggerReceived(void);
void GCS_Button3TriggerReceived(void);
/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /*SERV1_APP_H */
