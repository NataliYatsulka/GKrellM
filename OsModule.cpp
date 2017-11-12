
#include "OsModule.hpp"

OsModule::OsModule() {}

OsModule::~OsModule() {}

OsModule::OsModule(OsModule const & src) { *this = src;}

OsModule & OsModule::operator=(OsModule const &)
{
	return (*this);
}

std::string OsModule::getOsModuleKernel()
{
	FILE 				*file;
	char				buffer[80];
	std::stringstream	result;

	if(!(file = popen("system_profiler SPSoftwareDataType | grep Kernel", "r")))
		return "Ups...";
	while(fgets(buffer, sizeof(buffer), file))
		result << buffer;
	pclose(file);
	return result.str();
}

std::string OsModule::getOsModuleSysVersion()
{
	FILE 				*file;
	char				buffer[80];
	std::stringstream	result;

	if(!(file = popen("system_profiler SPSoftwareDataType | grep "System Version"", "r")))
		return "Ups...";
	while(fgets(buffer, sizeof(buffer), file))
		result << buffer;
	pclose(file);
	return result.str();
}

std::string OsModule::getOsModuleBootVolume()
{
	FILE 				*file;
	char				buffer[80];
	std::stringstream	result;

	if(!(file = popen("system_profiler SPSoftwareDataType | grep "Boot Volume:"", "r")))
		return "Ups...";
	while(fgets(buffer, sizeof(buffer), file))
		result << buffer;
	pclose(file);
	return result.str();
}
