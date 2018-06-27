#include "world.h"

World::World(int width, int height) {
  this->width = width;
  this->height = height;
};

World *load_world(std::string fileName) {
  std::ifstream ifs(fileName);
  std::ifstream ifs2(fileName);
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()));
  std::size_t height = std::count(std::istreambuf_iterator<char>(ifs2),
                                  std::istreambuf_iterator<char>(), '\n');
  std::size_t width = content.find_first_of("\n");
  printf("%lu, %lu\n", width, height);

  printf("%s\n", content.c_str());
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));


  World *world = new World(width, height);

  return world;
};
