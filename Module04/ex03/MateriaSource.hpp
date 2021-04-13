/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:11:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 13:35:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource();
		MateriaSource & operator=(MateriaSource const & rhs);

		virtual void		learnMateria(AMateria* source);
		virtual AMateria *	createMateria(std::string const & type);

		virtual void	displayTemplates(void) const;

	private:
		AMateria*	_templates[4];
};

#endif
