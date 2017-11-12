#include "Module.hpp"

Module::Module() {}

Module::Module(Module const &src) {
    *this = src;
}

Module &    Module::operator=(Module const &src) {
    (void)src;
    return *this;
}

Module::~Module() {}