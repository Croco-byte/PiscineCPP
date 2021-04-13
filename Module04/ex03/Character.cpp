/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:26:18 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:19:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("")
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = 0;
}

Character::Character(std::string const & name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = 0;
}

Character::Character(Character const & src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (src._materias[i])
				this->_materias[i] = src._materias[i]->clone();
			else
				this->_materias[i] = 0;
		}
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete (this->_materias[i]);
			this->_materias[i] = 0;
		}
	}
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
			{
				delete (this->_materias[i]);
				this->_materias[i] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs._materias[i])
				this->_materias[i] = rhs._materias[i]->clone();
			else
				this->_materias[i] = 0;
		}
	}
	return (*this);
}

void	Character::equip(AMateria * m)
{
	int	i;

	i = 0;
	while (i < 4 && this->_materias[i] != 0)
		i++;
	if (i < 4)
		this->_materias[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx > 4 || idx < 0)
		return ;
	this->_materias[idx] = 0;
}


void	Character::use(int idx, ICharacter & target)
{
	if (idx > 4 || idx < 0)
		return ;
	if (this->_materias[idx])
		this->_materias[idx]->use(target);
}


std::string const &	Character::getName() const
{ return (this->_name); }


void	Character::displayMaterias(void) const
{
	std::cout << "> Materias of " << this->_name << ": |";
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			std::cout << this->_materias[i]->getType();
			std::cout << ", xp = " << this->_materias[i]->getXP();
		}
		else
			std::cout << "empty";
		if (i != 3)
			std::cout << "| |";
		else
			std::cout << "|" << std::endl;
	}
}
