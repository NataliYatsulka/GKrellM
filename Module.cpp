#include "Module.hpp"

Module::Module(std::string name) : _name(name) {}

Module::Module(Module const &rhs, std::string name) : _name(name) {
    *this = rhs;
}

Module &    Module::operator=(Module const &rhs) {
    (void)rhs;
    return *this;
}

std::string     Module::getName() {
    return this->_name;
}