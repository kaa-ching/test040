#ifndef CYLINDER_H
#define CYLINDER_H

#include "IntakeItf.h"
#include "ExhaustItf.h"

class Cylinder
{
public:
    explicit Cylinder(int cylPos, IntakeItf& intake, ExhaustItf& exhaust);
    virtual ~Cylinder();
    
    enum class Stroke
    {
        INTAKE,
        COMPRESSION,
        COMBUSTION,
        EXHAUST
    };
    
    Stroke getStroke();
    
    void rotate();

private:
    int m_cylinderPosition;
    
    Stroke m_stroke;
    
    IntakeItf& m_intake;
    ExhaustItf& m_exhaust;
};

#endif // ENGINE_H
