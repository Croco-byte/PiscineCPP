/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:37:41 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 14:06:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src), _target(src._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::executeCheck(executor);
	std::cout << "Bureaucrat " << executor.getName() << " executes " << this->getName() << "." << std::endl;
	std::string	fileName(this->_target + "_shrubbery");
	std::ofstream	ofs(fileName.c_str());
	if (!ofs)
		throw std::ios_base::failure("Couldn't open shrubbery file");
	ofs << "            ,@@@@@@@," << std::endl;
	ofs << "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl,
	ofs << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "    |o|        | |         | |" << std::endl;
	ofs << "    |.|        | |         | |" << std::endl;
	ofs << "  \\/ ._\\//_/__/  ,\\ _//__\\/.  \\_//__/_" << std::endl;
}
