#ifndef ENGINE_H
#define ENGINE_H

#include "Cylinder.h"

#include <vector>

class Engine
{
public:
    explicit Engine(int numCyl);
    virtual ~Engine();

private:
    std::vector<Cylinder> m_cylinders;
};

#endif // ENGINE_H
