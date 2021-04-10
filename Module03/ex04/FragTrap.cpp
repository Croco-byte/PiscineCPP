/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:55:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 11:34:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	srand(time(NULL));
	std::cout << "[FR4G-TP " << this->_name << "]	Bootup sequence ... Directive one: protect humanity. Directive two: Obey Jack. Directive three: Dance!" << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeDmg = 30;
	this->_rangeDmg = 20;
	this->_armorReduction = 5;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FR4G-TP " << this->_name << "]	I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "[" << this->_name << "]	attacks " << target << " at melee range, inflicting " << this->_meleeDmg << " damage!" << std::endl;

}

void		FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "[" << this->_name << "]	attacks " << target << " from afar, inflicting " << this->_rangeDmg << " damage!" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int		key;
	std::string attacks[5] = {
		"Miniontrap (FR4G-TP throws out a Turrettrap that shoots explosive rockets)",
		"Meat Unicycle (FR4P-TP periodically emits incendiary novas)",
		"Blight bot (FR4G-TP summons a Sirentrap emitting an acid gas)",
		"Rubber Ducky (FR4G-TP continually bounce in the air and gains bullet reflection)",
		"Funzerker (FR4G-TP deploys a Holotrap and becomes invisible... Shhh...)"
	};

	key = rand() % 5;
	if (this->_energyPoints >= 25)
	{
		std::cout << "[" << this->_name << "]	uses one of his special attacks on "<< target << ": " << attacks[key] << std::endl;
		this->_energyPoints -= 25;
	}
	else
	{
		std::cout << "[" << this->_name << "]	doesn't have enough energy for a special attack!" << std::endl;
	}
}
