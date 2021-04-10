/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 11:40:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	std::cout << std::endl << "=== CREATING OBJECTS ===" << std::endl << std::endl;
	FragTrap	fragtrap("XY9S2B");
	ScavTrap	scavtrap("Hyperion");
	NinjaTrap	ninja("Sekiro");
	ClapTrap	defaultClap(100, 100, 50, 50, 1, "Default", 10, 10, 2);
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

	std::cout << std::endl << std::endl << "=== TESTS FOR NINJATRAP ===" << std::endl;
	ninja.displayStatus();
	ninja.meleeAttack(ennemy);
	ninja.rangedAttack(ennemy);
	ninja.takeDamage(50);
	ninja.displayStatus();
	ninja.beRepaired(20);
	ninja.displayStatus();
	ninja.ninjaShoebox(fragtrap);
	ninja.ninjaShoebox(scavtrap);
	ninja.ninjaShoebox(ninja);
	ninja.ninjaShoebox(defaultClap);

	std::cout << std::endl << std::endl << "=== CREATION AND TESTS OF SUPERTRAP ===" << std::endl << std::endl;
	SuperTrap super("SUP4RTR");

	super.displayStatus();
	super.meleeAttack(ennemy);
	super.rangedAttack(ennemy);
	super.takeDamage(35);
	super.displayStatus();
	super.beRepaired(80);
	super.vaulthunter_dot_exe(ennemy);
	super.ninjaShoebox(scavtrap);
	super.vaulthunter_dot_exe(ennemy);
	super.ninjaShoebox(fragtrap);
	super.displayStatus();

	std::cout << std::endl << std::endl << "=== DESTUCTION OF OBJECTS ===" << std::endl << std::endl;

	return (0);
}
