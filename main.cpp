
#include <iostream>
#include <unistd.h>
#include <ncurses.h>

#define H 80
#define W 80

void    max_win(int *maxheight, int *maxwidth)
{
    int     t_maxh;
    int     t_maxw;

    getmaxyx(stdscr, t_maxh, t_maxw);

    if (t_maxh < H)
        *maxheight = t_maxh;
    else
        *maxheight = H;

    if (t_maxw < W)
        *maxwidth = t_maxw;
    else
        *maxwidth = W;
}

void    make_clean_win(WINDOW *win, int maxheight, int maxwidth, char clean)
{
    for (int i = 0; i < maxheight; ++i)
    {
        for (int j = 0; j < maxwidth; ++j)
        {
            mvwaddch(win, i, j, clean);
        }
    }
}

void    make_frame(WINDOW * win, int maxheight, int maxwidth, char oldalchar)
{
    for (int i = 0; i < maxwidth; i++)
    {
        wmove(win, 0, i);
        waddch(win, oldalchar);
    }

    for (int i = 0; i < maxheight; i++)
    {
        wmove(win, i, 0);
        waddch(win, oldalchar);
    }
    for (int i = 0; i < maxwidth; i++)
    {
        wmove(win, maxheight-1,i);
        waddch(win, oldalchar);
    }
    for (int i = 0; i < maxheight; i++)
    {
        wmove(win, i, maxwidth - 1);
        waddch(win, oldalchar);
    }
}

int     main()
{
    int     maxheight;
    int     maxwidth;
    int     c = 0;

    initscr();
    WINDOW * win = newwin(H, W, 0, 0);
    nodelay(stdscr, true);
    noecho();
    keypad(stdscr, true);

    while (c != 27)
    {
        c = getch();

        max_win(&maxheight, &maxwidth);

        make_clean_win(win, maxheight, maxwidth, ' ');


        usleep(10000);
        refresh();
        wrefresh(win);

    }
    endwin();
    return 0;
}
