/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:28:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 15:34:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	std::cout << "=== Creating an intern ===" << std::endl;
	Intern intern;

	std::cout << std::endl << "=== Making the intern create a Shrubbery Creation Form ===" << std::endl;
	AForm * shrub = intern.makeForm("ShrubberyCreationForm", "SweetHome");

	std::cout << std::endl << "=== Making the intern create a Presidential Pardon Form and a Robotomy Request Form ===" << std::endl;
	AForm *robo = intern.makeForm("RobotomyRequestForm", "Innocent Victim");
	AForm *pres = intern.makeForm("PresidentialPardonForm", "Machiavel");

	std::cout << std::endl << "=== Displaying all the forms created to ensure they are of the right type ===" << std::endl;
	std::cout << *shrub << *robo << *pres;

	std::cout << std::endl << "=== Making the intern create an unknown form ===" << std::endl;
	AForm *unknown = intern.makeForm("SomeRandomForm", "RandomTarget");

	std::cout << std::endl << "=== Making a high rank bureaucrat sign and execute the forms to ensure everything works ===" << std::endl;
	Bureaucrat god("God", 1);
	god.signForm(*shrub);
	god.signForm(*robo);
	god.signForm(*pres);
	god.executeForm(*shrub);
	god.executeForm(*robo);
	god.executeForm(*pres);



	delete (shrub);
	delete (robo);
	delete (pres);
	delete (unknown);
	return (0);
}
