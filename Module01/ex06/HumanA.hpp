/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:12:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:32:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack(void);

	private:
		std::string	_name;
		Weapon&		_weapon;

};

#endif
