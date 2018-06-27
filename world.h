#ifndef WORLD_H
#define WORLD_H
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

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

World *load_world(std::string fileName);

#endif
