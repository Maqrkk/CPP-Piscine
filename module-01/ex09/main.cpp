#include "Logger.hpp"

int		main(void)
{
	Logger		logger("log.txt");

	logger.log("file", "Hallo");
	logger.log("console", "Help 1");
	logger.log("console", "Help 2");
	logger.log("file", "Doei");
	logger.log("abc", "message");
}
