/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:30:34 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 13:08:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

typedef struct	s_unit
{
	ISpaceMarine*	spacemarine;
	struct s_unit*	next;
}				t_unit;


class	Squad: public ISquad
{
	public:
		Squad();
		Squad(Squad const & src);
		~Squad();
		Squad & operator=(Squad const & src);

		virtual int	push(ISpaceMarine * spacemarine);

		virtual int				getCount(void) const;
		virtual ISpaceMarine *	getUnit(int index) const;

		static t_unit*	ft_lstlast(t_unit *lst);
		static void		ft_lstadd_back(t_unit **begin, t_unit *new_unit);

		void			displayAllUnits(void);

	private:
		int		_count;
		t_unit*	_units_list;



};



#endif
