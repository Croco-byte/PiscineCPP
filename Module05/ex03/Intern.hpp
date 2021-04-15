/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:27:22 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 15:21:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const & rhs);

		AForm *	makeForm(std::string const & type, std::string const & target);

		static AForm *		createRobotomyForm(std::string const & target);
		static AForm *		createShrubberyForm(std::string const & target);
		static AForm *	createPresidentialForm(std::string const & target);
};



#endif
