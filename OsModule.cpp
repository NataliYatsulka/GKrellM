#include "OsModule.hpp"

OsModule::OsModule() : Module(){}

OsModule::~OsModule() {}

OsModule::OsModule(OsModule const & src) { *this = src;}

OsModule & OsModule::operator=(OsModule const &)
{
	return (*this);
}

std::string OsModule::getOsModuleKernel()
{
	std::stringstream	data;

	if(!(this->_file = popen("system_profiler SPSoftwareDataType | grep Kernel", "r")))
		return "Ups...";
	while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
        data << this->_buffer;
	pclose(this->_file);
	return data.str();
}

std::string OsModule::getOsModuleSysVersion()
{
	std::stringstream	data;

	if(!(this->_file = popen("system_profiler SPSoftwareDataType | grep \"System Version\"", "r")))
		return "Ups...";
	while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
        data << this->_buffer;
	pclose(this->_file);
	return data.str();
}

std::string OsModule::getOsModuleBootVolume()
{
	std::stringstream	data;

	if(!(this->_file = popen("system_profiler SPSoftwareDataType | grep \"Boot Volume:\"", "r")))
		return "Ups...";
	while(fgets(this->_buffer, sizeof(this->_buffer), this->_file))
        data << this->_buffer;
	pclose(this->_file);
	return data.str();
}
