#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "vcnl4040.hpp"

TEST_GROUP(VCNL4040Tests)
{
};

TEST(VCNL4040Tests, SetAlsConfigWritesToCorrectRegister)
{
    FakeI2CDevice fake_device;
    VCNL4040Sensor sensor(&fake_device);

    sensor.set_als_config(0x01);

    CHECK_EQUAL(0x00, fake_device.last_register_address);
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
