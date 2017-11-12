
#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include <string>
# include <iostream>
# include <sstream>

class   HostModule// : public IMonitorModule
{
public:
	HostModule();
	~HostModule();
	HostModule(HostModule const & src);
	HostModule & operator=(HostModule const &);

	std::string getHostName();
	std::string getHostName2();

};

#endif