#ifndef RAWMODULE_HPP
# define RAWMODULE_HPP

# include <string>
# include <sstream>

class   RawModule {

public:
    RawModule();
    RawModule(RawModule const &);
    RawModule & operator=(RawModule const &);
    ~RawModule();

    std::string     getData();

};

#endif