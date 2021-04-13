/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:30:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:16:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _xp(0), _type("undefined")
{}

AMateria::AMateria(std::string const & type): _xp(0), _type(type)
{}

AMateria::AMateria(AMateria const & src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_xp = src._xp;
	}
}

AMateria::~AMateria()
{}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		this->_xp = rhs._xp;
	return (*this);
}

void		AMateria::use(ICharacter & target)
{
	(void)target;
	this->_xp += 10;
}

/* --- ACCESSORS --- */
std::string const &	AMateria::getType(void) const
{ return (this->_type); }

unsigned int		AMateria::getXP(void) const
{ return (this->_xp); }
