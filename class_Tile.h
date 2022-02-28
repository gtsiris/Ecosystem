#ifndef class_Tile_h
#define class_Tile_h

class Tile {
  unsigned char environmentType;
  unsigned int plantCounter;
  unsigned int animalCounter;
  
  public:
    Tile();
    
    const bool IsUndefiened() const;
    
    void SetWater();
    
    void SetHill();
    
    void SetMeadow();
    
    void PrintTile() const;
};

#endif
