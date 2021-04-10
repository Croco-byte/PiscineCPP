/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 13:39:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	std::cout << std::endl << "=== CREATING OBJECTS ===" << std::endl << std::endl;
	FragTrap	fragtrap("XY9S2B");
	ScavTrap	scavtrap("Hyperion");
	std::string	ennemy = "Janitor Official";
	std::string visitor = "Engineed Dockett";

	std::cout << std::endl << std::endl << "=== TESTS FOR FR4G-TP ===" << std::endl;
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

	std::cout << std::endl << "=== TESTS FOR SCAVTRAP ===" << std::endl;
	scavtrap.displayStatus();
	scavtrap.meleeAttack(ennemy);
	scavtrap.rangedAttack(ennemy);
	scavtrap.takeDamage(25);
	scavtrap.displayStatus();
	scavtrap.challengeNewcomer(visitor);
	scavtrap.beRepaired(50);
	scavtrap.displayStatus();
	scavtrap.challengeNewcomer(visitor);
	scavtrap.challengeNewcomer(visitor);

	std::cout << std::endl << std::endl << "=== DESTUCTION OF OBJECTS ===" << std::endl << std::endl;

	return (0);
}
