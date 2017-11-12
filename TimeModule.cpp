#include "TimeModule.hpp"

TimeModule::TimeModule() : Module() {}

TimeModule::~TimeModule() {}

TimeModule::TimeModule(TimeModule const & src) { *this = src;}

TimeModule & TimeModule::operator=(TimeModule const &src)
{
	(void)src;
	return (*this);
}

std::string TimeModule::getTimeModule()
{
	time_t	rawtime;
	struct	tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (this->_buffer, 80, "Date/Time: %A %x %X %p", timeinfo);
	return (std::string(this->_buffer));
}
