/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:29:13 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 11:37:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(): _name(""), _apcost(0), _damage(0)
{}

AWeapon::AWeapon(std::string const & name, int apcost, int damage): _name(name), _apcost(apcost), _damage(damage)
{}

AWeapon::AWeapon(AWeapon const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_apcost = src._apcost;
		this->_damage = src._damage;
	}
}

AWeapon::~AWeapon()
{}

AWeapon &	AWeapon::operator=(AWeapon const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_apcost = rhs._apcost;
		this->_damage = rhs._damage;
	}
	return (*this);
}



/* --- ACCESSORS --- */
std::string const &	AWeapon::getName(void) const
{ return (this->_name); }

int					AWeapon::getAPCost(void) const
{ return (this->_apcost); }

int					AWeapon::getDamage(void) const
{ return (this->_damage); }
