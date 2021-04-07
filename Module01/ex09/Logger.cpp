/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:15:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 15:39:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string filename): _filename(filename)
{
	this->_ofs.open(this->_filename.c_str(), std::ofstream::app);
	if (!this->_ofs)
		throw std::string("[X] Error: Couldn't open file for writing");
}

Logger::~Logger()
{}

std::string		Logger::_getTimestamp(void)
{
	std::stringstream	ss;

	std::time_t		curr = std::time(0);
	std::tm*		now = std::localtime(&curr);
	ss << "[" << (now->tm_year + 1900);
	ss << std::setfill('0') << std::setw(2);
	ss << (now->tm_mon);
	ss << std::setfill('0') << std::setw(2);
	ss << (now->tm_mday);
	ss << "_";
	ss << std::setfill('0') << std::setw(2);
	ss << (now->tm_hour);
	ss << std::setfill('0') << std::setw(2);
	ss << (now->tm_min);
	ss << std::setfill('0') << std::setw(2);
	ss << (now->tm_sec);
	ss << "] ";
	return (ss.str());
}

std::string		Logger::_makeLogEntry(std::string const & message)
{
	std::string	logEntry;

	logEntry = this->_getTimestamp();
	logEntry += "	";
	logEntry += message;
	return (logEntry);
}

void			Logger::_logToConsole(std::string const & message)
{
	std::cout << this->_makeLogEntry(message) << std::endl;
}

void			Logger::_logToFile(std::string const & message)
{
	this->_ofs << this->_makeLogEntry(message) << std::endl;
}

void			Logger::log(std::string const & dest, std::string const & message)
{
	int		key;
	void	(Logger::*p[2])(std::string const & message) = {
		&Logger::_logToConsole,
		&Logger::_logToFile
	};

	key =	(dest == "toConsole") ? 0 :
			(dest == "toFile") ? 1 :
			throw std::string("[X] Error: incorrect destination for log");
	(this->*p[key])(message);
}
