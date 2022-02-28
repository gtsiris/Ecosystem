#include <iostream>
#include "class_Tile.h"

using namespace std;

Tile::Tile() : environmentType('0'), plantCounter(0), animalCounter(0)  /* Ascii number of O represents the undefiened environment type */
{}

const bool Tile::IsUndefiened() const {
  return (environmentType == '0');  /* If environment type is '0', then it is undefiened */
}

void Tile::SetWater() {
  if (IsUndefiened())
    environmentType = '#';  /* Ascii number of # represents water-type environment */
}
    
void Tile::SetHill() {
  if (IsUndefiened())
    environmentType = '^';  /* Ascii number of ^ represents hill-type environment */
}

void Tile::SetMeadow() {
  if (IsUndefiened())
    environmentType = '"';  /* Ascii number of " represents meadow-type environment */
}

void Tile::PrintTile() const {
  cout << environmentType;
}
