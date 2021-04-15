/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:24 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:49:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;
class	Form;

class	Form
{
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & src);
		~Form();
		Form & operator=(Form const & rhs);

		void	beSigned(Bureaucrat const & bureaucrat);

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

		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;


	private:
		Form();

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream &	operator<<(std::ostream & out, Form const & input);

#endif
