/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:25:39 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 15:46:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _IQ(100)
{}

Brain::Brain(int IQ): _IQ(IQ)
{}

Brain::~Brain()
{}

std::string	Brain::identify(void) const
{
	std::ostringstream	oss;

	oss << this;
	return (oss.str());
}
