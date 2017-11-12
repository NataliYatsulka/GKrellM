#ifndef HOSTMODULE_HPP
# define HOSTMODULE_HPP

# include "Module.hpp"

class   HostModule : public Module
{
public:
	HostModule();
	~HostModule();
	HostModule(HostModule const & src);
	HostModule & operator=(HostModule const &);

	std::string getUserName();
	std::string getHostName2();
};

#endif