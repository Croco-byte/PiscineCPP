/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:50:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 14:57:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human human;

	try
	{
		human.action("meleeAttack", "Skeleton");
		human.action("rangedAttack", "Evil Sorcerer");
		human.action("intimidatingShout", "Dragon");
		human.action("Fireball", "Barbarian");
	}
	catch(std::string& error)
	{
		std::cerr << error << std::endl;
	}
}
