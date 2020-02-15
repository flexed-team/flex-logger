#ifndef FLEX_LOGGER_H_
#define FLEX_LOGGER_H_

#include<windows.h>
#include<string>

#define C_RED     FOREGROUND_RED
#define C_GREEN   FOREGROUND_GREEN
#define C_YELLOW  FOREGROUND_RED | FOREGROUND_GREEN
#define C_DEFAULT FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED

class Logger
{
	public:
		Logger(std::string n) 
			: name(n) 
		{};
		
		~Logger() {};
		
		void log(std::string);
		void log_err(std::string);
		void log_warr(std::string);
		
	protected:
		std::string name;
};

#endif