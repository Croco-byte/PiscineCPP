/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:13:03 by user42            #+#    #+#             */
/*   Updated: 2021/04/03 15:29:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int		main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for (size_t j = 0; j < str.size(); j++)
				std::cout << (char)std::toupper(str[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
