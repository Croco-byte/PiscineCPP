/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:28:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 14:01:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	std::cout << std::endl << "=== CREATING THREE BUREAUCRATS WITH GRADE 1, 60, and 150 ===" << std::endl;
	Bureaucrat	god("God", 1);
	Bureaucrat	sam("Sam", 60);
	Bureaucrat	bob("Bob", 150);
	std::cout << god << sam << bob;

	std::cout << std::endl << "=== CREATING A SHRUBBERY CREATION FORM, A ROBOTOMY REQUEST FORM, AND A PRESIDENTIAL PARDON FORM ===" << std::endl;
	ShrubberyCreationForm	shrub("SweetHome");
	RobotomyRequestForm		robo("Innocent Victim");
	PresidentialPardonForm	pres("Machiavel");
	std::cout << shrub << robo << pres;

	std::cout << std::endl << "=== TRYING TO EXECUTE THE SHRUBBERY CREATION FORM ===" << std::endl;
	bob.executeForm(shrub);

	std::cout << std::endl << "=== MAKING BOB SIGN THE SHRUBBERY CREATION FORM ===" << std::endl;
	bob.signForm(shrub);

	std::cout << std::endl << "=== MAKING GOD SIGN THE SHRUBBERY CREATION FORM ===" << std::endl;
	god.signForm(shrub);

	std::cout << std::endl << "=== MAKING BOB EXECUTE THE SHRUBBERY CREATION FORM ===" << std::endl;
	bob.executeForm(shrub);

	std::cout << std::endl << "=== MAKING SAM EXECUTE THE SHRUBBERY CREATION FORM ===" << std::endl;
	sam.executeForm(shrub);

	std::cout << std::endl << "=== MAKING SAM EXECUTE THE SHRUBBERY CREATION FORM, ON AN INVALID FILE ===" << std::endl;
	system("chmod -w SweetHome_shrubbery");
	sam.executeForm(shrub);

	std::cout << std::endl << "=== MAKING SAM SIGN THE ROBOTOMY REQUEST FORM ===" << std::endl;
	sam.signForm(robo);

	std::cout << std::endl << "=== MAKING SAM EXECUTE THE ROBOTOMY REQUEST FORM ===" << std::endl;
	sam.executeForm(robo);

	std::cout << std::endl << "=== MAKING GOD EXECUTE THE ROBOTOMY REQUEST FORM, THREE TIMES ===" << std::endl;
	god.executeForm(robo);
	god.executeForm(robo);
	god.executeForm(robo);

	std::cout << std::endl << "=== MAKING GOD EXECUTE THE PRESIDENTIAL PARDON FORM ===" << std::endl;
	god.executeForm(pres);

	std::cout << std::endl << "=== MAKING GOD SIGN THE PRESIDENTIAL PARDON FORM, THEN EXECUTE IT ===" << std::endl;
	god.signForm(pres);
	god.executeForm(pres);

	return (0);
}
