/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:06:30 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:33:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

class	Logger
{
	public:
		Logger(std::string filename);
		~Logger();

		void	log(std::string const & dest, std::string const & message);


	private:
		std::string		_filename;
		std::ofstream	_ofs;
		
		std::string		_getTimestamp(void);
		std::string		_makeLogEntry(std::string const & message);
		void			_logToConsole(std::string const & message);
		void			_logToFile(std::string const & message);


};


#endif
