
#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include <string>
# include <iostream>
# include <ctime>

class   TimeModule// : public IMonitorModule
{
public:
	TimeModule();
	~TimeModule();
	TimeModule(TimeModule const & src);
	TimeModule & operator=(TimeModule const &);

	std::string	getTimeModule();
};

#endif
