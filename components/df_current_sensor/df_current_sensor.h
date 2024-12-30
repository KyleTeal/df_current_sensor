#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace df_current_sensor {

class DFCurrentSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  DFCurrentSensor() : PollingComponent(1000) {}
  sensor::Sensor *water_level_sensor = new sensor::Sensor();

  void setup() override;
  void update() override;
};

}  // namespace df_current_sensor
}  // namespace esphome
