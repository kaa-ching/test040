#include "Cylinder.h"

Cylinder::Cylinder(int cylPos)
    : m_cylinderPosition(cylPos)
{
}

Cylinder::~Cylinder()
{
}

Cylinder::Stroke Cylinder::getStroke()
{
    return Stroke::INTAKE;
}
