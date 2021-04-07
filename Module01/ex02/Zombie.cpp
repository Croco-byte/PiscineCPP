/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:45:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 14:11:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Unknown_Zombie"), _type("Soldier")
{
	this->announce();
}

Zombie::Zombie(std::string name) : _name(name), _type("Soldier")
{
	this->announce();
}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	this->announce();
}

Zombie::~Zombie()
{}


void	Zombie::announce(void)
{
	std::cout << "<" << this->_name << "(" << this->_type << ")>";
	std::cout << "	Braiiiiiiinnnsss......" << std::endl;
}

/* --- MUTATORS --- */
void	Zombie::set_name(std::string name)
{ this->_name = name; }

void	Zombie::set_type(std::string type)
{ this->_type = type; }

/* --- ACCESSORS --- */
std::string	Zombie::get_name(void)
{ return (this->_name); }

std::string	Zombie::get_type(void)
{ return (this->_type); }
