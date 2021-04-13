/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:23:04 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 13:08:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class	AWeapon
{
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		virtual ~AWeapon();
		AWeapon &	operator=(AWeapon const & rhs);

		virtual void	attack() const = 0;

		std::string const &	getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;
	
	protected:
		AWeapon();

		std::string	_name;
		int			_apcost;
		int			_damage;
};


#endif
