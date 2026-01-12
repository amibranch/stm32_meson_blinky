#include <stdint.h>

#ifdef STM32L031xx
#define LED_GPIO_PIN         3
#define LED_GPIO_PORT        GPIOB
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#endif

#ifdef STM32F401xE
#define LED_GPIO_PIN         13
#define LED_GPIO_PORT        GPIOC
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()

// WeAct v3.0
#ifdef WEACTV30
#define KEY_Pin GPIO_PIN_0
#define KEY_GPIO_Port GPIOA
#endif
#endif

#ifdef STM32F405xx
#define LED_GPIO_PIN         13
#define LED_GPIO_PORT        GPIOC
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#endif

#ifdef STM32G431xx
#define LED_GPIO_PIN         8
#define LED_GPIO_PORT        GPIOB
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#endif

#ifdef NUCLEO144_F722ZE
#define LED_GPIO_PIN         0
#define LED_GPIO_PORT        GPIOB
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#endif

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
  LED_GPIO_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_SET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LED_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

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
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);

        // Wait for 500 ms
        HAL_Delay(500);

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

