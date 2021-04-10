/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:21:44 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 11:34:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap: public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & src);
		~SuperTrap();

		SuperTrap & operator=(SuperTrap const & rhs);

		void	meleeAttack(std::string const & target);
		void	rangedAttack(std::string const & target);

	private:


};



#endif
