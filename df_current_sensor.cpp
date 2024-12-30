#include "df_current_sensor.h"

namespace esphome {
namespace df_current_sensor {

void DFCurrentSensor::setup() {
  ESP_LOGCONFIG("DFCurrentSensor", "Initializing DF Current Sensor...");
}

void DFCurrentSensor::update() {
  PollingComponent::update();
}

}  // namespace df_current_sensor
}  // namespace esphome
