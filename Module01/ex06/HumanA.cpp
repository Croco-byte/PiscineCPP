/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:20:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 16:22:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon.get_type() << std::endl;
}
