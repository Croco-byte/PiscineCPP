/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:34:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:34:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int		main(void)
{
	std::cout << "=== CREATING NEW (empty) MATERIA SOURCE ===" << std::endl;
	IMateriaSource * src = new MateriaSource();

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();

	std::cout << std::endl << "=== MAKING SOURCE LEARN ICE AND CURE TEMPLATES ===" << std::endl;
	src->learnMateria(new Ice);
	src->learnMateria(new Cure);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();

	std::cout << std::endl << "=== CREATING A NEW CHARACTER, SAM ===" << std::endl;
	Character * sam = new Character("sam");

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== CREATING CURE AND ICE MATERIAS FROM SOURCE, AND MAKE SAM EQUIP THEM ===" << std::endl;
	AMateria * tmp;
	AMateria * remember;
	tmp = src->createMateria("ice");
	sam->equip(tmp);
	tmp = src->createMateria("cure");
	sam->equip(tmp);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== CREATING A NEW CHARACTER BOB, AND MAKING SAM USE HIS MATERIAS ON BOB ===" << std::endl;
	ICharacter * bob = new Character("bob");
	sam->use(0, *bob);
	sam->use(1, *bob);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== CREATING TWO MORE \"ICE\" MATERIAS, ASSIGNING THEM TO SAM, AND MAKING SAME USE ALL HIS MATERIAS ON BOB ===" << std::endl;
	tmp = src->createMateria("ice");
	remember = tmp;
	sam->equip(tmp);
	tmp = src->createMateria("ice");
	sam->equip(tmp);
	for (int i = 0; i < 4; i++)
		sam->use(i, *bob);
	
	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== UNEQUIPING THE THIRD MATERIA OF SAM, AND MAKING SAM USE ALL HIS MATERIAS ON BOB ===" << std::endl;
	sam->unequip(2);
	for (int i = 0; i < 4; i++)
		sam->use(i, *bob);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== RE-EQUIPING THE THIRD MATERIA OF SAM ===" << std::endl;
	sam->equip(remember);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== [COPY CONSTRUCTOR] CREATING ANOTHER CHARACTER THAT IS A COPY OF SAM ===" << std::endl;
	ICharacter * copy = new Character(*sam);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();
	copy->displayMaterias();
	delete (copy);

	std::cout << std::endl << "=== [ASSIGNATION] CREATING A NEW CHARACTER, THEN USING THE ASSIGNATION OPERATOR COPY = SAM ===" << std::endl;
	Character * assigned = new Character("assigned");
	*assigned = *sam;

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();
	assigned->displayMaterias();
	delete (assigned);

	std::cout << std::endl << "=== [ERROR HANDLING] TRYING TO MAKE SAM EQUIP ANOTHER MATERIA WHEN HE ALREADY HAS 4 ===" << std::endl;
	tmp = src->createMateria("cure");
	sam->equip(tmp);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();
	delete(tmp);

	std::cout << std::endl << "=== [ERROR HANDLING] TRYING TO MAKE SAM EQUIP A NULL MATERIA ===" << std::endl;
	sam->equip(0);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== [ERROR HANDLING] TRYING TO MAKE THE SOURCE CREATE AN UNKNOWN MATERIA ===" << std::endl;
	tmp = src->createMateria("fire");

	std::cout << "--> Source returns " << tmp << std::endl;

	std::cout << std::endl << "=== [ERROR HANDLING] TRYING TO MAKE THE SOURCE LEARN ANOTHER MATERIA WHEN IT ALREADY HAS 4 TEMPLATES ===" << std::endl;
	src->learnMateria(new Ice);
	src->learnMateria(new Cure);
	src->learnMateria(new Ice);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	std::cout << std::endl << "=== [ERROR HANDLING] TRYING TO MAKE SAM USE A MATERIA AT NON-EXISTING INDEX, AND AN EMPTY SLOT OF HIS INVENTORY ===" << std::endl;
	sam->use(6, *bob);
	sam->unequip(2);
	sam->use(2, *bob);
	sam->equip(remember);

	std::cout << std::endl << "=== STATS ===" << std::endl;
	src->displayTemplates();
	sam->displayMaterias();

	delete (src);
	delete (sam);
	delete (bob);

	return (0);
}
