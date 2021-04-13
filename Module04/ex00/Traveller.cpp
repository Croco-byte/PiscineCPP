/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Traveller.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:17:41 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:18:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Traveller.hpp"


Traveller::Traveller(): Victim()
{}

Traveller::Traveller(std::string name): Victim(name)
{
	std::cout << "Voyage voyage!" << std::endl;
}

Traveller::Traveller(Traveller const & src): Victim(src)
{
	std::cout << "Voyage voyage!" << std::endl;
}

Traveller::~Traveller()
{
	std::cout << "Adios..." << std::endl;
}

Traveller &	Traveller::operator=(Traveller const & rhs)
{
	if (this != &rhs)
		Victim::operator=(rhs);
	return (*this);
}

void	Traveller::getPolymorphed(void) const
{
	std::cout << this->_name << " was just polymorphed into a small frog!" << std::endl;
}
