/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:31:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 15:40:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main(void)
{
	try
	{
		Logger logger("test.log");

		logger.log("toConsole", "Opened logger program				[toConsole log]");
		logger.log("toConsole", "Just some random application logs		[toConsole log]");
		logger.log("toFile", "Some log, this time in a file		[toFile log]");
		logger.log("toConsole", "Another log on the console !			[toConsole log]");
		logger.log("toFile", "Some other log in a file...		[toFile log]");
		logger.log("toRandom", "This log should throw an error		[error log]");
	}
	catch (std::string const & error)
	{
		std::cerr << error << std::endl;
	}
	return (0);
}
