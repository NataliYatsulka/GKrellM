#include "TimeModule.hpp"
#include "CpuModule.hpp"
#include "RawModule.hpp"
#include <unistd.h>
#include <ncurses.h>

#define H 80
#define W 250

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

void    make_frame_option(WINDOW * win, int height, int width, int startH, int startW)
{
    for (int i = startW; i < width; i++)
    {
        wmove(win, startH, i);
        waddch(win, '*');
    }

    for (int i = startH; i < height; i++)
    {
        wmove(win, i, startW);
        waddch(win, '*');
    }
    for (int i = startW; i < width; i++)
    {
        wmove(win, height - 1, i);
        waddch(win, '*');
    }
    for (int i = startH; i < height; i++)
    {
        wmove(win, i, width - 1);
        waddch(win, '*');
    }
}

void    make_frame(WINDOW * win, int height, int width)
{
    for (int i = 0; i < width; i++)
    {
        wmove(win, 0, i);
        waddch(win, '*');
    }

    for (int i = 0; i < height; i++)
    {
        wmove(win, i, 0);
        waddch(win, '*');
    }
    for (int i = 0; i < width; i++)
    {
        wmove(win, height-1, i);
        waddch(win, '*');
    }
    for (int i = 0; i < height; i++)
    {
        wmove(win, i, width - 1);
        waddch(win, '*');
    }
}

int     main()
{
    int     maxheight;
    int     maxwidth;
    int     c = 0;

	TimeModule	module;
    CpuModule   cpu;
    RawModule   raw;

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

        mvwprintw(win, 3, 10, cpu.getData().c_str());
        make_frame_option(win, 22, 60, 2, 2);
		mvwprintw(win, 3, 73, module.getTimeModule().c_str());
        make_frame_option(win, 5, 120, 2, 61);
        mvwprintw(win, 15, 73, raw.getData().c_str());
        make_frame_option(win, 15, 120, 2, 61);
        make_frame(win, maxheight, maxwidth);

        usleep(10000);
        refresh();
        wrefresh(win);

    }
    endwin();
    return 0;
}
