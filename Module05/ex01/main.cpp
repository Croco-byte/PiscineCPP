/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:28:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:59:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	std::cout << ("=== CREATING THREE BUREAUCRATS WITH GRADE 1, 80, and 150 ===") << std::endl;
	Bureaucrat	god("God", 1);
	Bureaucrat	sam("Sam", 80);
	Bureaucrat	bob("Bob", 150);

	std::cout << god << sam << bob;

	std::cout << std::endl << "=== TRYING TO CREATE A FORM WITH A SIGN GRADE THAT IS TOO LOW (0) ===" << std::endl;
	try
	{
		Form toolow("TooLow", 0, 23);
		std::cout << "This should never be displayed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== TRYING TO CREATE A FORM WITH AN EXEC GRADE THAT IS TOO HIGH (151) ===" << std::endl;
	try
	{
		Form toohigh("TooHigh", 15, 151);
		std::cout << "This should never be displayed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=== CREATING TWO VALID FORMS, A340 and F13 ===" << std::endl;
	Form a340("A340", 20, 15);
	Form f13("F13", 80, 75);

	std::cout << a340 << f13;

	std::cout << std::endl << "=== MAKING GOD SIGN A340 ===" << std::endl;
	god.signForm(a340);
	std::cout << a340;

	std::cout << std::endl << "=== MAKING BOB TRY TO SIGN F13 ===" << std::endl;
	bob.signForm(f13);
	std::cout << f13;

	std::cout << std::endl << "=== MAKING SAM SIGN F13 ===" << std::endl;
	sam.signForm(f13);
	std::cout << f13;

	std::cout << std::endl << "=== BOTH FORMS SHOULD BE SIGNED NOW ===" << std::endl;
	std::cout << a340 << f13;


	


	return (0);
}
