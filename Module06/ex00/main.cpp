/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:15:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 14:06:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeDetector.hpp"
#include "Converter.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[x] ERROR: wrong number of arguments" << std::endl;
		return (1);
	}

	TypeDetector	typedetector;
	typedetector.analyzeType(argv[1]);
	Converter		converter(typedetector.getType(), argv[1]);

	std::cout << converter;

	return (0);
}
