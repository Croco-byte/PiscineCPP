/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:38:34 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 15:57:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(): _brain(120)
{

}

Human::~Human()
{
}

std::string	Human::identify(void)
{
	return (this->_brain.identify());
}

const Brain&	Human::getBrain(void)
{
	return (this->_brain);
}
