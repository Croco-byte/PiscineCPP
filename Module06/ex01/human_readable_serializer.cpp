/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:48:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 11:52:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sstream>


struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

std::string		formatData(void)
{
	srand(time(NULL));
	std::stringstream	ss;
	std::string			alphabet("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::string			s1("");
	std::string			s2("");
	int					n(rand() % 100000);
	int					intSize;

	for (int i = 0; i < 8; i++)
		s1 += alphabet[rand() % 62];
	for (int i = 0; i < 8; i++)
		s2 += alphabet[rand() % 62];
	ss << n;
	intSize = ss.str().size();
	ss.str("");
	ss << s1.size() << ":" << intSize << ":" << s2.size() << ":";
	ss << s1 << n << s2;
	return (ss.str());
}

void *			serialize(void)
{
	char *		result;
	std::string	format;
	size_t		i;

	format = formatData();
	result = new char[format.size() + 1];
	i = 0;
	while(i < format.size())
	{
		result[i] = format[i];
		i++;
	}
	result[i] = '\0';
	std::cout << "[INFO] Sending following human-readable (text) serialized data:" << std::endl;
	std::cout << "|" << result << "|" << std::endl << std::endl;
	return (static_cast<void *>(result));
}

int		parseSizes(std::string serialized, int sizes[3])
{
	int	i(0);
	int	j(0);

	for (int k = 0; k < 3; k++)
	{
		while (serialized[i] && serialized[i] != ':')
			i++;
		sizes[k] = std::atoi(serialized.substr(j, i).c_str());
		i++;
		j = i;
	}
	return (i);
}

Data *	deserialize(void * raw)
{
	std::string	serialized;
	int			sizes[3];
	Data *		deserialized = new Data;
	int			offset;

	serialized = reinterpret_cast<char *>(raw);
	offset = parseSizes(serialized, sizes);
	std::cout << "[INFO] Parsed the following sizes for serialized data:" << std::endl;
	std::cout << "|" << sizes[0] << "| |" << sizes[1] << "| |" << sizes[2] << "|" << std::endl << std::endl;

	deserialized->s1 = serialized.substr(offset, sizes[0]);
	offset += sizes[0];
	deserialized->n = std::atoi(serialized.substr(offset, sizes[1]).c_str());
	offset += sizes[1];
	deserialized->s2 = serialized.substr(offset, sizes[2]);
	return (deserialized);
}

int		main(void)
{
	void *	serialized;
	Data *	deserialized;
	serialized = serialize();
	deserialized = deserialize(serialized);

	std::cout << "[RESULT] Deserialized the data into the following structure:" << std::endl;
	std::cout << "deserialized->s1	=	|" << deserialized->s1 << "|" << std::endl;
	std::cout << "deserialized->n		=	|" << deserialized->n << "|" << std::endl;
	std::cout << "deserialized->s2	=	|" << deserialized->s2 << "|" << std::endl;

	delete [] reinterpret_cast<char *>(serialized);
	delete deserialized;
	return (0);
}
