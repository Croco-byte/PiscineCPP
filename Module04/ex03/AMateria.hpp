/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:25:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 16:27:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & rhs);

		virtual AMateria *	clone() const = 0;
		virtual void		use(ICharacter & target);

		std::string const &	getType(void) const;
		unsigned int		getXP(void) const;

	protected:
		AMateria();

		unsigned int	_xp;
		std::string		_type;
};


#endif
