
#include "TimeModule.hpp"

TimeModule::TimeModule() {}

TimeModule::~TimeModule() {}

TimeModule::TimeModule(TimeModule const & src) { *this = src;}

TimeModule & TimeModule::operator=(TimeModule const & src)
{
	return (*this);//->_time = src.getTimeModule());
}

std::string TimeModule::getTimeModule()
{
	time_t rawtime;
	struct tm * timeinfo;
	char	buffer[80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer, 80, "Day time:  %e/%m/%Y  %I:%M:%S%p", timeinfo);
	// puts (buffer);
	return (std::string(buffer));//??
	// time_t rawtime;
	// struct tm * timeinfo;

	// time (&rawtime);
	// timeinfo = localtime (&rawtime);
	// std::cout << "Current local time and date: " << asctime(timeinfo);// << std::endl;
}
