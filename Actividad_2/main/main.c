#include <stdio.h> //libreria para copiar al buffer etc.
#include "driver/gpio.h" //Si se necesita utilizar herramietnas que alguien mas ya hizo, osea SDK, al  hacer esto esta disponible. PARA MANEJAR LOS PINES DIGITALES
#include "freertos/FreeRTOS.h" //Sistema operativo para microcontroladores (administra las tareas)
#include "freertos/task.h"
#include "esp_log.h"
#include "freertos/timers.h"

#define LED 2


__uint8_t led_level = 0; //__u "unsigned_sing (sin signo)" - int8_t (entero de 8bits)
__uint8_t count = 0;
int timer_interval = 1000; //intervalo de timer en milisegundos
int timerId = 1; // Identificador del timer

TimerHandle_t xTimers;

static const char *TAG = "Logging";
esp_err_t init_led(void);
esp_err_t blink_led(void);
esp_err_t set_timer(void);

esp_err_t init_led(void){
 	gpio_reset_pin(LED);
 	esp_err_t err = gpio_set_direction(LED, GPIO_MODE_OUTPUT);
 	
 	if (err == ESP_OK){
 	    ESP_LOGI(TAG, "EL led se inicializo correctamente %d", LED);
 	    ESP_LOGD(TAG, "Debug: init_led() regreso ESP_OK");
 	}else {
 	    ESP_LOGE(TAG, "EL led fallo en inicializarse");
 	    
 	}
 	
 	return err;
}

esp_err_t blink_led(void){
	led_level = !led_level;
	ESP_LOGD(TAG, "Debug: parpadeo del led, siguient estado= %u", led_level);
	ESP_LOGI(TAG, "EL estado del led cambio");
	return gpio_set_level(LED, led_level);	
}

void vTimerCallback(TimerHandle_t px_Timer)
{
    ESP_LOGI(TAG, "Event was called from timer");
    blink_led();
}


esp_err_t set_timer(void){
    ESP_LOGI(TAG, "Inicializacion del timer");
    xTimers = xTimerCreate( // Nombre y cada que tiempo se necesita que se realice la funcion
        "Timer", //Nombre
        pdMS_TO_TICKS(timer_interval), //intervalo de tiempo
        pdTRUE,  // Reload de la funcion
        (void *)timerId, 
        vTimerCallback // FUncion a ejecutar
    ); 
    if (xTimers==NULL) {
        ESP_LOGE(TAG, "El timer no se creo de forma adecuada GAAAAAAA");
    } else {
        if (xTimerStart(xTimers, 0)!=pdPASS){ 
        ESP_LOGE(TAG, "EL timer se creo de forma adecuada EEEEEEO");
        }
    }
    return ESP_OK;
}

void app_main(void){
    init_led();
    set_timer();
}
