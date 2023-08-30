#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "esp_event.h"
#include "esp_netif_types.h"
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include <string.h>
#include <ctype.h>
#define ECHO_TEST_TXD (GPIO_NUM_22)
#define ECHO_TEST_RXD (GPIO_NUM_23)
#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)
#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)

#define ECHO_UART_PORT_NUM      (UART_NUM_2)
static const char *TAG = "UART TEST";
volatile char *buffer_pointer;

#define BUF_SIZE (256)
void convert (uint8_t *a)
{
    int buffer1[9];
    char buffer2[9];
    int i;
   
    buffer1[8]='\0';

    for(i=0; i<=7; i++)
        buffer1[7-i]=( ((*a)>>i)&(0x01) );

    for(i=0; i<=7; i++)
        buffer2[i] = buffer1[i] + '0';

    buffer2[8] = '\0';

    puts(buffer2);

    buffer_pointer = buffer2;
for(int i =0; i<sizeof(buffer_pointer);i++){
printf("HEX: %02X ", buffer_pointer[i]);
}
    printf("adrr :%p \n",buffer_pointer);
//    return buffer_pointer;
  return;
}
struct data {
  float fuel_cell_voltage;
  float fuel_cell_current;
  float super_capacitor_current;
  float super_capacitor_voltage;
  float vehicle_speed;
  float fan_rpm;
  float fuel_cell_temperature;
  float hydrogen_pressure;
  float motor_current;
  uint8_t error_codes;
  union {
    struct { // TODO remove bitfield since it won't be used here anyway
      uint8_t vehicle_is_speed_button_pressed:1;
      uint8_t vehicle_is_half_speed_button_pressed:1;
      uint8_t is_emergency:1;
      uint8_t hydrogen_cell_button_state:2; // Split into two variables?
      uint8_t is_super_capacitor_button_pressed:1;
      uint8_t is_relay_closed:1;
      uint8_t is_hydrogen_leaking:1;
    };
    uint8_t logic_state;
  };
} data;

static void SEND_NUDES(void *pVParameter){
 uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    int intr_alloc_flags = 0;
    int set;
    ESP_ERROR_CHECK(uart_driver_install(ECHO_UART_PORT_NUM, BUF_SIZE * 2, 0, 0, NULL, intr_alloc_flags));
    ESP_ERROR_CHECK(uart_param_config(ECHO_UART_PORT_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(ECHO_UART_PORT_NUM, ECHO_TEST_TXD, ECHO_TEST_RXD, ECHO_TEST_RTS, ECHO_TEST_CTS));
        data.fuel_cell_voltage = 10.0;
        data.fuel_cell_current = 11;
        data.super_capacitor_current = 21.38;
        data.super_capacitor_voltage = 21.39;
        data.vehicle_speed = 420.69;
        data.fan_rpm = 21.37;
        data.fuel_cell_temperature = 21.37;
        data.hydrogen_pressure = 21.37;
        data.motor_current = 21.37;
        data.error_codes = 0;
        data.logic_state = 3;
    // Configure a temporary buffer for the incoming data
    uint8_t * dataTX = (uint8_t *) malloc(sizeof(data));
    int test = 2137;
    while (1) {
        // Write data back to the UART
      if(set != 0 ){

        memcpy(dataTX,&data,sizeof(data));
        uart_write_bytes(ECHO_UART_PORT_NUM, dataTX, sizeof(data));
        set = 0;
        ESP_LOGI(TAG,"%d %d %d %d %f",dataTX[0],dataTX[1],dataTX[2],dataTX[3],data.fuel_cell_voltage);
        vTaskDelay(200/portTICK_PERIOD_MS);
        }
      else{
  //      uart_write_bytes(ECHO_UART_PORT_NUM, (const char *) dataTX, sizeof(data));
        set = 1;
      }
    }
} 
void app_main(void){
//     xTaskCreate(SEND_NUDES, "uart_task",2048, NULL, 10, NULL);
char data[5] = {68,85,80,65,44};
printf("%zu\n",sizeof(data));
puts(data);
}
