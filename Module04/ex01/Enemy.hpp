/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:02:11 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 13:31:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class	Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy();
		Enemy & operator=(Enemy const & rhs);

		virtual void	takeDamage(int amount);
		void			displayStatus(void);

		std::string const & getType(void) const;
		bool				isDead(void) const;

	protected:
		Enemy();

		int			_hp;
		std::string	_type;
		bool		_dead;

	
};



#endif
