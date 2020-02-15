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
		Logger(const char* n) 
			: name(n) 
		{};
		
		~Logger() {};
		
		void log(const char*);
		void log_err(const char*);
		void log_warr(const char*);
		
	protected:
		const char* name;
};

#endif
