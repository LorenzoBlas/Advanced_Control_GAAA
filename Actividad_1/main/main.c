#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"

#define LED 2
static uint8_t led_level = 0;
static const char *TAG = "LED_BLINK";

esp_err_t init_led(void){
    ESP_LOGI(TAG, "Inicializando LED en pin %d", LED);
    
    gpio_reset_pin(LED);
    ESP_LOGD(TAG, "Pin reseteado correctamente");
    
    esp_err_t err = gpio_set_direction(LED, GPIO_MODE_OUTPUT);
    
    return err;
}

esp_err_t blink_led(void){
    led_level = !led_level;
    
    ESP_LOGD(TAG, "Cambiando estado del LED a: %d", led_level);
    
    esp_err_t err = gpio_set_level(LED, led_level);
    
    if(err != ESP_OK){
        ESP_LOGE(TAG, "ERROR crítico al cambiar nivel del LED. Código: %s", esp_err_to_name(err));
        ESP_LOGW(TAG, "Advertencia: El LED podría no estar funcionando correctamente");
        return err;
    }
    
    if(led_level == 1){
        ESP_LOGI(TAG, "LED encendido ✓");
    } else {
        ESP_LOGE(TAG, "LED apagado ✗");
    }
    
    return err;
}

void app_main(void){
    esp_log_level_set(TAG, ESP_LOG_DEBUG);
    ESP_LOGI(TAG, "========================================");
    ESP_LOGI(TAG, "Iniciando aplicación de parpadeo LED");
    ESP_LOGI(TAG, "========================================");
    ESP_LOGD(TAG, "1 parpadeo por segundo");
    
    ESP_ERROR_CHECK(init_led());
    
    ESP_LOGI(TAG, "Entrando en bucle principal");
    
    int contador = 0;
    while(1){
        ESP_LOGW(TAG, "Ciclo #%d del bucle principal", contador++);
        
        vTaskDelay(pdMS_TO_TICKS(1000));
        ESP_LOGI(TAG, "Retardo completado, ejecutando blink_led()");
        
        ESP_ERROR_CHECK(blink_led());
    }	
}