/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 20:40:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	fragtrap("XY9S2B");
	std::string	ennemy = "Janitor Official";

	fragtrap.displayStatus();
	fragtrap.meleeAttack(ennemy);
	fragtrap.rangedAttack(ennemy);
	fragtrap.takeDamage(25);
	fragtrap.displayStatus();
	fragtrap.beRepaired(50);
	fragtrap.displayStatus();
	fragtrap.vaulthunter_dot_exe(ennemy);
	fragtrap.vaulthunter_dot_exe(ennemy);
	fragtrap.vaulthunter_dot_exe(ennemy);
	fragtrap.displayStatus();
	fragtrap.vaulthunter_dot_exe(ennemy);
	fragtrap.vaulthunter_dot_exe(ennemy);
	fragtrap.vaulthunter_dot_exe(ennemy);
	fragtrap.displayStatus();

	return (0);
}
