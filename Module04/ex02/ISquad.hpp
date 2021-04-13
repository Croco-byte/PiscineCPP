/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:28:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 15:32:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class	ISquad
{
	public:
		virtual ~ISquad() {};
		virtual int	getCount() const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;
		virtual int	push(ISpaceMarine*) = 0;
};



#endif
