/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:38:09 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:14:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(): _name("")
{}

Victim::Victim(std::string name): _name(name)
{
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const & src)
{
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
	if (this != &src)
		this->_name = src._name;
}

Victim::~Victim()
{
	std::cout << "The victim " << this->_name << " died for no apparent reasons!" << std::endl;
}

Victim & Victim::operator=(Victim const & rhs)
{
	if (this != &rhs)
		this->_name = rhs._name;
	return (*this);
}

void				Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " was just polymorphed in a cute little sheep!" << std::endl;
}


/* --- ACCESSORS --- */
const std::string	&Victim::getName(void) const
{ return (this->_name); }


/* --- DISPLAY OPERATOR --- */
std::ostream &	operator<<(std::ostream & out, Victim const & input)
{
	std::cout << "I'm " << input.getName() << " and I like otters!" << std::endl;
	return (out);
}
