from esphome.components.sensor import Sensor
from esphome.core import CORE

DEPENDENCIES = ["i2c"]

def setup_df_current_sensor(config):
    if CORE.has_component("i2c"):
        from .df_current_sensor_sensor import DFCurrentSensorSensor
        return DFCurrentSensorSensor()
    raise ValueError("I2C component is required for DF Current Sensor")
