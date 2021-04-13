/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:37:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 15:02:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int		main(void)
{
	Character	sam("Sam");
	AWeapon*	pr = new PlasmaRifle;
	AWeapon*	pf = new PowerFist;

	std::cout << sam;
	
	std::cout << "Sam finds a Plasma Rifle on the ground and picks it up." << std::endl;
	sam.equip(pr);
	
	std::cout << "A wild Super Mutant appears before Sam !" << std::endl;
	Enemy*		enemy1 = new SuperMutant;
	
	std::cout << std::endl << "=== STATS ===" << std::endl;
	enemy1->displayStatus();
	std::cout << sam;
	std::cout << std::endl;
	
	std::cout << "Sam engages the Super Mutant with his Plasma Rifle." << std::endl;
	sam.attack(enemy1);
	sam.attack(enemy1);
	sam.attack(enemy1);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	enemy1->displayStatus();
	std::cout << sam;
	std::cout << std::endl;
	
	std::cout << "Sam equips his Power Fist. Time to finish it hand-to-hand." << std::endl;
	sam.equip(pf);
	while (enemy1)
		sam.attack(enemy1);
	std::cout << "Super Mutant painfully dies." << std::endl;
	
	std::cout << std::endl << "=== STATS ===" << std::endl;
	std::cout << sam;
	std::cout << std::endl;

	std::cout << "Sam continues its journey. Dangerously low on Action Points, he decides to lay down his weapons, and rest for a bit." << std::endl;
	sam.recoverAP();
	sam.equip(NULL);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	std::cout << sam;
	std::cout << std::endl;

	std::cout << "While Sam was resting, a RadScorpion takes him by surprise!" << std::endl;
	Enemy*		enemy2 = new RadScorpion;
	std::cout << std::endl << "=== STATS ===" << std::endl;
	enemy2->displayStatus();
	std::cout << sam;
	std::cout << std::endl;

	std::cout << "Sam grabs his Power Fist, and smashes the RadScorpion with it." << std::endl;
	sam.equip(pf);
	sam.attack(enemy2);
	std::cout << "As he tries to hit the RadScorpion again with his Power Fist, he finds out that he is too low on AP." << std::endl;
	sam.attack(enemy2);
	std::cout << "He quickly grabs an AP stimulus potion and restores 10 AP points." << std::endl;
	sam.recoverAP();

	std::cout << std::endl << "=== STATS ===" << std::endl;
	enemy2->displayStatus();
	std::cout << sam;
	std::cout << std::endl;

	std::cout << "Sam can now deliver the final blow." << std::endl;
	sam.attack(enemy2);
	std::cout << "The RadScorpion is smashed to the ground." << std::endl;

	std::cout << std::endl << "=== STATS ===" << std::endl;
	std::cout << sam;
	std::cout << std::endl;


	delete (pr);
	delete (pf);
	delete (enemy1);
	delete (enemy2);
	return (0);
}
