/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:56:48 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 12:57:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"


class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

#endif
