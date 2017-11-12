#include "CpuModule.hpp"

CpuModule::CpuModule() : Module() {}

CpuModule::CpuModule(CpuModule const &src) {
    *this = src;
}

CpuModule & CpuModule::operator=(CpuModule const &src) {
    (void)src;
    return *this;
}

CpuModule::~CpuModule() {}

std::string     CpuModule::getCpu() {
    std::stringstream	data;

    if(!(this->_file = popen("system_profiler SPHardwareDataType", "r")))
        return "Something wrong!";
    while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
        data << this->_buffer;
    pclose(this->_file);
    return data.str();
}
