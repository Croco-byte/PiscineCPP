/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:35:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 18:08:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name): ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	this->_hitPoints = FragTrap::_fragHitPoints;
	this->_maxHitPoints = FragTrap::_fragMaxHitPoints;
	this->_energyPoints = NinjaTrap::_ninjaEnergyPoints;
	this->_maxEnergyPoints = NinjaTrap::_ninjaMaxEnergyPoints;
	this->_level = 1;
	this->_meleeDmg = NinjaTrap::_ninjaMeleeDmg;
	this->_rangeDmg = FragTrap::_fragRangeDmg;
	this->_armorReduction = FragTrap::_fragArmorRed;
}

SuperTrap::SuperTrap(SuperTrap const & src): ClapTrap(src), FragTrap(src), NinjaTrap(src)
{}

SuperTrap::~SuperTrap()
{}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs)
{
	if (this != &rhs)
		SuperTrap::operator=(rhs);
	return (*this);
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	this->NinjaTrap::meleeAttack(target);
}

void	SuperTrap::rangedAttack(std::string const & target)
{
	this->FragTrap::rangedAttack(target);
}
