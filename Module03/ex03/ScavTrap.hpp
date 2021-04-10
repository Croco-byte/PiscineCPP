/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:53:21 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 13:30:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		virtual ~ScavTrap();

		ScavTrap &	operator=(ScavTrap const & rhs);

		/* Overrides functions of parent class */
		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		/* New function of child class */
		void		challengeNewcomer(std::string const & target);

	private:

};


#endif
