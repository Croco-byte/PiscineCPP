/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:53:21 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 12:39:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

class	ScavTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		virtual ~ScavTrap();

		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		challengeNewcomer(std::string const & target);
		void		displayStatus(void) const;

		ScavTrap & operator=(ScavTrap const & rhs);

	private:
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		std::string	_name;
		int			_meleeDmg;
		int			_rangeDmg;
		int			_armorReduction;

};


#endif
