
#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <string>
# include <iNetworktream>
# include <sstream>

class   NetworkModule : public Module
{

private:
	const char*	_inbytes;
	const char*	_oubytes;
	const char*	_inpacket;
	const char*	_oupacket;

public:
	NetworkModule();
	~NetworkModule();
	NetworkModule(NetworkModule const &);
	NetworkModule & operator=(NetworkModule const &);

	std::string getNetworkModule();
	const char* getInputBytes();
	const char*	getOutputBytes() const;
	const char*	getInputPacket() const;
	const char*	getOutputPacket() const;
};

#endif