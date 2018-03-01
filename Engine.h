#ifndef ENGINE_H
#define ENGINE_H

#include "Cylinder.h"

#include <vector>

class Engine
{
public:
    explicit Engine(int numCyl);
    virtual ~Engine();

    void rotate(double rotations);
    double getRotations();

private:
    std::vector<Cylinder> m_cylinders;
    double m_rotations;
};

#endif // ENGINE_H
