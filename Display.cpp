#include "Display.hpp"

Display::Display() {}
Display::Display(Display const &src) {
    *this = src;
}
Display &   Display::operator=(Display const &src) {
    (void)src;
    return *this;
}
Display::~Display() {}

void    Display::make_frame_option(WINDOW * win, int height, int width, int startH, int startW)
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

void    Display::make_frame(WINDOW * win, int height, int width)
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

void    Display::max_win(int *maxheight, int *maxwidth)
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

void    Display::play() {

    int     maxheight;
    int     maxwidth;
    int     y;
    int     x;
    int     c = 0;

    initscr();
    WINDOW * win = newwin(H, W, 0, 0);
    nodelay(stdscr, true);
    noecho();
    keypad(stdscr, true);

    while (c != 27)
    {
        c = getch();

        this->max_win(&maxheight, &maxwidth);
        getmaxyx(win, y, x);
        wclear(win);
        if (x < 60 || y < 22) {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 10, "Make the window bigger");
        } else {
            mvwprintw(win, 3, 10, this->_cpu.getData().c_str());
            this->make_frame_option(win, 22, 60, 2, 2);
        }
        if (x < 122 || y < 5) {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 10, "Make the window bigger");
        } else {
            mvwprintw(win, 3, 72, this->_module.getTimeModule().c_str());
            this->make_frame_option(win, 5, 120, 2, 62);
        }
        if (x < 122 || y < 11) {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 10, "Make the window bigger");
        } else {
            mvwprintw(win, 8, 68, this->_raw.getData().c_str());
            this->make_frame_option(win, 11, 120, 6, 62);
        }
        if (x < 122 || y < 19) {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 10, "Make the window bigger");
        } else {
            mvwprintw(win, 14, 80, "USERNAME: ");
            mvwprintw(win, 14, 90, this->_host.getHostName().c_str());
            mvwprintw(win, 16, 76, "HOSTNAME: ");
            mvwprintw(win, 16, 86, this->_host.getHostName2().c_str());
            this->make_frame_option(win, 19, 120, 12, 62);
        }
        if (x < 26 || y < 5)
        {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 1, "DUDE");
        }
        this->make_frame(win, maxheight, maxwidth);

        usleep(10000);
        refresh();
        wrefresh(win);

    }
    endwin();
}