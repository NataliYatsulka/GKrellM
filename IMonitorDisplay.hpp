#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class   IMonitorDisplay {

public:
    virtual void    init() = 0;
    virtual void    play() = 0;
    virtual void    exit() = 0;
    virtual ~IMonitorDisplay() = 0;

};

#endif