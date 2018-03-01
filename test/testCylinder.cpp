#include "Cylinder.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::_;
using ::testing::NiceMock;
using ::testing::StrictMock;
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

class MockSparkPlug : public SparkPlug
{
public:
    MOCK_METHOD0(Spark, void());
};

template <class IntakeType, class ExhaustType, class SparkType>
class CylinderTest : public ::testing::Test
{
public:
    CylinderTest()
    {
        auto pSpark = std::make_unique<SparkType>();
        m_pSpark = pSpark.get();
        m_cylinder = std::make_unique<Cylinder>(0, m_intake, m_exhaust, std::move (pSpark));
    }

    SparkType* m_pSpark;
    IntakeType m_intake;
    ExhaustType m_exhaust;
    std::unique_ptr<Cylinder> m_cylinder;
};

using CylinderTestNice = CylinderTest<NiceMock<MockIntake>, NiceMock<MockExhaust>, NiceMock<MockSparkPlug>>;
using CylinderTestStrict = CylinderTest<StrictMock<MockIntake>, StrictMock<MockExhaust>, NiceMock<MockSparkPlug>>;
using CylinderTestSpark = CylinderTest<NiceMock<MockIntake>, NiceMock<MockExhaust>, StrictMock<MockSparkPlug>>;

TEST_F(CylinderTestNice, Test_Cylinder_StartPhase)
{
    EXPECT_EQ(m_cylinder->getStroke(), Cylinder::Stroke::INTAKE);

    Cylinder myCylinder1(1, m_intake, m_exhaust, std::make_unique<SparkPlug>());
    EXPECT_EQ(myCylinder1.getStroke(), Cylinder::Stroke::COMPRESSION);

    Cylinder myCylinder2(2, m_intake, m_exhaust, std::make_unique<SparkPlug>());
    EXPECT_EQ(myCylinder2.getStroke(), Cylinder::Stroke::COMBUSTION);

    Cylinder myCylinder3(3, m_intake, m_exhaust, std::make_unique<SparkPlug>());
    EXPECT_EQ(myCylinder3.getStroke(), Cylinder::Stroke::EXHAUST);

    Cylinder myCylinder7(3, m_intake, m_exhaust, std::make_unique<SparkPlug>());
    EXPECT_EQ(myCylinder7.getStroke(), Cylinder::Stroke::EXHAUST);
}

TEST_F(CylinderTestNice, Test_Cylinder_Rotate)
{
    EXPECT_EQ(m_cylinder->getStroke(), Cylinder::Stroke::INTAKE);
    m_cylinder->rotate();
    EXPECT_EQ(m_cylinder->getStroke(), Cylinder::Stroke::COMPRESSION);
    m_cylinder->rotate();
    EXPECT_EQ(m_cylinder->getStroke(), Cylinder::Stroke::COMBUSTION);
    m_cylinder->rotate();
    EXPECT_EQ(m_cylinder->getStroke(), Cylinder::Stroke::EXHAUST);
    m_cylinder->rotate();
    EXPECT_EQ(m_cylinder->getStroke(), Cylinder::Stroke::INTAKE);
}

TEST_F(CylinderTestStrict, Test_Cylinder_ChangeIntake)
{
    EXPECT_CALL(m_intake, CloseIntake(0));
    m_cylinder->rotate();
}

TEST_F(CylinderTestStrict, Test_Cylinder_ChangeExhaust)
{
    Cylinder myCylinder3(3, m_intake, m_exhaust, std::make_unique<NiceMock<MockSparkPlug>>());

    EXPECT_CALL(m_intake, OpenIntake(_));
    EXPECT_CALL(m_exhaust, CloseExhaust(3));
    myCylinder3.rotate();
}

TEST_F(CylinderTestSpark, Test_Cylinder_FireSparkPlug)
{
    m_cylinder->rotate();
    EXPECT_CALL(*m_pSpark, Spark());
    m_cylinder->rotate();
    m_cylinder->rotate();
}
