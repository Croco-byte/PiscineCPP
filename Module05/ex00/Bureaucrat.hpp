/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:52:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 17:42:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>

class	Bureaucrat
{
	public:
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & src);
		virtual ~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const & getName(void) const;
		int					getGrade(void) const;

		void				incGrade(int nb);
		void				decGrade(int nb);

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *	what() const throw();
		};

	private:
		Bureaucrat();
		
		const std::string	_name;
		int					_grade;

};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & input);


#endif
