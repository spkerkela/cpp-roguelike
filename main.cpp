#include "main.h"

int max_width = 0;
int max_height = 0;

void init() {
  load_world("worlds/world1.world");
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  getmaxyx(stdscr, max_height, max_width);
  start_color();

  /* COLORS */
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
}

void cleanup() { endwin(); }

void erase(int y, int x) { mvaddch(y, x, ' '); }

void game_loop(Entity *player) {
  int ch = getch();
  clear();
  draw_world();
  draw_entity(player);

  for (;;) {
    ch = getch();
    if (ch == KEY_LEFT) {
      player->x -= 1;
    } else if (ch == KEY_RIGHT) {
      player->x += 1;
    } else if (ch == KEY_UP) {
      player->y -= 1;
    } else if (ch == KEY_DOWN) {
      player->y += 1;
    } else if (ch == 'q' || ch == 'Q') {
      break;
    }
    clear();
    draw_world();
    draw_entity(player);
  }
}

void draw_world() {
  attron(COLOR_PAIR(2));
  for (int x = 0; x < max_width; ++x) {
    for (int y = 0; y < max_height; ++y) {
      if (x % 2 == 0) {
        mvaddch(y, x, '#');
      }
    }
  }
}

int main() {
  init();
  Entity player(max_width / 2, max_height / 2, '@');
  printw("Welcome to roguelike!\nPress any key to start\nPress Q to quit\n");
  printw("max width: %d, max height: %d", max_width, max_height);
  game_loop(&player);
  cleanup();
  return 0;
}
