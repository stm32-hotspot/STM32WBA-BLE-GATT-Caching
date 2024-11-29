/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    service1.h
  * @author  MCD Application Team
  * @brief   Header for service1.c
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
#ifndef SERV1_H
#define SERV1_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported defines ----------------------------------------------------------*/
/* USER CODE BEGIN ED */

/* USER CODE END ED */

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  SERV1_CHAR1,
  SERV1_CHAR2,
  SERV1_CHAR3,
  /* USER CODE BEGIN Service1_CharOpcode_t */

  /* USER CODE END Service1_CharOpcode_t */
  SERV1_CHAROPCODE_LAST
} SERV1_CharOpcode_t;

typedef enum
{
  SERV1_CHAR1_NOTIFY_ENABLED_EVT,
  SERV1_CHAR1_NOTIFY_DISABLED_EVT,
  SERV1_CHAR2_READ_EVT,
  SERV1_CHAR2_WRITE_NO_RESP_EVT,
  SERV1_CHAR3_NOTIFY_ENABLED_EVT,
  SERV1_CHAR3_NOTIFY_DISABLED_EVT,
  /* USER CODE BEGIN Service1_OpcodeEvt_t */

  /* USER CODE END Service1_OpcodeEvt_t */
  SERV1_BOOT_REQUEST_EVT
} SERV1_OpcodeEvt_t;

typedef struct
{
  uint8_t *p_Payload;
  uint8_t Length;

  /* USER CODE BEGIN Service1_Data_t */

  /* USER CODE END Service1_Data_t */
} SERV1_Data_t;

typedef struct
{
  SERV1_OpcodeEvt_t       EvtOpcode;
  SERV1_Data_t             DataTransfered;
  uint16_t                ConnectionHandle;
  uint16_t                AttributeHandle;
  uint8_t                 ServiceInstance;
  /* USER CODE BEGIN Service1_NotificationEvt_t */

  /* USER CODE END Service1_NotificationEvt_t */
} SERV1_NotificationEvt_t;

/* USER CODE BEGIN ET */

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
void SERV1_Init(void);
void SERV1_Notification(SERV1_NotificationEvt_t *p_Notification);
tBleStatus SERV1_UpdateValue(SERV1_CharOpcode_t CharOpcode, SERV1_Data_t *pData);
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /*SERV1_H */
