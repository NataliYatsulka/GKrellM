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

void    init_color(void)
{
    start_color();
    init_pair(0, 1, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, 2, COLOR_BLACK);
    init_pair(3, 3, COLOR_BLACK);
    init_pair(4, 4, COLOR_BLACK);
    init_pair(5, 5, COLOR_BLACK);
    init_pair(6, 6, COLOR_BLACK);
    init_pair(7, 7, COLOR_BLACK);
}

void    Display::play() {

    int     maxheight;
    int     maxwidth;
    int     y;
    int     x;
    int     rand_num = 0;
    int     c = 0;

    initscr();
    WINDOW * win = newwin(H, W, 0, 0);
    nodelay(stdscr, true);
    noecho();
    keypad(stdscr, true);
    init_color();

    while (c != 27)
    {
        c = getch();

        this->max_win(&maxheight, &maxwidth);

        getmaxyx(win, y, x);

        wclear(win);

        if (x < 122 || y < 22) {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 10, "Make the window bigger");
        } else {
            mvwprintw(win, 3, 10, this->_cpu.getCpu().c_str());
            rand_num = rand() % 8;
            wattron(win, COLOR_PAIR(rand_num));
            this->make_frame_option(win, 22, 60, 2, 2);
            wattroff(win, COLOR_PAIR(rand_num));
            mvwprintw(win, 3, 72, this->_module.getTimeModule().c_str());
            rand_num = rand() % 8;
            wattron(win, COLOR_PAIR(rand_num));
            this->make_frame_option(win, 5, 120, 2, 62);
            wattroff(win, COLOR_PAIR(rand_num));
            mvwprintw(win, 7, 68, this->_raw.getRaw().c_str());
            rand_num = rand() % 8;
            wattron(win, COLOR_PAIR(rand_num));
            this->make_frame_option(win, 9, 120, 6, 62);
            wattroff(win, COLOR_PAIR(rand_num));
            mvwprintw(win, 11, 80, "USERNAME: ");
            mvwprintw(win, 11, 90, this->_host.getUserName().c_str());
            mvwprintw(win, 13, 76, "HOSTNAME: ");
            mvwprintw(win, 13, 86, this->_host.getHostName2().c_str());
            rand_num = rand() % 8;
            wattron(win, COLOR_PAIR(rand_num));
            this->make_frame_option(win, 15, 120, 10, 62);
            wattroff(win, COLOR_PAIR(rand_num));
            mvwprintw(win, 17, 68, "OS info: ");
            mvwprintw(win, 18, 72, this->_os.getOsModuleKernel().c_str());
            mvwprintw(win, 19, 72, this->_os.getOsModuleSysVersion().c_str());
            mvwprintw(win, 20, 72, this->_os.getOsModuleBootVolume().c_str());
            rand_num = rand() % 8;
            wattron(win, COLOR_PAIR(rand_num));
            this->make_frame_option(win, 22, 120, 16, 62);
            wattroff(win, COLOR_PAIR(rand_num));
        }

        if (x < 26 || y < 5)
        {
            wclear(win);
            mvwprintw(win, y/2, x/2 - 1, "DUDE");
        }
        rand_num = rand() % 8;
        wattron(win, COLOR_PAIR(rand_num));
        this->make_frame(win, maxheight, maxwidth);

        usleep(10000);
        refresh();
        wrefresh(win);

    }
    endwin();
}