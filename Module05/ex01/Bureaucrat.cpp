/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:11:01 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:57:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Undefined"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src): _name(src._name), _grade(src._grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (*this);
}

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->_name << " signs form " << form.getName() << "." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " can't sign form " << form.getName() << " because his grade is too low (bureaucrat grade " << this->_grade << ", form signature requires " << form.getSignGrade() << ")." << std::endl;
	}
}


/* --- ACCESSORS --- */
std::string const & Bureaucrat::getName(void) const
{ return (this->_name); }

int					Bureaucrat::getGrade(void) const
{ return (this->_grade); }

/* --- MUTATORS --- */
void				Bureaucrat::incGrade(int nb)
{
	this->_grade -= nb;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void				Bureaucrat::decGrade(int nb)
{
	this->_grade += nb;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* --- EXCEPTION GRADE TOO HIGH --- */
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade of bureaucrat is too high!");
}

/* --- EXCEPTION GRADE TOO LOW --- */
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade of bureaucrat is too low!");
}


/* --- DISPLAY OPERATOR --- */
std::ostream & operator<<(std::ostream & out, Bureaucrat const & input)
{
	std::cout << input.getName() << ", bureaucrat grade " << input.getGrade() << "." << std::endl;
	return (out);
}
