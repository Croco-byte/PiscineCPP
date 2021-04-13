/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:11:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:14:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(): _name(""), _title("")
{}

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_title = src._title;
	}
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return (*this);
}

void				Sorcerer::polymorph(Victim const & victim)
{
	victim.getPolymorphed();
}


/* --- ACCESSORS --- */
const std::string	&Sorcerer::getName(void) const
{ return (this->_name); }
const std::string	&Sorcerer::getTitle(void) const
{ return (this->_title); }


/* --- DISPLAY OPERATOR --- */
std::ostream & operator<<(std::ostream & out, Sorcerer const & input)
{
	std::cout << "I am " << input.getName() << ", " << input.getTitle() << ", and I like ponies!" << std::endl;
	return (out);
}
