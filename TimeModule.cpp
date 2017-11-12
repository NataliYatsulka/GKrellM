
#include "TimeModule.hpp"

TimeModule::TimeModule() {}

TimeModule::~TimeModule() {}

TimeModule::TimeModule(TimeModule const & src) { *this = src;}

TimeModule & TimeModule::operator=(TimeModule const &)
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

	strftime (buffer, 80, "Date/Time: %A %x %X %p", timeinfo);
	return (std::string(buffer));
}
