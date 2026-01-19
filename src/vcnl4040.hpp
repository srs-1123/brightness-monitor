#pragma once
#include <cstdint>

class FakeI2CDevice {
public:
    uint8_t last_register_address = 0xFF;
};

class VCNL4040Sensor {
public:
    VCNL4040Sensor(FakeI2CDevice* device) : device_(device) {}

    void set_als_config(uint8_t /*cmd*/) {
        device_->last_register_address = 0x00;
    }

private:
    FakeI2CDevice* device_;
};
