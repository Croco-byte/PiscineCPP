/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:04:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 19:50:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class	Sorcerer
{
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);
		~Sorcerer();
		Sorcerer & operator=(Sorcerer const & rhs);

		void				polymorph(Victim const & victim);

		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;

	private:
		Sorcerer();

		std::string		_name;
		std::string		_title;

};

std::ostream &	operator<<(std::ostream & out, Sorcerer const & input);



#endif
