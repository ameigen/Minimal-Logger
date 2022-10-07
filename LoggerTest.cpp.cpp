#include <string.h>
#include "Logger.h"

int main()
{
	Logger logger;
	logger.log(INFO, "This is a logger info:", 3);
	logger.log(DEBUG, "This is a logger debug:",3,20.2);
	logger.log(WARNING, "This is a logger warning:", 3, "thing!");
	logger.log(ERROR, "This is a logger warning:", "Foo"," Bar ", "FOOBAR");
	
    logger.setLogColors(ERROR, MAGENTA_TEXT, RED_BACKGROUND);
	logger.log(ERROR, "This is a logger warning:", "Foo"," Bar ", "FOOBAR");
	return 0;
}