/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:56:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 15:51:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name): ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << "[NINJA-TP " << this->_name << "]	Ahh -- one of my very first startup sequences! The memories..." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src): ClapTrap(src)
{}

NinjaTrap::~NinjaTrap()
{
	std::cout << "[NINJA-TP " << this->_name << "]	I'm too pretty to die!" << std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

void		NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "[NINJA-TP " << this->_name << "]	Ninja attacks " << target << ", inflicting " << this->_meleeDmg << " damage!" << std::endl;
}
void		NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "[NINJA-TP " << this->_name << "]	throws shurikens at " << target << ", inflicting " << this->_rangeDmg << " damage!" << std::endl;
}
void		NinjaTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= (amount - this->_armorReduction > 0) ? amount - this->_armorReduction : 0;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "[NINJA-TP " << this->_name << "]	takes " << amount - this->_armorReduction << " damage. A ninja doesn't feel pain, but still..." << std::endl;
}
void		NinjaTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "[NINJA-TP " << this->_name << "]	is repaired for " << amount << " HP. Ninja thanks." << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap const & clap)
{
	std::cout << "[NINJA-TP " << this->_name << "]	Hey " << clap.getName() << ", I'm a sexy dinosaur! RAWR!" << std::endl;
}
void		NinjaTrap::ninjaShoebox(FragTrap const & clap)
{
	std::cout << "[NINJA-TP " << this->_name << "]	Hey " << clap.getName() << ", hack the planet!" << std::endl;
}
void		NinjaTrap::ninjaShoebox(ScavTrap const & clap)
{
std::cout << "[NINJA-TP " << this->_name << "]	Hey " << clap.getName() << ", pretend you're a Siren!" << std::endl;
}
void		NinjaTrap::ninjaShoebox(NinjaTrap const & clap)
{
	std::cout << "[NINJA-TP " << this->_name << "]	Hey " << clap.getName() << ", I'm a robot ninja too!" << std::endl;
}



