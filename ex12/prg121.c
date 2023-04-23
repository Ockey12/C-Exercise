#include <curses.h>
#include <unistd.h> // sleep利用するため

int main()
{
  char c='A';
  int  gyou=5, retsu=10, wait=5;

  initscr(); // 画面制御開始

  move(gyou,retsu);  //５行１０列に移動
  addch(c);  // 画面制御用の１文字出力
  refresh();  // 書き込んだものを画面に表示

  sleep(wait);  // 停止

  endwin(); // 画面制御終了
  return 0;
}
