/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:47:36 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 15:25:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const & src);
		virtual ~NinjaTrap();

		NinjaTrap & operator=(NinjaTrap const & rhs);

		/* Overrides functions of parent class with specific messages */
		void		meleeAttack(std::string const & target);
		void		rangedAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		/* New functions of the child class */
		void		ninjaShoebox(ClapTrap const & clap);
		void		ninjaShoebox(FragTrap const & clap);
		void		ninjaShoebox(ScavTrap const & clap);
		void		ninjaShoebox(NinjaTrap const & clap);
};


#endif
