/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:39:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 14:57:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{}

Human::~Human()
{}

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Human attacks " << target << " at melee range" << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Human attacks " << target << " from afar" << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Human SHOUTS on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	int		key;
	void	(Human::*actions[3])(std::string const & target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	key =	(action_name == "meleeAttack") ? 0 :
			(action_name == "rangedAttack") ? 1 :
			(action_name == "intimidatingShout") ? 2 :
			throw std::string("[X] Error: Invalid action name");
	(this->*actions[key])(target);
}
