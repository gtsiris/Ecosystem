#include <iostream>
#include <cstdlib>
#include "class_Terrain.h"

using namespace std;

Terrain::Terrain(const unsigned int terrain_size) : terrainSize(terrain_size > 10 ? terrain_size : 10)
{
  tiles = new Tile*[terrainSize];
  for(unsigned int y = 1; y <= terrainSize; y++)
    tiles[y - 1] = new Tile[terrainSize];
  MapGenerator();
}

Terrain::~Terrain() {  /* Release the allocated memory that is not necessary anymore */
  for(unsigned int y = 1; y <= terrainSize; y++)
    delete [] tiles[y];
  delete [] tiles;
}

void Terrain::MapGenerator() {
  GenerateRiver();
  PrintMap();
  GenerateLake(rand() % 3 + 2);
  PrintMap();
  GenerateHills(2);
  PrintMap();
  GenerateMeadow();
}

void Terrain::GenerateRiver() {
  unsigned x = rand() % (terrainSize - 4);
  while (x < 5) {
    x = rand() % (terrainSize - 4);
  }
  for (unsigned int y = 1; y <= terrainSize; y++) {
    tiles[x - 1][y - 1].SetWater();
    if (rand() % 100 + 1 <= 30) {  /* Emulate 30% possibility */
      if (rand() % 2 == 0) {  /* River moves right */
        if (rand() % 2 == 0 && x < terrainSize) {  /* River moves one tile to the right */
          x++;
          tiles[x - 1][y - 1].SetWater();
        }
        else if (x < terrainSize - 1) {  /* River moves two tiles to the right */
          x += 2;
          tiles[x - 2][y - 1].SetWater();
          tiles[x - 1][y - 1].SetWater();
        }
      }
      else {  /* River moves left */
        if (rand() % 2 == 0 && x > 1) {  /* River moves one tile to the left */
          x--;
          tiles[x - 1][y - 1].SetWater();
        }
        else if (x > 2) {  /* River moves two tiles to the left */
          x -= 2;
          tiles[x][y - 1].SetWater();
          tiles[x - 1][y - 1].SetWater();
        }
      }
    }
  }
}

void Terrain::GenerateLake(const unsigned int lakeSize) {
  const unsigned int xInit = rand() % (terrainSize - lakeSize) + 1;
  const unsigned int X = xInit + lakeSize;
  unsigned int y = rand() % (terrainSize - lakeSize) + 1;
  const unsigned int Y = y + lakeSize;
  for (; y < Y; y++)
    for (unsigned int x = xInit; x < X; x++)
      tiles[x - 1][y - 1].SetWater();
}

void Terrain::GenerateHills(const unsigned int numberOfHills) {
  for (unsigned int hills = 1; hills <= numberOfHills; hills++) {
    const unsigned int hillSize = rand() % 3 + 2;
    const unsigned int xInit = rand() % (terrainSize - hillSize) + 1;
    const unsigned int X = xInit + hillSize;
    unsigned int y = rand() % (terrainSize - hillSize) + 1;
    const unsigned int Y = y + hillSize;
    for (; y < Y; y++)
      for (unsigned int x = xInit; x < X; x++)
        tiles[x - 1][y - 1].SetHill();
  }
}

void Terrain::GenerateMeadow() {
  for (unsigned int y = 1; y <= terrainSize; y++) {
    for (unsigned int x = 1; x <= terrainSize; x++) {
        tiles[x - 1][y - 1].SetMeadow();
    }
  }
}

void Terrain::PrintMap() const{
  for (unsigned int y = 1; y <= terrainSize; y++) {
    for (unsigned int x = 1; x <= terrainSize; x++) {
      tiles[x - 1][y - 1].PrintTile();
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;
}
