/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:34:06 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 14:19:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = (int)integer << Fixed::_byteNb;
}

Fixed::Fixed(const float floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = (int)roundf(floater * (1 << Fixed::_byteNb));
}


Fixed::Fixed (Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw / (float)(1 << Fixed::_byteNb));
}
int		Fixed::toInt(void) const
{
	return ((int)this->_raw >> Fixed::_byteNb);
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}


std::ostream &	operator<<(std::ostream & out, Fixed const & input)
{
	out << input.toFloat();
	return (out);
}
