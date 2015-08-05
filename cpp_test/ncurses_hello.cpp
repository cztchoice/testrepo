#include <ncurses.h>

int main()
{
    int ch;

    initscr();                 /* Start curses mode     */
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printw("Type any characer to see it in bold!"); 
    ch = getch();

    if(ch == KEY_F(1))
        printw("F1 Key pressed!");
    else{
        printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
    }
    refresh();                 /* Print it on to the real screen */
    getch();                   /* Wait for user input */

    mvprintw(10, 10, "Hello czt!!");
    refresh();
    getch();
    endwin();                  /* End curses mode    */

    return 0;
}
