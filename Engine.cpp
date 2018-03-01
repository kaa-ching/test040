#include "Engine.h"

Engine::Engine(int numCyl)
{
    for (int i=0; i<numCyl; i++)
        m_cylinders.emplace_back(i);
}

Engine::~Engine()
{
}
