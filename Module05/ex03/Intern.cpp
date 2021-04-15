/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:34:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 15:30:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern::~Intern()
{}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

AForm *	Intern::makeForm(std::string const & type, std::string const & target)
{
	typedef AForm *		(*func)(std::string const & target);
	typedef struct	s_FormType
	{
		func		func;
		std::string	type;
	}				t_FormType;

	t_FormType	forms[] = {
		{&createRobotomyForm, "RobotomyRequestForm"},
		{&createShrubberyForm, "ShrubberyCreationForm"},
		{&createPresidentialForm, "PresidentialPardonForm"}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].type == type)
		{
			std::cout << "Intern creates " << type << "." << std::endl;
			return (forms[i].func(target));
		}
	}
	std::cout << "Intern couldn't create the form : incorrect form type." << std::endl;
	return (0);
}

AForm *		Intern::createRobotomyForm(std::string const & target)
{ return (new RobotomyRequestForm(target)); }

AForm *		Intern::createShrubberyForm(std::string const & target)
{ return (new ShrubberyCreationForm(target)); }

AForm *	Intern::createPresidentialForm(std::string const & target)
{ return (new PresidentialPardonForm(target)); }
