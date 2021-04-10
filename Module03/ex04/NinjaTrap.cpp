/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:56:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 11:34:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name): ClapTrap(name)
{
	std::cout << "[NINJA-TP " << this->_name << "]	Ahh -- one of my very first startup sequences! The memories..." << std::endl;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeDmg = 60;
	this->_rangeDmg = 5;
	this->_armorReduction = 0;
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
	std::cout << "[" << this->_name << "]	Ninja attacks " << target << ", inflicting " << this->_meleeDmg << " damage!" << std::endl;
}
void		NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "[" << this->_name << "]	throws shurikens at " << target << ", inflicting " << this->_rangeDmg << " damage!" << std::endl;
}

void		NinjaTrap::ninjaShoebox(ClapTrap const & clap)
{
	std::cout << "[" << this->_name << "]	Hey " << clap.getName() << ", I'm a sexy dinosaur! RAWR!" << std::endl;
}
void		NinjaTrap::ninjaShoebox(FragTrap const & clap)
{
	std::cout << "[" << this->_name << "]	Hey " << clap.getName() << ", hack the planet!" << std::endl;
}
void		NinjaTrap::ninjaShoebox(ScavTrap const & clap)
{
std::cout << "[" << this->_name << "]	Hey " << clap.getName() << ", pretend you're a Siren!" << std::endl;
}
void		NinjaTrap::ninjaShoebox(NinjaTrap const & clap)
{
	std::cout << "[" << this->_name << "]	Hey " << clap.getName() << ", I'm a robot ninja too!" << std::endl;
}



