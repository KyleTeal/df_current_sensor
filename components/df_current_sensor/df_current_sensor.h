#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace df_current_sensor {

class DFCurrentSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  DFCurrentSensor() : PollingComponent(1000) {}
  void set_sensor(sensor::Sensor *sensor) { this->sensor_ = sensor; }

  void setup() override {
    ESP_LOGCONFIG("DFCurrentSensor", "Setting up DF Current Sensor...");
  }

  void update() override {
    uint8_t buffer[2];
    if (!this->read_bytes(buffer, 2)) {
      ESP_LOGE("DFCurrentSensor", "Failed to read from sensor!");
      return;
    }

    uint16_t raw_value = (buffer[0] << 8) | buffer[1];
    float current_mA = (raw_value / 65535.0) * 16.0 + 4.0;
    float gallons = (current_mA - 4.0) * (500.0 / 16.0);
    this->sensor_->publish_state(gallons);
  }

 protected:
  sensor::Sensor *sensor_;
};

}  // namespace df_current_sensor
}  // namespace esphome
