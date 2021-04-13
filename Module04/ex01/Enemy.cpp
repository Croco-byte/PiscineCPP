/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:05:54 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 14:52:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(): _hp(0), _type(""), _dead(false)
{}

Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type), _dead(false)
{}

Enemy::Enemy(Enemy const & src)
{
	if (this != &src)
	{
		this->_hp = src._hp;
		this->_type = src._type;
	}
}

Enemy::~Enemy()
{}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_type = rhs._type;
	}
	return (*this);
}

void	Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return ;
	this->_hp -= amount;
	if (this->_hp <= 0)
	{
		this->_dead = true;
		this->_hp = 0;
	}
}

void	Enemy::displayStatus(void)
{
	std::cout << "|Enemy type: " << this->_type << "|	|HP: " << this->_hp << "|" << std::endl;
}


/* --- ACCESSORS --- */
std::string const & Enemy::getType(void) const
{ return (this->_type); }

bool				Enemy::isDead(void) const
{ return (this->_dead); }

