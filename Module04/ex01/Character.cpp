/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:47:11 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 14:44:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name(""), _ap(0), _weapon(0)
{}

Character::Character(std::string const & name): _name(name), _ap(40), _weapon(0)
{}

Character::Character(Character const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_ap = src._ap;
		this->_weapon = src._weapon;
	}
}

Character::~Character()
{}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_ap = rhs._ap;
		this->_weapon = rhs._weapon;
	}
	return (*this);
}

void	Character::recoverAP()
{
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void	Character::equip(AWeapon* weapon)
{
	this->_weapon = weapon;
}

void	Character::attack(Enemy*& target)
{
	if (!this->_weapon)
		return ;
	if (this->_ap < this->_weapon->getAPCost())
	{
		std::cout << this->_name << " doesn't have enough AP points to attack!" << std::endl;
		return ;
	}

	this->_ap -= this->_weapon->getAPCost();
	std::cout << this->_name << " attacks " << target->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	target->takeDamage(this->_weapon->getDamage());
	if (target->isDead() == true)
	{
		delete (target);
		target = NULL;
	}
}

/* --- ACCESSORS --- */
std::string	const & Character::getName(void) const
{ return (this->_name); }

int					Character::getAP(void) const
{ return (this->_ap); }

AWeapon* const &		Character::getWeapon(void) const
{ return (this->_weapon); }



std::ostream & operator<<(std::ostream & out, Character const & input)
{
	if (!input.getWeapon())
		std::cout << input.getName() << " has " << input.getAP() << " AP and is unarmed" << std::endl;
	else
		std::cout << input.getName() << " has " << input.getAP() << " AP and carries a " << input.getWeapon()->getName() << std::endl;
	return (out);
}
