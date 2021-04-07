/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poney.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:36:29 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 19:37:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONEY_H
# define PONEY_H

#include <iostream>

class Poney
{
public:
	Poney(std::string name, std::string fav_meal, int age, std::string color);
	~Poney();

	std::string		get_name(void);
	std::string		get_fav_meal(void);
	int				get_age(void);
	std::string		get_color(void);

	void			set_name(std::string new_name);
	void			set_fav_meal(std::string new_fav);

protected:
	std::string		_name;
	std::string		_fav_meal;
	int				_age;
	std::string		_color;
};

#endif
