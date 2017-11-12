
#include "HostModule.hpp"

HostModule::HostModule() {}

HostModule::~HostModule() {}

HostModule::HostModule(HostModule const & src) { *this = src;}

HostModule & HostModule::operator=(HostModule const &)
{
	return (*this);
}

std::string HostModule::getHostName()
{
	FILE		*input;
	char		buffer[64];
	std::stringstream	result;

	if(!(input = popen("whoami", "r")))
		return ("Ups...I can't do this operation");
	while(fgets(buffer, sizeof(buffer), input))
		result << buffer;
	pclose(input);
	return result.str();
}

std::string HostModule::getHostName2()
{
	FILE		*input;
	char		buffer[64];
	std::stringstream	result;

	if(!(input = popen("hostname", "r")))
		return ("Ups...I can't do this operation");
	while(fgets(buffer, sizeof(buffer), input))
		result << buffer;
	pclose(input);
	return result.str();
}
