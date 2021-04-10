/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:46:08 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 20:37:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

class	FragTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		virtual ~FragTrap();

		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const & target);

		void		displayStatus(void) const;

		FragTrap & operator=(FragTrap const & rhs);

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
