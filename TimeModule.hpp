
#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include <string>
# include <iostream>
# include <ctime>

class   TimeModule// : public IMonitorModule
{

	TimeModule();
	~TimeModule();
	TimeModule(TimeModule const & src);
	TimeModule & operator=(TimeModule const & src);

	std::string getTimeModule();
};

#endif