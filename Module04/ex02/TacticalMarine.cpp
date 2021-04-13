/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:58:51 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 13:10:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for action!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	(void)src;
	std::cout << "Tactical Marine ready for action!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine &	TacticalMarine::operator=(TacticalMarine const & rhs)
{
	(void)rhs;
	return (*this);
}

ISpaceMarine *	TacticalMarine::clone() const
{
	ISpaceMarine *new_clone = new TacticalMarine;
	return (new_clone);
}

void			TacticalMarine::battleCry() const
{
	std::cout << "For the Holy PLOT!" << std::endl;
}

void			TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
