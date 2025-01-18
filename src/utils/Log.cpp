/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 03/01/2025

*/

#include"Log.h"
#include "TimeUtils.h"

#include <algorithm>
#include <filesystem>
#include<fstream>
#include<iostream>



std::fstream Log::logFile;


std::string Log::logsHome = "logs";


std::string buildMessage(const std::string &, const std::string &);

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

void Log::initLog() {

	std::filesystem::create_directory("logs");

	logFile.open(getLogFileName(), std::ios::out);

	if (logFile.is_open()) info("Logfile was created successfully");
	else {

		std::cerr << "Failed to open log file" << std::endl;

		exit(206);
	}
}

void Log::info(const std::string &str) {

	write(buildMessage("INFO", str) + "\n");
}

void Log::debug(const std::string &str) {

	write(buildMessage("DEBUG", str) + "\n");
}

void Log::warning(const std::string &str) {

	write(buildMessage("WARNING", str) + "\n");
}

void Log::error(const std::string &str) {

	write(buildMessage("ERROR", str) + "\n");
}

void Log::fatal(const std::string &str) {

	write(buildMessage("FATAL", str) + "\n");
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

Log::Log()= default;

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

void Log::write(const std::string &str){

	logFile << str;
	logFile.flush();
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

void Log::finishLog(){

	if(logFile) logFile.close();
}

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

std::string buildMessage(const std::string &token, const std::string &message) {

	return TimeUtils::getTimeStamp() + "  " + token + ": " + message;
}


/**
 * A timestamp usada no nome do arquivo é obtida a partir da função TimeUtils::getTimeStamp
 * @return um nome de arquivo de log na forma logs/timestamp.log
 */
std::string Log::getLogFileName() {

	std::string stamp = TimeUtils::getTimeStamp();

	std::ranges::replace(stamp, ' ', '_'); // Replaces spaces in the filename with underscores

	return logsHome + "/" + stamp + ".log";
}
