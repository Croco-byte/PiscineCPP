/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:24 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:49:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm;

class	AForm
{
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const & src);
		virtual ~AForm();
		AForm & operator=(AForm const & rhs);

		void			beSigned(Bureaucrat const & bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			executeCheck(Bureaucrat const & executor) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

		class FormNotSigned: public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;

	private:
		AForm();

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream &	operator<<(std::ostream & out, AForm const & input);

#endif
