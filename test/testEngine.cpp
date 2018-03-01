#include "Engine.h"
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

// TEST(Engine, Test_Engine_Rotation)
// {
//     Engine myEngine(4);
//     EXPECT_NO_THROW(myEngine.rotate(0.5));
//     EXPECT_DOUBLE_EQ(myEngine.getRotations(), 0.5);
// }
