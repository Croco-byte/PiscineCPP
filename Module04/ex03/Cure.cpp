/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:53:22 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:16:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{}

Cure::Cure(Cure const & src): AMateria(src)
{}

Cure::~Cure()
{}

Cure & Cure::operator=(Cure const & rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

AMateria *	Cure::clone() const
{
	AMateria * new_materia = new Cure(*this);
	return (new_materia);
}

void		Cure::use(ICharacter & target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
