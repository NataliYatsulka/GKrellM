#ifndef GRAPHICAL_HPP
# define GRAPHICAL_HPP

# include <string>
# include <SFML/Graphics.hpp>
# include "IMonitorDisplay.hpp"
# include "IMonitorDisplay.hpp"
# include "TimeModule.hpp"
# include "CpuModule.hpp"
# include "RawModule.hpp"
# include "HostModule.hpp"
# include "OsModule.hpp"

class   Graphical : public IMonitorDisplay {

public:

    Graphical();
    Graphical(Graphical const &);
    Graphical & operator=(Graphical const &);
    ~Graphical();

//    void    draw(sf::RenderWindow *, int);
    void    play();

private:
    TimeModule	    _module;
    CpuModule       _cpu;
    RawModule       _raw;
    HostModule      _host;
    OsModule        _os;
};

#endif