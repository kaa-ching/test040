#include "Cylinder.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::Invoke;

class MockIntake : public IntakeItf
{
public:
    MOCK_METHOD1(OpenIntake, void(int nr));
    MOCK_METHOD1(CloseIntake, void(int nr));
};

class MockExhaust : public ExhaustItf
{
public:
    MOCK_METHOD1(OpenExhaust, void(int nr));
    MOCK_METHOD1(CloseExhaust, void(int nr));
};

class CylinderTest : public ::testing::Test
{
public:
    CylinderTest()
        : m_cylinder(0, m_intake, m_exhaust)
    {
    }
    
    MockIntake m_intake;
    MockExhaust m_exhaust;
    Cylinder m_cylinder;
};


TEST_F(CylinderTest, Test_Cylinder_StartPhase)
{
    EXPECT_EQ(m_cylinder.getStroke(), Cylinder::Stroke::INTAKE);

    Cylinder myCylinder1(1, m_intake, m_exhaust);
    EXPECT_EQ(myCylinder1.getStroke(), Cylinder::Stroke::COMPRESSION);

    Cylinder myCylinder2(2, m_intake, m_exhaust);
    EXPECT_EQ(myCylinder2.getStroke(), Cylinder::Stroke::COMBUSTION);

    Cylinder myCylinder3(3, m_intake, m_exhaust);
    EXPECT_EQ(myCylinder3.getStroke(), Cylinder::Stroke::EXHAUST);

    Cylinder myCylinder7(3, m_intake, m_exhaust);
    EXPECT_EQ(myCylinder7.getStroke(), Cylinder::Stroke::EXHAUST);
}

TEST_F(CylinderTest, Test_Cylinder_Rotate)
{
    EXPECT_EQ(m_cylinder.getStroke(), Cylinder::Stroke::INTAKE);
    m_cylinder.rotate();
    EXPECT_EQ(m_cylinder.getStroke(), Cylinder::Stroke::COMPRESSION);
    m_cylinder.rotate();
    EXPECT_EQ(m_cylinder.getStroke(), Cylinder::Stroke::COMBUSTION);
    m_cylinder.rotate();
    EXPECT_EQ(m_cylinder.getStroke(), Cylinder::Stroke::EXHAUST);
    m_cylinder.rotate();
    EXPECT_EQ(m_cylinder.getStroke(), Cylinder::Stroke::INTAKE);
}

TEST_F(CylinderTest, Test_Cylinder_ChangeIntake)
{
    EXPECT_CALL(m_intake, CloseIntake(0));
    m_cylinder.rotate();
}
