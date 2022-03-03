#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>

class Logger
{
	public:
		Logger(std::string const &filename);
		~Logger(void);

		void				log(std::string const &dest, std::string const &message);

	private:
		void				logToConsole(std::string const &message);
		void				logToFile(std::string const &message);
		std::string			makeLogEntry(std::string const &message);

		std::string const	&_filename;
};

#endif
