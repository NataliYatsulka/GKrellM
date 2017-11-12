
#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include <string>
# include <iostream>

class   HostModule// : public IMonitorModule
{

	HostModule();
	~HostModule();
	HostModule(HostModule const & src);
	HostModule & operator=(HostModule const & src);

	std::string getHostModule();
};

#endif