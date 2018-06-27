#include "entity.h"

void draw_entity(Entity *entity) {
  attron(COLOR_PAIR(1));
  mvaddch(entity->y, entity->x, entity->c);
  attroff(COLOR_PAIR(1));
}
