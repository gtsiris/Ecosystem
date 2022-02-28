#include "class_Ecosystem.h"

Ecosystem::Ecosystem(const unsigned int terrain_size, const unsigned int initial_day) :
terrain(terrain_size), dayOfYear((initial_day != 0 && initial_day <= 365) ? initial_day : 1)
{}

void Ecosystem::PrintEcosystem() const {
  terrain.PrintMap();
}


