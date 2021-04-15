/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:28:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 17:51:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	std::cout << std::endl << "=== CREATING A VALID BUREAUCRAT OF GRADE 24 ===" << std::endl;
	Bureaucrat bob("bob", 24);

	std::cout << bob;

	std::cout << std::endl << "=== CREATING A BUREAUCRAT WITH A GRADE TOO HIGH (0) ===" << std::endl;
	try
	{
		Bureaucrat sam("sam", 0);
		std::cout << "This should never be displayed." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== CREATING A BUREAUCRAT WITH A GRADE TOO LOW (151) ===" << std::endl;
	try
	{
		Bureaucrat max("max", 151);
		std::cout << "This should never be displayed." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== CREATING A BUREAUCRAT WITH THE HIGHEST POSSIBLE GRADE (1)" << std::endl;
	Bureaucrat tom("tom", 1);
	std::cout << tom;

	std::cout << std::endl << "=== TRYING TO INCREASE THE GRADE OF THE BUREAUCRAT THAT ALREADY HAS HIGHEST POSSIBLE GRADE ===" << std::endl;
	try
	{
		tom.incGrade(3);
		std::cout << "This should never be displayed." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== CREATING A BUREAUCRAT WITH THE LOWEST POSSIBLE GRADE (150)" << std::endl;
	Bureaucrat jean("jean", 150);
	std::cout << jean;

	std::cout << std::endl << "=== TRYING TO LOWER THE GRADE OF THE BUREAUCRAT THAT ALREADY HAS LOWEST POSSIBLE GRADE ===" << std::endl;
	try
	{
		jean.decGrade(1);
		std::cout << "This should never be displayed." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
