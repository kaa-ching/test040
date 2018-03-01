#ifndef CYLINDER_H
#define CYLINDER_H

#include "IntakeItf.h"
#include "ExhaustItf.h"
#include "SparkPlug.h"

#include <memory>

class Cylinder
{
public:
    Cylinder(int cylPos, IntakeItf& intake, ExhaustItf& exhaust, std::unique_ptr<SparkPlug> sparkPlug);
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
    
    std::unique_ptr<SparkPlug> m_sparkPlug;
};

#endif // ENGINE_H
