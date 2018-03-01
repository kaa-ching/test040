#include "Cylinder.h"

Cylinder::Cylinder(int cylPos)
    : m_cylinderPosition(cylPos)
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
