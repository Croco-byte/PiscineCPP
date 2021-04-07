/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:16:06 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 16:44:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{}

Weapon::~Weapon()
{}

const std::string&	Weapon::get_type(void)
{ return (this->_type); }


void				Weapon::setType(std::string type)
{ this->_type = type; }
