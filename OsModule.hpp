
#ifndef OSMODULE_HPP
# define OSMODULE_HPP

# include <string>
# include <iostream>
# include <sstream>

class   OsModule// : public IMonitorModule
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