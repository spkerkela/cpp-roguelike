#ifndef ENTITY_H
#define ENTITY_H

#include <ncurses.h>

class Entity {
public:
  int x;
  int y;
  char c;
  Entity(int x, int y, char c) : x(x), y(y), c(c){};
};

void draw_entity(Entity *entity);

#endif
