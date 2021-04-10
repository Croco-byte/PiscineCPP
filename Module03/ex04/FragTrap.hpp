/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:46:08 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 11:33:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		virtual ~FragTrap();

		FragTrap & operator=(FragTrap const & rhs);

		/* Overrides functions of parent class with specific messages */
		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);

		/* New functions of the child class */
		void		vaulthunter_dot_exe(std::string const & target);


	private:
		/* All attributes defined in parent class */

	protected:
		static const int	_fragHitPoints		= 100;
		static const int	_fragMaxHitPoints	= 100;
		static const int	_fragRangeDmg		= 20;
		static const int	_fragArmorRed		= 5;

};


#endif
