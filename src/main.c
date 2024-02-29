#include <stdint.h>


#ifdef STM32L031xx
#define C13_Pin GPIO_PIN_3
#define C13_GPIO_Port GPIOB
#endif

#ifdef STM32F401xE
#define C13_Pin GPIO_PIN_13
#define C13_GPIO_Port GPIOC
#endif

#ifdef STM32G431xx
#define C13_Pin GPIO_PIN_8
#define C13_GPIO_Port GPIOB
#endif

#define KEY_Pin GPIO_PIN_0
#define KEY_GPIO_Port GPIOA

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
#ifndef STM32G431xx
  __HAL_RCC_GPIOH_CLK_ENABLE();
#else
  __HAL_RCC_GPIOB_CLK_ENABLE();
#endif
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(C13_GPIO_Port, C13_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = C13_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(C13_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
#ifdef WEACTV30
  GPIO_InitStruct.Pin = KEY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY_GPIO_Port, &GPIO_InitStruct);
#endif
}


// the loop function runs over and over again forever
int main(void) {

  HAL_Init();
  MX_GPIO_Init();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

        // Toggle the LED
        HAL_GPIO_TogglePin(C13_GPIO_Port, C13_Pin);

        // Wait for 500 ms
        HAL_Delay(100);

        // Rinse and repeat :)

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

  return 0;
}

void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

