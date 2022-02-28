#ifndef class_Ecosystem_h
#define class_Ecosystem_h

#include "class_Terrain.h"

class Ecosystem {
  Terrain terrain;
  const unsigned short dayOfYear;
  
  public:
    Ecosystem(const unsigned int terrain_size, const unsigned int initial_day);
    
    void PrintEcosystem() const;
};

#endif
