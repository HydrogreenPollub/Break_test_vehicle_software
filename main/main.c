#include "driver/gpio.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "math.h"
//#define ECHO_TEST_TXD (GPIO_NUM_22)
#define Forwad GPIO_NUM_34
#define Reverse GPIO_NUM_39
#define Grip_state GPIO_NUM_32
#define PWM_PIN GPIO_NUM_27
uint32_t map(uint32_t au32_IN, uint32_t au32_INmin, uint32_t au32_INmax, uint32_t au32_OUTmin, uint32_t au32_OUTmax)
{
    return ((((au32_IN - au32_INmin)*(au32_OUTmax - au32_OUTmin))/(au32_INmax - au32_INmin)) + au32_OUTmin);
}
void app_main(void){ 
gpio_set_direction(PWM_PIN, GPIO_MODE_OUTPUT);   
gpio_set_direction(Forwad, GPIO_MODE_INPUT);
gpio_set_direction(Reverse, GPIO_MODE_INPUT);
gpio_set_direction(Grip_state, GPIO_MODE_INPUT);
int PWM;
int Grip;
while (1) {
  if(Forwad){
    Grip = gpio_get_level(Grip_state);
    PWM = map(Grip,0,1023,120,240);
    gpio_set_level(PWM_PIN, PWM);
    }
  if(Reverse){
    Grip = gpio_get_level(Grip_state);
    PWM = map(Grip,0,1023,120,10);
    gpio_set_level(PWM_PIN, PWM);
    }
vTaskDelay(1);
}
}
