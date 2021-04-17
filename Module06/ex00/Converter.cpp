/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:39:54 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 16:19:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter()
{}

Converter::Converter(std::string const & type, std::string const & input): _cvalue(0), _ivalue(0), _fvalue(0), _dvalue(0), _inputType(TypeInvalid)
{
	for (int i = 0; i < 4; i++)
		this->_status[i] = true;
	if (!type.compare("char"))
		this->_inputType = TypeChar;
	else if (!type.compare("int"))
		this->_inputType = TypeInt;
	else if (!type.compare("float"))
		this->_inputType = TypeFloat;
	else if (!type.compare("double"))
		this->_inputType = TypeDouble;
	else
		this->_inputType = TypeInvalid;
	
	switch (this->_inputType)
	{
		case TypeChar:
			this->fromChar(input);
			break;
		case TypeInt:
			this->fromInt(input);
			break;
		case TypeFloat:
			this->fromFloat(input);
			break;
		case TypeDouble:
			this->fromDouble(input);
			break;
		default:
			this->fromInvalid();
			break;
	};
}

Converter::Converter(Converter const & src):
									_cvalue(src._cvalue),
									_ivalue(src._ivalue),
									_fvalue(src._fvalue),
									_dvalue(src._dvalue),
									_inputType(src._inputType)
{
	for (int i = 0; i < 4; i++)
		this->_status[i] = src._status[i];
}

Converter::~Converter()
{}

Converter & Converter::operator=(Converter const & rhs)
{
	this->_inputType = rhs._inputType;
	this->_cvalue = rhs._cvalue;
	this->_ivalue = rhs._ivalue;
	this->_fvalue = rhs._fvalue;
	this->_dvalue = rhs._dvalue;
	for (int i = 0; i < 4; i++)
		this->_status[i] = rhs._status[i];
	return (*this);
}

void		Converter::fromChar(std::string const & input)
{
	this->_cvalue = input[0];
	this->_ivalue = static_cast<int>(this->_cvalue);
	this->_fvalue = static_cast<float>(this->_cvalue);
	this->_dvalue = static_cast<double>(this->_cvalue);
}

void		Converter::fromInt(std::string const & input)
{
	this->_ivalue = std::atoi(input.c_str());
	if (this->_ivalue > 127 || this->_ivalue < 0)
		this->setImpossible(TypeChar);
	else
		this->_cvalue = static_cast<char>(this->_ivalue);
	this->_fvalue = static_cast<float>(this->_ivalue);
	this->_dvalue = static_cast<double>(this->_ivalue);
}

void		Converter::fromFloat(std::string const & input)
{
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
	{
		this->setImpossible(TypeChar);
		this->setImpossible(TypeInt);
		this->_fvalue = std::atof(input.c_str());
		this->_dvalue = std::atof(input.c_str());
	}
	else
	{
		this->_fvalue = std::atof(input.c_str());
		if (this->_fvalue > 127 || this->_fvalue < 0)
			this->setImpossible(TypeChar);
		else
			this->_cvalue = static_cast<char>(this->_fvalue);
		this->_ivalue = static_cast<int>(this->_fvalue);
		this->_dvalue = static_cast<double>(this->_fvalue);
		if (this->_dvalue > std::numeric_limits<int>::max() || this->_dvalue < std::numeric_limits<int>::min())
			this->setImpossible(TypeInt);
	}
}

void		Converter::fromDouble(std::string const & input)
{
	if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
	{
		this->setImpossible(TypeChar);
		this->setImpossible(TypeInt);
		this->_fvalue = std::atof(input.c_str());
		this->_dvalue = std::atof(input.c_str());
	}
	else
	{
		this->_dvalue = std::atof(input.c_str());
		if (this->_dvalue > 127 || this->_dvalue < 0)
			this->setImpossible(TypeChar);
		else
			this->_cvalue = static_cast<char>(this->_dvalue);
		this->_ivalue = static_cast<int>(this->_dvalue);
		this->_fvalue = static_cast<double>(this->_dvalue);
		if (this->_dvalue > std::numeric_limits<int>::max() || this->_dvalue < std::numeric_limits<int>::min())
			this->setImpossible(TypeInt);
	}
}

void		Converter::fromInvalid(void)
{
	this->setImpossible(TypeChar);
	this->setImpossible(TypeInt);
	this->setImpossible(TypeFloat);
	this->setImpossible(TypeDouble);
}

void		Converter::setImpossible(Type type)
{
	this->_status[type] = false;
}


void		Converter::displayConverted(void) const
{
	std::stringstream ss;

	if (this->_status[TypeChar] == false)
		std::cout << "char: impossible" << std::endl;
	else if (this->_cvalue < 32 || this->_cvalue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << this->_cvalue << "\'" << std::endl;
	
	if (this->_status[TypeInt] == false)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->_ivalue << std::endl;
	
	if (this->_status[TypeFloat] == false)
		std::cout << "float: impossible" << std::endl;
	else
	{
		ss << this->_fvalue;
		if (ss.str().find('.') == std::string::npos && ss.str().compare("nan") != 0 && ss.str().compare("inf") != 0 && ss.str().compare("-inf") != 0)
			std::cout << "float: " << this->_fvalue << ".0f" << std::endl;
		else
			std::cout << "float: " << this->_fvalue << "f" << std::endl;
	}
	
	if (this->_status[TypeDouble] == false)
		std::cout << "double: impossible" << std::endl;
	else
	{
		ss.str(std::string());
		ss << this->_dvalue;
		if (ss.str().find('.') == std::string::npos && ss.str().compare("nan") != 0 && ss.str().compare("inf") != 0 && ss.str().compare("-inf") != 0)
			std::cout << "double: " << this->_dvalue << ".0" << std::endl;
		else
			std::cout << "double: " << this->_dvalue << std::endl;
	}
	
}

std::ostream const & operator<<(std::ostream const & out, Converter const & input)
{
	input.displayConverted();
	return (out);
}
