#ifndef RAWMODULE_HPP
# define RAWMODULE_HPP

# include "Module.hpp"

class   RawModule : public Module {

public:
    RawModule();
    RawModule(RawModule const &);
    RawModule & operator=(RawModule const &);
    ~RawModule();

    std::string     getRaw();
};

#endif