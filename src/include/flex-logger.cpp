#include "flex-logger.h"

#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>

void Logger::log(std::string msg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, C_GREEN);
	
	time_t raw_now;
	struct tm* timedata;
	char   buffer[255];
	
	time(&raw_now);
	timedata = localtime(&raw_now);
	
	strftime (buffer, sizeof(buffer), "%H:%M:%S", timedata);
	
	std::cout<<"[" << buffer << "] " << name << " : " << msg << std::endl;
	
	SetConsoleTextAttribute(hConsole, C_DEFAULT);
}

void Logger::log_err(std::string msg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, C_RED);
	
	time_t raw_now;
	struct tm* timedata;
	char   buffer[255];
	
	time(&raw_now);
	timedata = localtime(&raw_now);
	
	strftime (buffer, sizeof(buffer), "%H:%M:%S", timedata);
	
	std::cout<<"[" << buffer << "] " << name << " : " << msg << std::endl;
	
	SetConsoleTextAttribute(hConsole, C_DEFAULT);
}

void Logger::log_warr(std::string msg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, C_YELLOW);
	
	time_t raw_now;
	struct tm* timedata;
	char   buffer[255];
	
	time(&raw_now);
	timedata = localtime(&raw_now);
	
	strftime (buffer, sizeof(buffer), "%H:%M:%S", timedata);
	
	std::cout<<"[" << buffer << "] " << name << " : " << msg << std::endl;
	
	SetConsoleTextAttribute(hConsole, C_DEFAULT);
}
