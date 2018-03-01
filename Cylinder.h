#ifndef CYLINDER_H
#define CYLINDER_H

class Cylinder
{
public:
    explicit Cylinder(int cylNum);
    virtual ~Cylinder();

private:
    int m_cylinderNumber;
};

#endif // ENGINE_H
