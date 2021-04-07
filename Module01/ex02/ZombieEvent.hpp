/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:40:36 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 13:58:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

#include <iostream>
#include "Zombie.hpp"
#include <stdlib.h>
#include <time.h>

class	ZombieEvent
{
	public:
		ZombieEvent();
		~ZombieEvent();

		Zombie	*newZombie(std::string name);
		Zombie	*randomChump(void);

		std::string	get_type(void);
		void		setZombieType(std::string type);

	private:
		std::string	_type;

};

#endif
