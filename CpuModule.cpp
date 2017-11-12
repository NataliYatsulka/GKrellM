#include "CpuModule.hpp"

CpuModule::CpuModule() {}

CpuModule::CpuModule(CpuModule const &src) {
    *this = src;
}

CpuModule & CpuModule::operator=(CpuModule const &src) {
    (void)src;
    return *this;
}

CpuModule::~CpuModule() {}

std::string     CpuModule::getData() {
    FILE 				*file;
    char				buffer[80];
    std::stringstream	result;

    if(!(file = popen("system_profiler SPHardwareDataType", "r")))
        return "Something wrong!";
    while(fgets(buffer, sizeof(buffer), file))
        result << buffer;
    pclose(file);
    return result.str();
}
