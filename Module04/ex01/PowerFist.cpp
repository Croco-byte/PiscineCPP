/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:54:51 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 11:57:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50)
{}

PowerFist::PowerFist(PowerFist const & src): AWeapon(src)
{}

PowerFist::~PowerFist()
{}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs)
		AWeapon::operator=(rhs);
	return (*this);
}

void	PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}
