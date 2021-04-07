/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:27:25 by user42            #+#    #+#             */
/*   Updated: 2021/04/06 14:39:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Zombie.hpp"

class	ZombieHorde
{
	public:
		ZombieHorde(int n);
		~ZombieHorde();

		void	setRandName(Zombie& zombie);
		void	announce(void);

	protected:
		int		_n;
		Zombie	*_zombies;
};



#endif
