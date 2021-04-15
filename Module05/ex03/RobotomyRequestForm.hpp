/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:46:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 13:00:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <time.h>
#include <stdlib.h>

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

#endif
