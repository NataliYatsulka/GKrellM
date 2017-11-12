#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include <string>
# include <sstream>

class   CpuModule {

public:
    CpuModule();
    CpuModule(CpuModule const &);
    CpuModule & operator=(CpuModule const &);
    ~CpuModule();

    std::string     getData();

};

#endif