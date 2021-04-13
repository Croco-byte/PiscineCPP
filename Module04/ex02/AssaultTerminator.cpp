/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:15:18 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 12:17:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"


AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	(void)src;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'Il be back ..." << std::endl;
}

AssaultTerminator &	AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	(void)rhs;
	return (*this);
}

ISpaceMarine *	AssaultTerminator::clone() const
{
	ISpaceMarine *new_clone = new AssaultTerminator;

	return (new_clone);
}

void			AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. Purify it!" << std::endl;
}

void			AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void			AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
