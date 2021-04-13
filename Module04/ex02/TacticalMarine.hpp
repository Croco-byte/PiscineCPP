/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:54:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 12:13:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class	TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const & src);
		virtual ~TacticalMarine();
		TacticalMarine &	operator=(TacticalMarine const & rhs);

		virtual ISpaceMarine *	clone() const;
		virtual void			battleCry() const;
		virtual void			rangedAttack() const;
		virtual void			meleeAttack() const;
};

#endif
