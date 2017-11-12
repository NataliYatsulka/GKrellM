#ifndef MODULE_HPP
# define MODULE_HPP

# include "IMonitorModule.hpp"

# include <string>
# include <sstream>

class   Module : public IMonitorModule{

public:
    Module();
    Module(Module const &);
    Module &  operator=(Module const &);
    virtual ~Module();


protected:
    FILE 				*_file;
    char				_buffer[80];

};

#endif