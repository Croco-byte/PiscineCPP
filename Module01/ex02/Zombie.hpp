/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:41:36 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 19:51:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		Zombie(std::string name, std::string type);
		~Zombie();

		void	announce(void);

		void	set_name(std::string name);
		void	set_type(std::string type);

		std::string	get_name(void);
		std::string	get_type(void);


	private:
		std::string	_name;
		std::string	_type;
};



#endif
