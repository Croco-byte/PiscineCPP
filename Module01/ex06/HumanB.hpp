/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:25:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:32:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack(void);
		void	setWeapon(Weapon& weapon);

	private:
		std::string	_name;
		Weapon*		_weapon;

};

#endif
