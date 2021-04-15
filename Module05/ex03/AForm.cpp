/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:32:32 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:54:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Unknown"), _signed(false), _signGrade(1), _execGrade(1)
{}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src): _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{}

AForm & AForm::operator=(AForm const & rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::executeCheck(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
}



/* --- GRADE TOO HIGH EXCEPTION --- */
const char * AForm::GradeTooHighException::what(void) const throw()
{
	return ("ERROR: Grade is too high for the form!");
}

/* --- GRADE TOO LOW EXCEPTION --- */
const char * AForm::GradeTooLowException::what(void) const throw()
{
	return ("ERROR: Grade is too low for the form!");
}

/* --- FORM NOT SIGNED EXCEPTION --- */
const char * AForm::FormNotSigned::what(void) const throw()
{
	return ("ERROR: the form isn't signed!");
}

/* --- ACCESSORS --- */

std::string	AForm::getName(void) const
{ return (this->_name); }

bool		AForm::isSigned(void) const
{ return (this->_signed); }

int			AForm::getSignGrade(void) const
{ return (this->_signGrade); }

int			AForm::getExecGrade(void) const
{ return (this->_execGrade); }






/* --- DISPLAY OPERATOR --- */
std::ostream &	operator<<(std::ostream & out, AForm const & input)
{
	std::cout << "Informations regarding " << input.getName() << ":	|Grade to sign = " << input.getSignGrade() << "| |Grade to execute = " << input.getExecGrade() << "| |Is signed = " << input.isSigned() << "|" << std::endl;
	return (out);
}
