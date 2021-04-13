/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:40:14 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 13:15:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int		main(void)
{
	Squad*	alpha = new Squad;

	std::cout << "=== CREATED ALPHA SQUAD ===" << std::endl;
	
	std::cout << std::endl << "=== SQUADS STATS ===" << std::endl;
	std::cout << "> Alpha:	";
	alpha->displayAllUnits();
	std::cout << std::endl;

	std::cout << "=== CREATING TWO TACTICAL MARINES AND ADDING THEM TO SQUAD ===" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		TacticalMarine * new_unit = new TacticalMarine;
		alpha->push(new_unit);
	}

	std::cout << std::endl << "=== CREATING THREE ASSAULT TERMINATORS AND ADDING THEM TO SQUAD ===" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			AssaultTerminator * new_unit = new AssaultTerminator;
			alpha->push(new_unit);
		}
		catch (std::string push_error)
		{ std::cerr << push_error << std::endl; }
	}

	std::cout << std::endl << "=== SQUADS STATS ===" << std::endl;
	std::cout << "> Alpha:	";
	alpha->displayAllUnits();
	std::cout << std::endl;

	std::cout << "=== MAKING ALL SPACEMARINES IN SQUAD SHOUT THEIR BATTLECRY ===" << std::endl;
	for (int i = 0; i < alpha->getCount(); i++)
	{
		try
		{
			ISpaceMarine * curr = alpha->getUnit(i);
			curr->battleCry();
		}
		catch (int index)
		{ std::cerr << "[X] Error: unit number " << index << " doesn't exist." << std::endl; }
	}

	std::cout << std::endl << "=== MAKING ALL SPACEMARINES IN SQUAD USE THEIR RANGE ATTACK, THEN THEIR MELEE ATTACK ===" << std::endl;
	for (int i = 0; i < alpha->getCount(); i++)
	{
		try
		{
			ISpaceMarine * curr = alpha->getUnit(i);
			curr->rangedAttack();
			curr->meleeAttack();
		}
		catch (int index)
		{ std::cerr << "[X] Error: unit number " << index << " doesn't exist." << std::endl; }
	}

	std::cout << std::endl << "=== CREATING ANOTHER TACTIAL MARINE AND ADDING IT TO SQUAD ALPHA ===" << std::endl;
	TacticalMarine * bob = new TacticalMarine;
	alpha->push(bob);

	std::cout << std::endl << "=== ERROR HANDLING: TRYING TO ADD THE SAME TACTICAL MARINE TO SQUAD ALPHA ===" << std::endl;
	try
	{
		alpha->push(bob);
	}
	catch (std::string push_error)
	{ std::cerr << push_error << std::endl; }

	std::cout << std::endl << "=== ERROR HANDLING: TRYING TO ADD A NULL SPACEMARINE TO SQUAD ALPHA ===" << std::endl;
	try
	{
		alpha->push(0);
	}
	catch (std::string push_error)
	{ std::cerr << push_error << std::endl; }

	std::cout << std::endl << "=== ERROR HANDLING: TRYING TO ACCESS A UNIT THAT DOESN'T EXIST IN SQUAD ALPHA ===" << std::endl;
	try
	{
		alpha->getUnit(8);
	}
	catch (int index)
	{ std::cerr << "[X] Error: unit number " << index << " doesn't exist." << std::endl; }

	std::cout << std::endl << "=== SQUADS STATS ===" << std::endl;
	std::cout << "> Alpha:	";
	alpha->displayAllUnits();
	std::cout << std::endl;

	std::cout << "=== CREATING BETA SQUAD FROM ALPHA SQUAD WITH ITS COPY CONSTRUCTOR ===" << std::endl;
	Squad*	beta = new Squad(*alpha);
	std::cout << "[INFO] First unit of Alpha squad is at address " << alpha->getUnit(0) << ", but first unit of Beta squad is at address " << beta->getUnit(0) << ". The addresses are different, so a deep copy was made." << std::endl;

	std::cout << std::endl << "=== SQUADS STATS ===" << std::endl;
	std::cout << "> Alpha:	";
	alpha->displayAllUnits();
	std::cout << "> Beta:		";
	beta->displayAllUnits();
	std::cout << std::endl;

	std::cout << "=== CREATING AN EMPTY TETA SQUAD ===" << std::endl;
	Squad*	teta = new Squad;
	
	std::cout << std::endl << "=== SQUADS STATS ===" << std::endl;
	std::cout << "> Alpha:	";
	alpha->displayAllUnits();
	std::cout << "> Beta:		";
	beta->displayAllUnits();
	std::cout << "> Teta:		";
	teta->displayAllUnits();
	std::cout << std::endl;

	std::cout << "=== USING THE ASSIGNATION OPERATOR TETA = ALPHA ===" << std::endl;
	*teta = *alpha;
	std::cout << "[INFO] First unit of Alpha squad is at address " << alpha->getUnit(0) << ", but first unit of Teta squad is at address " << teta->getUnit(0) << ". The addresses are different, so a deep copy was made." << std::endl;


	std::cout << std::endl << "=== SQUADS STATS ===" << std::endl;
	std::cout << "> Alpha:	";
	alpha->displayAllUnits();
	std::cout << "> Beta:		";
	beta->displayAllUnits();
	std::cout << "> Teta:		";
	teta->displayAllUnits();
	std::cout << std::endl;

	std::cout << "=== MAKING ALL SPACEMARINES FROM SQUAD TETA SHOUT THEIR BATTLECRY ===" << std::endl;
	for (int i = 0; i < teta->getCount(); i++)
	{
		try
		{
			ISpaceMarine * curr = teta->getUnit(i);
			curr->battleCry();
		}
		catch (int index)
		{ std::cerr << "[X] Error: unit number " << index << " doesn't exist." << std::endl; }
	}


	std::cout << std::endl << "=== Destroying all the squads, and the spacemarines in it. 18 spacemarines should die! (6 per squad) ===" << std::endl;
	delete (alpha);
	delete (beta);
	delete (teta);
	return (0);
}
