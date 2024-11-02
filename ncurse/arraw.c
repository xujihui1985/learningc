#include <ncurses.h>

int main() {

  int key, x, y;
  initscr();
  keypad(stdscr, TRUE);
  noecho();

  x = y = 5;

  while (key != 'q') {

    clear();
    move(0, 0);
    printw("press left or right arrow");


    move(y, x);
    printw("O");
    refresh();

    key = getch();

    if (key == KEY_LEFT) {
      x--;
      if (x < 0)
        x = 0;
    } else if(key == KEY_RIGHT) {
      x++;
      if (x > 30)
        x = 30;
    }
  }

  getch();
  endwin();

  return 0;
}
