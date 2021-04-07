/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:29:04 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 13:05:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"
#include "Writer.hpp"

int		args_errors(int argc, char **argv)
{
	std::string	s1;
	std::string	s2;

	if (argc < 4 || argc > 4)
	{
		std::cout << "[X] Error: wrong number of arguments." << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "[X] Error: s1 or s2 can't be empty." << std::endl;
		return (1);
	}
	return (0);
}


int		main(int argc, char **argv)
{
	if (args_errors(argc, argv))
		return (0);

	std::string		store;
	try 
	{
		Reader reader(argv[1]);
		Writer writer(argv[1], argv[2], argv[3]);
		while (1)
		{
			store = reader.getLine();
			if (!reader.getIfs())
				break ;
			writer.setLine(store);
			writer.replace();
			writer.write();
		}
	}
	catch(std::string& error)
	{
		std::cerr << error << std::endl;
	}

	return (0);
}
