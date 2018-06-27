#ifndef WORLD_H
#define WORLD_H

class Tile {
  char c;
};

class World {
public:
  int width;
  int height;
  struct Tile tiles[];
  World(int widht, int height);
};

#endif
