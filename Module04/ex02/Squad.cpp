/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:41:22 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 13:10:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(): _count(0), _units_list(0)
{}

Squad::Squad(Squad const & src): _count(0), _units_list(0)
{
	t_unit	*units;
	t_unit	*src_units;

	units = this->_units_list;
	src_units = src._units_list;
	for (int i = 0; i < src._count; i++)
	{
		ISpaceMarine * marine = src_units->spacemarine->clone();
		this->push(marine);
		src_units = src_units->next;
	}
}

Squad::~Squad()
{
	t_unit*	temp;

	for (int i = 0; i < this->_count; i++)
	{
		temp = this->_units_list->next;
		delete (this->_units_list->spacemarine);
		delete (this->_units_list);
		this->_units_list = temp;
	}
}

Squad & Squad::operator=(Squad const & rhs)
{
	t_unit	*units;
	t_unit	*temp;
	t_unit	*rhs_units;

	units = this->_units_list;
	rhs_units = rhs._units_list;
	while (units)
	{
		temp = units->next;
		delete (units->spacemarine);
		delete (units);
		units = temp;
	}
	this->_units_list = 0;
	this->_count = 0;
	for (int i = 0; i < rhs._count; i++)
	{
		ISpaceMarine * marine = rhs_units->spacemarine->clone();
		this->push(marine);
		rhs_units = rhs_units->next;
	}
	return (*this);
}

int	Squad::push(ISpaceMarine * spacemarine)
{
	t_unit	*new_unit;
	t_unit	*units;

	units = this->_units_list;
	if (spacemarine == 0)
		throw std::string("[X] Error: couldn't add spacemarine to squad: spacemarine can't be NULL.");
	while (units)
	{
		if (units->spacemarine == spacemarine)
			throw std::string("[X] Error: couldn't add spacemarine to squad: spacemarine already in squad.");
		units = units->next;
	}

	new_unit = new t_unit;
	new_unit->spacemarine = spacemarine;
	new_unit->next = 0;
	Squad::ft_lstadd_back(&this->_units_list, new_unit);
	this->_count += 1;
	return (this->_count);
}

t_unit*		Squad::ft_lstlast(t_unit *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void		Squad::ft_lstadd_back(t_unit **begin, t_unit *new_unit)
{
	t_unit  *last;
	if (!begin)
		return ;
	if (!*begin)
	{
		*begin = new_unit;
		return ;
	}
	last = Squad::ft_lstlast(*begin);
	last->next = new_unit;
}


int				Squad::getCount(void) const
{ return (this->_count); }

ISpaceMarine *	Squad::getUnit(int index) const
{
	t_unit	*temp;

	temp = this->_units_list;
	if (index > this->_count - 1 || index < 0)
		throw int(index);
	for (int i = 0; i < index; i++)
		temp = temp->next;
	return (temp->spacemarine);
}

void			Squad::displayAllUnits(void)
{
	t_unit	*units;
	int		i;

	units = this->_units_list;
	i = 0;
	if (this->_count == 0)
	{
		std::cout << " |empty|" << std::endl;
		return ;
	}
	while (units)
	{
		std::cout << " |spacemarine n°" << i << "|" ;
		units = units->next;
		i++;
	}
	std::cout << std::endl;
}
