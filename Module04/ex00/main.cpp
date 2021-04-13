/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:21:09 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:19:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Traveller.hpp"

int		main(void)
{
	Sorcerer	robert("Robert", "The Magnificent");

	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Traveller	jack("Jack");

	std::cout << robert << jim << joe << jack;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(jack);

	return (0);
}
