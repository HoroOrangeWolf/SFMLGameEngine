
#define __STDC_WANT_LIB_EXT1__ 1
#define _XOPEN_SOURCE
#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"
#include <fstream>

void Logger::setPath(std::string path)
{
	Logger::filePath = path;
}
std::string Logger::filePath = "";

void Logger::log(std::string data)
{
	std::ofstream outfile;

	time_t t = time(NULL);

	outfile.open(Logger::filePath, std::ios_base::app);

	outfile << data << " | " << asctime(localtime(&t));

	outfile.close();
}
