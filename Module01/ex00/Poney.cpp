/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poney.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:44:18 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 19:03:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poney.hpp"

Poney::Poney(std::string name, std::string fav_meal, int age, std::string color) : _name(name), _fav_meal(fav_meal), _age(age), _color(color)
{
	std::cout << "A poney was created !" << std::endl;
}

Poney::~Poney()
{
	std::cout << "A poney died ! RIP" << std::endl << std::endl << std::endl;
}

void			Poney::set_name(std::string new_name)
{ this->_name = new_name; }

void			Poney::set_fav_meal(std::string new_fav)
{ this->_fav_meal = new_fav; }

std::string		Poney::get_name(void)
{ return (this->_name); }

std::string		Poney::get_fav_meal(void)
{ return (this->_fav_meal); }

int				Poney::get_age(void)
{ return (this->_age); }

std::string		Poney::get_color(void)
{ return (this->_color); }
