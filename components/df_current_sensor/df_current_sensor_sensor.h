#pragma once
#include "esphome/core/automation.h"
#include "esphome/components/sensor/sensor.h"
#include "df_current_sensor.h"

namespace esphome {
namespace df_current_sensor {

class DFCurrentSensorSensor : public sensor::Sensor, public Component {
 public:
  void setup() override {
    this->df_current_sensor_ = new DFCurrentSensor();
    this->df_current_sensor_->set_sensor(this);
    this->df_current_sensor_->setup();
  }

  void loop() override {
    this->df_current_sensor_->loop();
  }

  void update() override {
    this->df_current_sensor_->update();
  }

 private:
  DFCurrentSensor *df_current_sensor_;
};

}  // namespace df_current_sensor
}  // namespace esphome
