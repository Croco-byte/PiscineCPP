/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:24:18 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:32:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._templates[i])
			this->_templates[i] = src._templates[i]->clone();
		else
			this->_templates[i] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
		{
			delete (this->_templates[i]);
			this->_templates[i] = 0;
		}
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
		{
			delete (this->_templates[i]);
			this->_templates[i] = 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (rhs._templates[i])
			this->_templates[i] = rhs._templates[i]->clone();
	}
	return (*this);
}


void		MateriaSource::learnMateria(AMateria* source)
{
	int	i;

	i = 0;
	while (i < 4 && this->_templates[i] != 0)
		i++;
	if (i < 4 && source)
		this->_templates[i] = source;
	if (i == 4)
		delete (source);
}

AMateria *	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
		{
			if (type == "ice")
				return (new Ice);
			if (type == "cure")
				return (new Cure);
		}
	}
	return (0);
}


void	MateriaSource::displayTemplates(void) const
{
	std::cout << "> Templates of source: |";
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
			std::cout << this->_templates[i]->getType();
		else
			std::cout << "empty";
		if (i != 3)
			std::cout << "| |";
		else
			std::cout << "|" << std::endl;
	}
}
