/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:08:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 10:08:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class	ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const &	getName() const = 0;
		virtual void	equip(AMateria * m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter & target) = 0;

		virtual void	displayMaterias(void) const = 0;

};

#endif
