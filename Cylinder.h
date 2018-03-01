#ifndef CYLINDER_H
#define CYLINDER_H

class Cylinder
{
public:
    explicit Cylinder(int cylPos);
    virtual ~Cylinder();
    
    enum class Stroke
    {
        INTAKE,
        COMPRESSION,
        COMBUSTION,
        EXHAUST
    };
    
    Stroke getStroke();

private:
    int m_cylinderPosition;
    
    Stroke m_stroke;
};

#endif // ENGINE_H
