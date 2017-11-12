#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "Module.hpp"

class   CpuModule : public Module {

public:
    CpuModule();
    CpuModule(CpuModule const &);
    CpuModule & operator=(CpuModule const &);
    ~CpuModule();

    std::string     getCpu();

};

#endif