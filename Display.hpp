#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# define Hi 80
# define Wi 250

# include <ncurses.h>
# include <unistd.h>

# include "IMonitorDisplay.hpp"
# include "TimeModule.hpp"
# include "CpuModule.hpp"
# include "RawModule.hpp"
# include "HostModule.hpp"
# include "OsModule.hpp"

class   Display : public IMonitorDisplay {

public:

    Display();
    Display(Display const &);
    Display &   operator=(Display const &);
    ~Display();

    void    play();
    void    max_win(int *, int *);
    void    make_frame_option(WINDOW *, int, int, int, int);
    void    make_frame(WINDOW *, int, int);

private:
    TimeModule	    _module;
    CpuModule       _cpu;
    RawModule       _raw;
    HostModule      _host;
    OsModule        _os;
};

#endif