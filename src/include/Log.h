/*

	Autor: Cícero Augusto Alcântara de Sousa
	Última edição: 03/01/2025

*/

#ifndef LOG_H
#define LOG_H

#include<fstream>

class Log{
		
	public:
	
		Log(Log &) = delete;
		
		Log(Log const&) = delete;
		
		void operator=(const Log &) = delete;

		static void initLog();

		static void finishLog();
		
		static void info(const std::string &str);
		
		static void debug(const std::string &str);
		
		static void warning(const std::string &str);
		
		static void error(const std::string &str);
		
		static void fatal(const std::string &str);

	private:

		Log();

		static Log *log;

		static std::fstream logFile;

		static void write(const std::string &);
};

#endif /* LOG_H */
