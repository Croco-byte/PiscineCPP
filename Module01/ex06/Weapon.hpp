/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:14:13 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:32:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string&	get_type(void);
		void				setType(std::string);

	private:
		std::string	_type;

};

#endif
