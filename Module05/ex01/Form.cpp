/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:32:32 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:54:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Unknown"), _signed(false), _signGrade(1), _execGrade(1)
{}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src): _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{}

Form & Form::operator=(Form const & rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}


/* --- GRADE TOO HIGH EXCEPTION --- */
const char * Form::GradeTooHighException::what(void) const throw()
{
	return ("ERROR: Grade is too high for the form!");
}

/* --- GRADE TOO LOW EXCEPTION --- */
const char * Form::GradeTooLowException::what(void) const throw()
{
	return ("ERROR: Grade is too low for the form!");
}

/* --- ACCESSORS --- */

std::string	Form::getName(void) const
{ return (this->_name); }

bool		Form::isSigned(void) const
{ return (this->_signed); }

int			Form::getSignGrade(void) const
{ return (this->_signGrade); }

int			Form::getExecGrade(void) const
{ return (this->_execGrade); }






/* --- DISPLAY OPERATOR --- */
std::ostream &	operator<<(std::ostream & out, Form const & input)
{
	std::cout << "Informations regarding Form " << input.getName() << ":	|Grade to sign = " << input.getSignGrade() << "| |Grade to execute = " << input.getExecGrade() << "| |Is signed = " << input.isSigned() << "|" << std::endl;
	return (out);
}
