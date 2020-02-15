#ifndef FLEX_LOGGER_H_
#define FLEX_LOGGER_H_
#pragma warning(disable : 4996)

#include <windows.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <time.h>

#define C_RED     FOREGROUND_RED
#define C_GREEN   FOREGROUND_GREEN
#define C_YELLOW  FOREGROUND_RED | FOREGROUND_GREEN
#define C_DEFAULT FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED

namespace flexLogger
{
	class Logger
	{
	public:
		Logger(const char* n)
			: name(n)
		{};

		~Logger() {};

		void log(const char* msg)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, C_GREEN);

			time_t raw_now;
			struct tm* timedata;
			char   buffer[255];

			time(&raw_now);
			timedata = localtime(&raw_now);

			strftime(buffer, sizeof(buffer), "%H:%M:%S", timedata);

			std::cout << "[" << buffer << "] " << name << " : " << msg << std::endl;

			SetConsoleTextAttribute(hConsole, C_DEFAULT);
		};

		void log_err(const char* msg)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, C_RED);

			time_t raw_now;
			struct tm* timedata;
			char   buffer[255];

			time(&raw_now);
			timedata = localtime(&raw_now);

			strftime(buffer, sizeof(buffer), "%H:%M:%S", timedata);

			std::cout << "[" << buffer << "] " << name << " : " << msg << std::endl;

			SetConsoleTextAttribute(hConsole, C_DEFAULT);
		};

		void log_warr(const char* msg)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, C_YELLOW);

			time_t raw_now;
			struct tm* timedata;
			char   buffer[255];

			time(&raw_now);
			timedata = localtime(&raw_now);

			strftime(buffer, sizeof(buffer), "%H:%M:%S", timedata);

			std::cout << "[" << buffer << "] " << name << " : " << msg << std::endl;

			SetConsoleTextAttribute(hConsole, C_DEFAULT);
		};

	protected:
		const char* name;
	};
};
#endif
