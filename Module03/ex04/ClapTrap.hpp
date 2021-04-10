/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:53:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 17:02:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(std::string const & name);
		ClapTrap(int HP, int maxHP, int EP, int maxEP, int level, std::string name, int melee, int range, int armor);
		ClapTrap(ClapTrap const & src);
		virtual ~ClapTrap();

		ClapTrap &	operator=(ClapTrap const & rhs);

		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		displayStatus(void) const;

		std::string	getName(void) const;

	protected:
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
