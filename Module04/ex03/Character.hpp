/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:07:39 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 10:09:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character();
		Character & operator=(Character const & rhs);

		virtual void	equip(AMateria * m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter & target);

		virtual std::string const &	getName() const;

		virtual void	displayMaterias(void) const;

	private:
		Character();

		std::string	_name;
		AMateria *	_materias[4];
};


#endif
