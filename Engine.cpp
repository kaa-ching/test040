#include "Engine.h"

Engine::Engine(int numCyl)
{
    for (int i=0; i<numCyl; i++)
        m_cylinders.emplace_back(std::make_unique<Cylinder>(i, *this, *this, std::move(std::make_unique<SparkPlug>())));
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
