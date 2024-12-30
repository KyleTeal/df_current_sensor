from esphome.components.sensor import Sensor
from esphome.const import CONF_NAME
import esphome.config_validation as cv
from esphome import automation
from esphome.core import CORE, Component

DEPENDENCIES = ["i2c"]

CONF_UNIT_OF_MEASUREMENT = "unit_of_measurement"
CONF_ACCURACY_DECIMALS = "accuracy_decimals"
CONF_UPDATE_INTERVAL = "update_interval"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(Sensor),
        cv.Required(CONF_NAME): cv.string,
        cv.Optional(CONF_UNIT_OF_MEASUREMENT, default=""): cv.string,
        cv.Optional(CONF_ACCURACY_DECIMALS, default=2): cv.int_,
        cv.Optional(CONF_UPDATE_INTERVAL, default="60s"): cv.update_interval,
    }
).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = await automation.new_component(Sensor, config)
    Component.new_component(var)
