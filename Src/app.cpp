#include "app.hpp"

void setup()
{

}

void loop()
{
  static bool blink = false;
  GPIO_PinState pin_state;
  if(blink)
  {
    blink = false;
    pin_state = GPIO_PIN_RESET;
  }
  else
  {
    blink = true;
    pin_state = GPIO_PIN_SET;
  }

  HAL_GPIO_WritePin(GPIOB, LD2_Pin, pin_state);
  HAL_Delay(100);
}

