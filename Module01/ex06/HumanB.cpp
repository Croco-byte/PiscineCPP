/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:26:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 16:41:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name): _name(name)
{}

HumanB::~HumanB()
{}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon->get_type() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
