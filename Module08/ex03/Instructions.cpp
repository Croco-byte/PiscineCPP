/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:41:45 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 21:03:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instructions.hpp"

/* --- MoveRight --- */
void	MoveRight::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{ ++ptr; }

/* --- MoveLeft --- */
void	MoveLeft::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{ --ptr; }

/* --- Increment --- */
void	Increment::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{ data[ptr]++; }

/* --- Decrement --- */
void	Decrement::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{ data[ptr]--; }

/* --- Display --- */
void	Display::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{ std::cout << data[ptr]; }

/* --- Input --- */
void	Input::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{ data[ptr] = getchar(); }


/* --- OpenBracket --- */
OpenBracket::OpenBracket(std::stack<int> & brackets, unsigned int pos)
{
	std::cout << "Pushing " << pos << std::endl;
	brackets.push(pos);
}

void	OpenBracket::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{
	if (data[ptr] == 0)
		ip = this->_corr;
}

void	OpenBracket::setCorr(unsigned int pos)
{ this->_corr = pos; }

unsigned int	OpenBracket::getCorr(void) const
{ return (this->_corr); }

/* --- CloseBracket --- */
CloseBracket::CloseBracket(std::stack<int> & brackets, std::vector<IInstruction *> & instr, unsigned int pos)
{
	OpenBracket * corresponding;

	corresponding = dynamic_cast<OpenBracket *>(instr[brackets.top()]);
	this->_corr = brackets.top();
	corresponding->setCorr(pos);
	std::cout << "Popping " << pos << std::endl;
	brackets.pop();
}

void	CloseBracket::execute(char * data, unsigned short & ptr, unsigned int & ip) const
{
	if (data[ptr] != 0)
		ip = this->_corr;
}

unsigned int	CloseBracket::getCorr(void) const
{ return (this->_corr); }
