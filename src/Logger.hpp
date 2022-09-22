#pragma once

#include <queue>
#include <string>
#include <mutex>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <fstream>
#include <stdexcept>
#include <ctime>

#define CRITICAL_LEVEL 40
#define ERROR_LEVEL    30
#define WARNING_LEVEL  20
#define INFO_LEVEL     10
#define DEBUG_LEVEL    0

class Logger {
public:
	Logger(std::string loggerName="root", std::string fileName="log.txt", std::string filePath="", std::string level="INFO", std::string separator="::", unsigned int delay = 1);
	Logger(const Logger&);
	~Logger();

	void debug(std::string entry);
	void info(std::string entry);
	void warning(std::string entry);
	void error(std::string entry);
	void critical(std::string entry);

private:
	std::string m_separator; // needs to be validated if user inputs
	std::string m_loggerName;
	std::string m_fileName;
	std::string m_filePath;
	unsigned int m_delay; // delay in seconds
	int m_level = INFO_LEVEL;


	std::atomic_bool m_stopListener = false;
	std::mutex m_queueMutex;
	std::queue<std::string> m_queue;
	std::vector<std::thread> m_threads;
	
	void PushToQueue(std::string level, std::string entry);

	std::string ConstructEntry(std::string level, std::string entry);

	std::string GetDateTime();

	std::string ValidateLoggerName(std::string name);

	std::string ValidateFileName(std::string name);

	std::string ValidateFilePath(std::string path);

	std::string ValidateSeparator(std::string separator);

	int TranslateLevel(std::string level);
	
	void Listener();

	void WriteToFile(std::string entry);
};

