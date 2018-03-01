#include "Cylinder.h"

Cylinder::Cylinder(int cylPos, IntakeItf& intake, ExhaustItf& exhaust)
    : m_cylinderPosition(cylPos)
    , m_intake(intake)
    , m_exhaust(exhaust)
{
    m_stroke = static_cast<Stroke>(m_cylinderPosition%4);
}

Cylinder::~Cylinder()
{
}

Cylinder::Stroke Cylinder::getStroke()
{
    return m_stroke;
}

void Cylinder::rotate()
{
    switch(m_stroke)
    {
        case Stroke::INTAKE:
            m_stroke = Stroke::COMPRESSION;
            m_intake.CloseIntake(m_cylinderPosition);
            break;
        case Stroke::COMPRESSION:
            m_stroke = Stroke::COMBUSTION;
            break;
        case Stroke::COMBUSTION:
            m_stroke = Stroke::EXHAUST;
            m_exhaust.OpenExhaust(m_cylinderPosition);
            break;
        case Stroke::EXHAUST:
            m_stroke = Stroke::INTAKE;
            m_exhaust.CloseExhaust(m_cylinderPosition);
            m_intake.OpenIntake(m_cylinderPosition);
            break;
    }
}
