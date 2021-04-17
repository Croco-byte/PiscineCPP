/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDetector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:56:51 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 16:22:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeDetector.hpp"

TypeDetector::TypeDetector(): _type("invalid")
{}

TypeDetector::TypeDetector(TypeDetector const & src)
{
	if (this != &src)
		this->_type= src._type;
}

TypeDetector::~TypeDetector()
{}

TypeDetector &	TypeDetector::operator=(TypeDetector const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void			TypeDetector::analyzeType(std::string const & input)
{
	if (TypeDetector::isChar(input))
		this->_type = "char";
	else if (TypeDetector::isInt(input))
		this->_type = "int";
	else if (TypeDetector::isFloat(input))
		this->_type = "float";
	else if (TypeDetector::isDouble(input))
		this->_type = "double";
}

bool		TypeDetector::isChar(std::string const & input)
{
	if (input.size() == 1 && !std::isdigit(input[0]))
		return (true);
	return (false);
}

bool		TypeDetector::isInt(std::string const & input)
{
	size_t		i;

	i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;

	for ( ; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	long tool = std::atol(input.c_str());
	if (tool > 2147483647 || tool < -2147483648)
		return (false);
	return (true);
}

bool		TypeDetector::isFloat(std::string const & input)
{
	int		i;

	i = 0;
	if (!input.compare("-inff") || !input.compare("inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (true);
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (!input[i] || !std::isdigit(input[i]))
		return (false);
	while (std::isdigit(input[i]))
		i++;
	if (!input[i] || input[i] != '.')
		return (false);
	i++;
	if (!input[i] || !std::isdigit(input[i]))
		return (false);
	while(std::isdigit(input[i]))
		i++;
	if (!input[i] || input[i] != 'f')
		return (false);
	i++;
	if (input[i] != 0)
		return (false);
	return (true);
}

bool		TypeDetector::isDouble(std::string const & input)
{
	int		i;

	i = 0;
	if (!input.compare("-inf") || !input.compare("inf") || !input.compare("+inf") || !input.compare("nan"))
		return (true);
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (!input[i] || !std::isdigit(input[i]))
		return (false);
	while (std::isdigit(input[i]))
		i++;
	if (!input[i] || input[i] != '.')
		return (false);
	i++;
	if (!input[i] || !std::isdigit(input[i]))
		return (false);
	while(std::isdigit(input[i]))
		i++;
	if (input[i] != 0)
		return (false);
	return (true);
}


/* --- ACCESSORS --- */
std::string		TypeDetector::getType(void) const
{ return (this->_type); }
