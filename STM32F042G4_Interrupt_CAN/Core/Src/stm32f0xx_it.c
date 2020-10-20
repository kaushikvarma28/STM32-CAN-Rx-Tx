/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t txdata1[30] =  "CAN Interrupt \n";
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern CAN_HandleTypeDef hcan;
extern CAN_HandleTypeDef hcan;
extern CAN_TxHeaderTypeDef pHeader;
extern CAN_RxHeaderTypeDef pRxHeader;
extern uint32_t TxMailbox;
extern uint8_t a,r;
extern UART_HandleTypeDef huart1;
extern uint8_t newline[2];
extern uint8_t space[2]; //RxData[0];
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles HDMI-CEC and CAN global interrupts / HDMI-CEC wake-up interrupt through EXTI line 27.
  */
void CEC_CAN_IRQHandler(void)
{
	/* USER CODE BEGIN CEC_CAN_IRQn 0 */

	/* USER CODE END CEC_CAN_IRQn 0 */
	HAL_CAN_IRQHandler(&hcan);
	/* USER CODE BEGIN CEC_CAN_IRQn 1 */
	CAN_RxHeaderTypeDef RxHeader;
	uint8_t RxData[8];
	uint8_t ID[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	char B0[2];
	char B1[2];
	char B2[2];
	char B3[2];
	char B4[2];
	char B5[2];
	char B6[2];
	char B7[2];

	HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &RxHeader, RxData);  // get the currently waiting frame

	//	  		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_7);
	char buffer1 [8];
	sprintf(buffer1,"%0x",RxHeader.ExtId);

	sprintf(B0,"%0x",RxData[0]);
	sprintf(B1,"%0x",RxData[1]);
	sprintf(B2,"%0x",RxData[2]);
	sprintf(B3,"%0x",RxData[3]);
	sprintf(B4,"%0x",RxData[4]);
	sprintf(B5,"%0x",RxData[5]);



	HAL_UART_Transmit(&huart1, (uint8_t *)buffer1, sizeof(buffer1), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B0, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B1, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B2, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B3, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B3, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B4, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, (uint8_t *)B5, sizeof(B0), 20);
	HAL_UART_Transmit(&huart1, space, sizeof(space), 20);
	HAL_UART_Transmit(&huart1, newline, sizeof(newline), 20);
	//  GPIOD->ODR=r<<12; //use output data register to turn on LEDs
	HAL_UART_Transmit(&huart1, txdata1, sizeof(txdata1), 100);
	/* USER CODE END CEC_CAN_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
