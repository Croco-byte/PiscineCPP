/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:57:43 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 14:06:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src), _target(src._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::executeCheck(executor);
	std::cout << "Bureaucrat " << executor.getName() << " executes " << this->getName() << "." << std::endl;
	std::cout << this->_target << " was pardonned by Zafod Beeblebrox" << std::endl;
}
