#include "RawModule.hpp"

RawModule::RawModule() : Module() {}

RawModule::RawModule(RawModule const &src) {
    *this = src;
}

RawModule & RawModule::operator=(RawModule const &src) {
    (void)src;
    return *this;
}

RawModule::~RawModule() {}

std::string RawModule::getRaw() {
    std::stringstream	data;

    if(!(this->_file = popen("top -l 1 | head -n 10 | grep PhysMem", "r")))
        return "Something wrong!";
    while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
        data << this->_buffer;
    pclose(this->_file);
    return data.str();
}