// disable pins
// uint8_t disabled_pins[11] = {1, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}; //10 pins max. First array position is used as index
extern uint8_t pinMask_DIN[];
extern uint8_t pinMask_AIN[];
extern uint8_t pinMask_DOUT[];
extern uint8_t pinMask_AOUT[];

#ifdef USE_DS18B20_BLOCK
#include "modules/ds18b20.c"
#endif

#ifdef USE_P1AM_BLOCKS
#include "modules/p1am.c"
#endif

#ifdef USE_CLOUD_BLOCKS
#include "modules/arduino_cloud.c"
#endif

#ifdef USE_MQTT_BLOCKS
#include "modules/mqtt.c"
#endif

#ifdef USE_SM_BLOCKS
#include "modules/sm_cards.c"
#endif

#ifdef USE_ARDUINOCAN_BLOCK
#include "modules/arduinocan.c"
#endif

#ifdef USE_STM32CAN_BLOCK
#include "modules/stm32can.c"
#endif

// Declare external C++/C function
extern "C" void print_number_on_serial(uint16_t num);

bool first_time_called = true;
void print_number_on_serial(uint16_t num)
{
    if (first_time_called)
    {
        // Setup Serial port as this is the first time this function is called
        Serial.begin(115200);
        first_time_called = false;
    }
    Serial.print(num);
}