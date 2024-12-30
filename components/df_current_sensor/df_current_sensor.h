#pragma once
#include "esphome.h"

namespace esphome {
namespace df_current_sensor {

class DFCurrentSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  DFCurrentSensor() : PollingComponent(1000) {}  // Poll every second

  Sensor *water_level_sensor = new Sensor();  // Expose water level in gallons

  void setup() override {
    ESP_LOGCONFIG("DFCurrentSensor", "Setting up DF Current Sensor...");
  }

  void update() override {
    uint8_t buffer[2];
    if (!read_bytes(buffer, 2)) {
      ESP_LOGE("DFCurrentSensor", "Failed to read from sensor!");
      return;
    }

    // Combine bytes into a 16-bit integer
    uint16_t raw_value = (buffer[0] << 8) | buffer[1];

    // Convert raw_value to milliamps (based on DFRobot specs)
    float current_mA = (raw_value / 65535.0) * 16.0 + 4.0;

    // Convert current_mA to water level in gallons
    float gallons = (current_mA - 4.0) * (500.0 / 16.0);

    // Publish the water level
    water_level_sensor->publish_state(gallons);
  }
};

}  // namespace df_current_sensor
}  // namespace esphome
