/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:31:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 12:17:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;

};

#endif
