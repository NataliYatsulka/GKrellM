
#include "HostModule.hpp"

HostModule::HostModule() : Module() {}

HostModule::~HostModule() {}

HostModule::HostModule(HostModule const & src) { *this = src;}

HostModule & HostModule::operator=(HostModule const &)
{
	return (*this);
}

std::string HostModule::getUserName()
{
	std::stringstream	data;

	if(!(this->_file = popen("whoami", "r")))
		return ("Ups...I can't do this operation");
	while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
		data << this->_buffer;
	pclose(this->_file);
	return data.str();
}

std::string HostModule::getHostName2()
{
	std::stringstream	data;

	if(!(this->_file = popen("hostname", "r")))
		return ("Ups...I can't do this operation");
	while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
		data << this->_buffer;
	pclose(this->_file);
	return data.str();
}
