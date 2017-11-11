#ifndef MODULE_HPP
# define MODULE_HPP

# include "IMonitorModule.hpp"

class   Module : public IMonitorModule{

public:
    Module(std::string);
    Module(Module const &, std::string);
    Module &  operator=(Module const &);
    virtual ~Module();

    std::string     getName();

private:
    std::string     _name;

};

#endif