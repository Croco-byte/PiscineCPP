/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:02:18 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:14:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(): Victim()
{}

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog Zog." << std::endl;
}

Peon::Peon(Peon const & src): Victim(src)
{
	std::cout << "Zog Zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &	Peon::operator=(Peon const & rhs)
{
	if (this != &rhs)
		Victim::operator=(rhs);
	return (*this);
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " was just polymorphed into a pink pony!" << std::endl;
}
