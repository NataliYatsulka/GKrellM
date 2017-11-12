#ifndef OSMODULE_HPP
# define OSMODULE_HPP

#include "Module.hpp"

class   OsModule : public Module
{
public:
	OsModule();
	~OsModule();
	OsModule(OsModule const & src);
	OsModule & operator=(OsModule const &);

	std::string getOsModuleKernel();
	std::string getOsModuleSysVersion();
	std::string getOsModuleBootVolume();
};

#endif