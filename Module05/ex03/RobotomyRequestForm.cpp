/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:47:40 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 14:06:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src), _target(src._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::executeCheck(executor);
	std::cout << "Bureaucrat " << executor.getName() << " executes " << this->getName() << "." << std::endl;

	int		success;

	success = rand() % 2;
	if (success)
		std::cout << "Bzzzzzzzz... Prrrrr..... Robotomy of " << this->_target << " was a success!" << std::endl;
	else
		std::cout << "Bzzzzzzzz... Prrrr.... CRACK! Robotomy of " << this->_target << " failed. Oops." << std::endl;
}
