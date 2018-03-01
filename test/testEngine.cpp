#include "Engine.h"
#include "mockInjection.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::Invoke;

TEST(Engine, Test_Engine_Creation)
{
    EXPECT_NO_THROW(Engine myEngine(4));
}
