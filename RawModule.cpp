#include "RawModule.hpp"

RawModule::RawModule() {}

RawModule::RawModule(RawModule const &src) {
    *this = src;
}

RawModule & RawModule::operator=(RawModule const &src) {
    (void)src;
    return *this;
}

RawModule::~RawModule() {}

std::string RawModule::getData() {
    FILE 				*file;
    char				buffer[80];
    std::stringstream	result;

    if(!(file = popen("top -l 1 | head -n 10 | grep PhysMem", "r")))
        return "Something wrong!";
    while(fgets(buffer, sizeof(buffer), file))
        result << buffer;
    pclose(file);
    return result.str();
}