#include <iostream>
#include "flex-logger.h"

int main(int argc, char** argv) 
{
	Logger l("TEST LOGGER");
	l.log("1");
	l.log_err("2");
	l.log_warr("3");
	return 0;
}
