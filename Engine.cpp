#include "Engine.h"

Engine::Engine(int numCyl)
{
    for (int i=0; i<numCyl; i++)
        m_cylinders.emplace_back(i, *this, *this);
}

Engine::~Engine()
{
}

void Engine::rotate(double /*rotations*/)
{
//     while (m_rotations < )
//     {
//         for (auto& c : m_cylinders)
//         {
//             c.rotate(0.5);
//         }
//     }
}

double getRotations()
{
    return 0.0;
}
