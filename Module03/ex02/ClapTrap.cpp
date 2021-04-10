/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:05:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 15:00:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int HP, int maxHP, int EP, int maxEP, int level, std::string name, int melee, int range, int armor):
			_hitPoints(HP),
			_maxHitPoints(maxHP),
			_energyPoints(EP),
			_maxEnergyPoints(maxEP),
			_level(level),
			_name(name),
			_meleeDmg(melee),
			_rangeDmg(range),
			_armorReduction(armor)
{
	std::cout << "[ClapTrap " << this->_name << "]	initialized bootup sequence." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_maxHitPoints = src._maxHitPoints;
		this->_energyPoints = src._energyPoints;
		this->_maxEnergyPoints = src._maxEnergyPoints;
		this->_level = src._level;
		this->_meleeDmg = src._meleeDmg;
		this->_rangeDmg = src._rangeDmg;
		this->_armorReduction = src._armorReduction;
	}
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_maxHitPoints = rhs._maxHitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_maxEnergyPoints = rhs._maxEnergyPoints;
		this->_level = rhs._level;
		this->_meleeDmg = rhs._meleeDmg;
		this->_rangeDmg = rhs._rangeDmg;
		this->_armorReduction = rhs._armorReduction;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap " << this->_name << "]	was destroyed" << std::endl;
}

void		ClapTrap::displayStatus(void) const
{
	std::cout << std::endl;
	std::cout << "|name -> " << this->_name << "| |HP -> " << this->_hitPoints << "| |EP -> " << this->_energyPoints << "| |level -> " << this->_level << "|" << std::endl;
	std::cout << std::endl;
}

void		ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "[ClapTrap " << this->_name << "]	attacks " << target << " at melee range, inflicting " << this->_meleeDmg << " damage." << std::endl;

}

void		ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "[ClapTrap " << this->_name << "]	attacks " << target << " from afar, inflicting " << this->_rangeDmg << " damage." << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorReduction > 0) ? amount - this->_armorReduction : 0;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "[ClapTrap " << this->_name << "]	takes " << amount - this->_armorReduction << " damage." << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "[ClapTrap " << this->_name << "]	is repaired for " << amount << " HP." << std::endl;
}
