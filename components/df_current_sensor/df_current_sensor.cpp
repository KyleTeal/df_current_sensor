#pragma once
#include "esphome.h"

namespace esphome {
namespace df_current_sensor {

class DFCurrentSensor : public PollingComponent, public i2c::I2CDevice {
 public:
  DFCurrentSensor() : PollingComponent(1000) {}
  Sensor *water_level_sensor = new Sensor();

  void setup() override;
  void update() override;
};

}  // namespace df_current_sensor
}  // namespace esphome
