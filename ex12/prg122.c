#include <curses.h>
#include <unistd.h>

int main()
{
  int row=0, col=0;
  int row_max, col_max;
  int wait_interval=1, wait_last=5;
  char c='A';
  int i;

  initscr();  // 画面制御開始
  curs_set(0);              // カーソルの表示をしない 1:カーソルの表示をする

  //getmaxyx( stdscr, row_max, col_max);  // 画面の大きさの取得

  for( i=0; i<10; i++) {
    move( row, col );  // カーソルを移動
    addch(c);  // 文字を書く
    refresh();  // 画面を更新
    sleep(wait_interval);  // 少し待つ
    ++row;
    ++col;
  } 

  sleep( wait_last);  // しばらく待つ

  endwin();  // 画面制御の終了
  return 0;
}
