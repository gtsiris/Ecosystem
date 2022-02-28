#ifndef class_Terrain_h
#define class_Terrain_h

#include "class_Tile.h"

class Terrain {
  const unsigned int terrainSize;
  Tile** tiles;
  
  public:
    Terrain(const unsigned int terrain_size);
    
    ~Terrain();
    
    void MapGenerator();
    
    void GenerateRiver();
    
    void GenerateLake(const unsigned int lakeSize);
    
    void GenerateHills(const unsigned int numberOfHills);
    
    void GenerateMeadow();
    
    void PrintMap() const;
};

#endif
