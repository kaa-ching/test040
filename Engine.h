#ifndef ENGINE_H
#define ENGINE_H

#include "Cylinder.h"
#include "IntakeItf.h"
#include "ExhaustItf.h"

#include <vector>

class Engine : public IntakeItf, public ExhaustItf
{
public:
    explicit Engine(int numCyl);
    virtual ~Engine();

    void rotate(double rotations);
    double getRotations();

private:
    std::vector<std::unique_ptr<Cylinder>> m_cylinders;
    double m_rotations;
};

#endif // ENGINE_H
