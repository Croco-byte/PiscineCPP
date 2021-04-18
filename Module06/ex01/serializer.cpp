/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:48:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 19:28:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <string>
//#include <time.h>


struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

void *			serialize(void)
{
	srand(time(NULL));
	int			n(rand() % 10000);
	std::string	alphabet("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	char *raw = new char[20];

	std::cout << "[INFO] Initial data" << std::endl;
	std::cout << "First string	->	";
	for (int i = 0; i < 8; i++)
	{
		raw[i] = alphabet[rand() % 62];
		std::cout << raw[i];
	}
	std::cout << std::endl << "Number		->	" << n << std::endl;
	*reinterpret_cast<int *>(raw + 8) = n;
	std::cout << "Second string	->	";
	for (int i = 0; i < 8; i++)
	{
		raw[i + 12] = alphabet[rand() % 62];
		std::cout << raw[i + 12];
	}
	std::cout << std::endl;

	std::cout << std::endl << "[INFO] Serializing data into bytes stream" << std::endl;
	return (static_cast<void *>(raw));
}

Data *	deserialize(void * raw)
{
	Data * result = new Data;

	std::cout << std::endl << "[INFO] Deserializing bytes stream" << std::endl << std::endl;
	result->s1 = std::string(reinterpret_cast<char *>(raw), 8);
	result->n = *reinterpret_cast<int *>(static_cast<char *>(raw) + 8);
	result->s2 = std::string(reinterpret_cast<char *>(static_cast<char *>(raw) + 12), 8);
	return (result);
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
