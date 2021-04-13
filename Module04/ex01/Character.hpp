/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:38:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 13:44:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character
{
	public:
		Character(std::string const & name);
		Character(Character const & src);
		~Character();
		Character & operator=(Character const & rhs);

		void	recoverAP();
		void	equip(AWeapon* weapon);
		void	attack(Enemy*& target);

		std::string	const & getName(void) const;
		int					getAP(void) const;
		AWeapon* const &	getWeapon(void) const;

	private:
		Character();

		std::string	_name;
		int			_ap;
		AWeapon*	_weapon;

};

std::ostream & operator<<(std::ostream & out, Character const & input);

#endif
