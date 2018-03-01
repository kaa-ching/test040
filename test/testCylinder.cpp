#include "Cylinder.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::Invoke;

TEST(Cylinder, Test_Cylinder_Creation)
{
    EXPECT_NO_THROW(Cylinder myCylinder(1));
}

TEST(Cylinder, Test_Cylinder_StartPhase)
{
    Cylinder myCylinder0(0);
    EXPECT_EQ(myCylinder0.getStroke(), Cylinder::Stroke::INTAKE);

    Cylinder myCylinder1(1);
    EXPECT_EQ(myCylinder1.getStroke(), Cylinder::Stroke::COMPRESSION);

    Cylinder myCylinder2(2);
    EXPECT_EQ(myCylinder2.getStroke(), Cylinder::Stroke::COMBUSTION);

    Cylinder myCylinder3(3);
    EXPECT_EQ(myCylinder3.getStroke(), Cylinder::Stroke::EXHAUST);

    Cylinder myCylinder7(3);
    EXPECT_EQ(myCylinder7.getStroke(), Cylinder::Stroke::EXHAUST);
}
