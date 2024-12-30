#include "df_current_sensor.h"

namespace esphome {
namespace df_current_sensor {

void DFCurrentSensor::setup() {
  ESP_LOGCONFIG("DFCurrentSensor", "Initializing DF Current Sensor...");
}

void DFCurrentSensor::update() {
  uint8_t buffer[2];
  if (!this->read_bytes(buffer, 2)) {
    ESP_LOGE("DFCurrentSensor", "Failed to read from sensor!");
    return;
  }

  uint16_t raw_value = (buffer[0] << 8) | buffer[1];
  float current_mA = (raw_value / 65535.0) * 16.0 + 4.0;
  float gallons = (current_mA - 4.0) * (500.0 / 16.0);
  this->water_level_sensor->publish_state(gallons);
}

}  // namespace df_current_sensor
}  // namespace esphome
