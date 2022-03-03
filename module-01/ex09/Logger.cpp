#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Logger::Logger(std::string const &filename) : _filename(filename)
{
	return ;
}

Logger::~Logger(void)
{

}

void				Logger::log(std::string const &dest, std::string const &message)
{
	typedef void(Logger::*LoggerFunction)(std::string const &message);
	LoggerFunction	functions[] = {&Logger::logToConsole, &Logger::logToFile};
	std::string		destinations[] = {"console", "file"};

	for (int i = 0; i < 2; i++)
	{
		if (destinations[i] == dest)
		{
			(this->*functions[i])(message);
			return ;
		}
	}
	std::cout << "Unknown logging destination: " << dest << std::endl;
}

void				Logger::logToConsole(std::string const &message)
{
	std::cout << makeLogEntry(message) << std::endl;
}

void				Logger::logToFile(std::string const &message)
{
	std::ofstream	file(this->_filename.c_str(), std::fstream::in | std::fstream::app);

	file << makeLogEntry(message) << std::endl;
}

std::string			Logger::makeLogEntry(std::string const &message)
{
	std::stringstream	stamp;
	time_t				now;
	struct tm			*timeinfo;

	time(&now);
	timeinfo = localtime(&now);

	stamp << "[" << timeinfo->tm_year + 1900;
	stamp << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_mon;
	stamp << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_mday << "_";
	stamp << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_hour;
	stamp << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_min;
	stamp << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_sec << "] ";
	return stamp.str() + message;
}
