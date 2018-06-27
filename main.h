#ifndef MAIN_H
#define MAIN_H

#include "entity.h"
#include "world.h"
#include <ncurses.h>

const int WIDTH = 100;
const int HEIGHT = 30;

void init();
void cleanup();
void erase(int y, int x);
void game_loop(Entity *entity);
void draw_world();

#endif
