/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    service1_app.c
  * @author  MCD Application Team
  * @brief   service1_app application definition.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "log_module.h"
#include "app_ble.h"
#include "ll_sys_if.h"
#include "dbg_trace.h"
#include "ble.h"
#include "serv1_app.h"
#include "serv1.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

typedef enum
{
  Char1_NOTIFICATION_OFF,
  Char1_NOTIFICATION_ON,
  Char3_NOTIFICATION_OFF,
  Char3_NOTIFICATION_ON,
  /* USER CODE BEGIN Service1_APP_SendInformation_t */

  /* USER CODE END Service1_APP_SendInformation_t */
  SERV1_APP_SENDINFORMATION_LAST
} SERV1_APP_SendInformation_t;

typedef struct
{
  SERV1_APP_SendInformation_t     Char1_Notification_Status;
  SERV1_APP_SendInformation_t     Char3_Notification_Status;
  /* USER CODE BEGIN Service1_APP_Context_t */
  uint16_t Serv1Handle;
  uint16_t Serv1Char1Handle;
  uint16_t Serv1Char2Handle;
  uint16_t Serv1Char3Handle;
  /* USER CODE END Service1_APP_Context_t */
  uint16_t              ConnectionHandle;
} SERV1_APP_Context_t;

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */
SERVICE1_APP_Context_t SERVICE1_APP_Context;
/* USER CODE END EV */

/* Private macros ------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
static SERV1_APP_Context_t SERV1_APP_Context;

uint8_t a_SERV1_UpdateCharData[247];

/* USER CODE BEGIN PV */
static const uint16_t SizeChar3 = 255;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void SERV1_Char1_SendNotification(void);
static void SERV1_Char3_SendNotification(void);

/* USER CODE BEGIN PFP */
#define COPY_UUID_128(uuid_struct, uuid_15, uuid_14, uuid_13, uuid_12, uuid_11, uuid_10, uuid_9, uuid_8, uuid_7, uuid_6, uuid_5, uuid_4, uuid_3, uuid_2, uuid_1, uuid_0) \
do {\
    uuid_struct[0] = uuid_0; uuid_struct[1] = uuid_1; uuid_struct[2] = uuid_2; uuid_struct[3] = uuid_3; \
    uuid_struct[4] = uuid_4; uuid_struct[5] = uuid_5; uuid_struct[6] = uuid_6; uuid_struct[7] = uuid_7; \
    uuid_struct[8] = uuid_8; uuid_struct[9] = uuid_9; uuid_struct[10] = uuid_10; uuid_struct[11] = uuid_11; \
    uuid_struct[12] = uuid_12; uuid_struct[13] = uuid_13; uuid_struct[14] = uuid_14; uuid_struct[15] = uuid_15; \
}while(0)

#define COPY_CHAR3_UUID(uuid_struct)       COPY_UUID_128(uuid_struct,0x00,0x00,0x01,0x33,0x8e,0x22,0x45,0x41,0x9d,0x4c,0x21,0xed,0xae,0x82,0xed,0x19)
/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void SERV1_Notification(SERV1_NotificationEvt_t *p_Notification)
{
  /* USER CODE BEGIN Service1_Notification_1 */

  /* USER CODE END Service1_Notification_1 */
  switch(p_Notification->EvtOpcode)
  {
    /* USER CODE BEGIN Service1_Notification_Service1_EvtOpcode */

    /* USER CODE END Service1_Notification_Service1_EvtOpcode */

    case SERV1_CHAR1_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN Service1Char1_NOTIFY_ENABLED_EVT */

      /* USER CODE END Service1Char1_NOTIFY_ENABLED_EVT */
      break;

    case SERV1_CHAR1_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN Service1Char1_NOTIFY_DISABLED_EVT */

      /* USER CODE END Service1Char1_NOTIFY_DISABLED_EVT */
      break;

    case SERV1_CHAR2_READ_EVT:
      /* USER CODE BEGIN Service1Char2_READ_EVT */

      /* USER CODE END Service1Char2_READ_EVT */
      break;

    case SERV1_CHAR2_WRITE_NO_RESP_EVT:
      /* USER CODE BEGIN Service1Char2_WRITE_NO_RESP_EVT */

      /* USER CODE END Service1Char2_WRITE_NO_RESP_EVT */
      break;

    case SERV1_CHAR3_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN Service1Char3_NOTIFY_ENABLED_EVT */

      /* USER CODE END Service1Char3_NOTIFY_ENABLED_EVT */
      break;

    case SERV1_CHAR3_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN Service1Char3_NOTIFY_DISABLED_EVT */

      /* USER CODE END Service1Char3_NOTIFY_DISABLED_EVT */
      break;

    default:
      /* USER CODE BEGIN Service1_Notification_default */

      /* USER CODE END Service1_Notification_default */
      break;
  }
  /* USER CODE BEGIN Service1_Notification_2 */

  /* USER CODE END Service1_Notification_2 */
  return;
}

void SERV1_APP_EvtRx(SERV1_APP_ConnHandleNotEvt_t *p_Notification)
{
  /* USER CODE BEGIN Service1_APP_EvtRx_1 */

  /* USER CODE END Service1_APP_EvtRx_1 */

  switch(p_Notification->EvtOpcode)
  {
    /* USER CODE BEGIN Service1_APP_EvtRx_Service1_EvtOpcode */

    /* USER CODE END Service1_APP_EvtRx_Service1_EvtOpcode */
    case SERV1_CONN_HANDLE_EVT :
      /* USER CODE BEGIN Service1_APP_CONN_HANDLE_EVT */

      /* USER CODE END Service1_APP_CONN_HANDLE_EVT */
      break;

    case SERV1_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN Service1_APP_DISCON_HANDLE_EVT */

      /* USER CODE END Service1_APP_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN Service1_APP_EvtRx_default */

      /* USER CODE END Service1_APP_EvtRx_default */
      break;
  }

  /* USER CODE BEGIN Service1_APP_EvtRx_2 */

  /* USER CODE END Service1_APP_EvtRx_2 */

  return;
}

void SERV1_APP_Init(void)
{
  UNUSED(SERV1_APP_Context);
  SERV1_Init();

  /* USER CODE BEGIN Service1_APP_Init */

  /* USER CODE END Service1_APP_Init */
  return;
}

/* USER CODE BEGIN FD */
void GCS_Button1TriggerReceived(void)
{
  tBleStatus status;
  Char_UUID_t  uuid;
  /* add charac */
  COPY_CHAR3_UUID(uuid.Char_UUID_128);
  status = aci_gatt_add_char(SERVICE1_APP_Context.Serv1Handle,
                          UUID_TYPE_128,
                          (Char_UUID_t *) &uuid,
                          SizeChar3,
                          CHAR_PROP_NOTIFY,
                          ATTR_PERMISSION_NONE,
                          GATT_NOTIFY_ATTRIBUTE_WRITE,
                          0x10,
                          CHAR_VALUE_LEN_VARIABLE,
                          &(SERVICE1_APP_Context.Serv1Char3Handle));
  if (status != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_gatt_add_char command   : CHAR3, error code: 0x%2X\n", status);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_gatt_add_char command   : CHAR3\n");
  }
  return;
}

void GCS_Button2TriggerReceived(void)
{
  tBleStatus status;
  /* remove charac */
  status = aci_gatt_del_char(SERVICE1_APP_Context.Serv1Handle, SERVICE1_APP_Context.Serv1Char3Handle);
  if (status != BLE_STATUS_SUCCESS)
  {
    LOG_INFO_APP("  Fail   : aci_gatt_del_char command   : CHAR3, error code: 0x%2X\n", status);
  }
  else
  {
    LOG_INFO_APP("  Success: aci_gatt_del_char command   : CHAR3\n");
  }
  return;
}

void GCS_Button3TriggerReceived(void)
{

  return;
}
/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/
__USED void SERV1_Char1_SendNotification(void) /* Property Notification */
{
  SERV1_APP_SendInformation_t notification_on_off = Char1_NOTIFICATION_OFF;
  SERV1_Data_t serv1_notification_data;

  serv1_notification_data.p_Payload = (uint8_t*)a_SERV1_UpdateCharData;
  serv1_notification_data.Length = 0;

  /* USER CODE BEGIN Service1Char1_NS_1*/

  /* USER CODE END Service1Char1_NS_1*/

  if (notification_on_off != Char1_NOTIFICATION_OFF)
  {
    SERV1_UpdateValue(SERV1_CHAR1, &serv1_notification_data);
  }

  /* USER CODE BEGIN Service1Char1_NS_Last*/

  /* USER CODE END Service1Char1_NS_Last*/

  return;
}

__USED void SERV1_Char3_SendNotification(void) /* Property Notification */
{
  SERV1_APP_SendInformation_t notification_on_off = Char3_NOTIFICATION_OFF;
  SERV1_Data_t serv1_notification_data;

  serv1_notification_data.p_Payload = (uint8_t*)a_SERV1_UpdateCharData;
  serv1_notification_data.Length = 0;

  /* USER CODE BEGIN Service1Char3_NS_1*/

  /* USER CODE END Service1Char3_NS_1*/

  if (notification_on_off != Char3_NOTIFICATION_OFF)
  {
    SERV1_UpdateValue(SERV1_CHAR3, &serv1_notification_data);
  }

  /* USER CODE BEGIN Service1Char3_NS_Last*/

  /* USER CODE END Service1Char3_NS_Last*/

  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/

/* USER CODE END FD_LOCAL_FUNCTIONS*/
