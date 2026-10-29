#include "driver/gpio.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include "hal/gpio_types.h"
#include "soc/gpio_num.h"
#include <stdbool.h>
#include <stdio.h>
#include <sys/_intsup.h>

#define BTN_GPIO GPIO_NUM_27
#define LED_GPIO GPIO_NUM_2

static void prepare_pins(void)
{
	gpio_set_direction(BTN_GPIO, GPIO_MODE_INPUT);
	gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
	gpio_set_pull_mode(BTN_GPIO, GPIO_PULLUP_ONLY);
}

void app_main(void)
{
	prepare_pins();
	gpio_set_level(LED_GPIO, 1);

	while (1)
	{
		int btn_level = gpio_get_level(BTN_GPIO);
		printf("level: %d\n", btn_level);
		gpio_set_level(LED_GPIO, btn_level);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}
