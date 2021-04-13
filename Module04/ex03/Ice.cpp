/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:01:49 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:15:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{}

Ice::Ice(Ice const & src): AMateria(src)
{}

Ice::~Ice()
{}

Ice & Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

AMateria *	Ice::clone() const
{
	AMateria * new_materia = new Ice(*this);
	return (new_materia);
}

void		Ice::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout << "* shouts an ice bolt at " << target.getName() << " *" << std::endl;
}
