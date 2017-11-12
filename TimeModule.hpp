#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include "Module.hpp"

class   TimeModule : public Module
{
public:
	TimeModule();
	~TimeModule();
	TimeModule(TimeModule const & src);
	TimeModule & operator=(TimeModule const &);

	std::string	getTimeModule();
};

#endif
