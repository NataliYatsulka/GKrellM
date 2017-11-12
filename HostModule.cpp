
#include "HostModule.hpp"

HostModule::HostModule() {}

HostModule::~HostModule() {}

HostModule::HostModule(HostModule const & src) { *this = src;}

HostModule & HostModule::operator=(HostModule const & src)
{
	return (*this);
}

std::string getHostModule()
{
	
}
