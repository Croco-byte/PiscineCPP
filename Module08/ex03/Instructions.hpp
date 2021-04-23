/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:26:29 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 20:45:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

#include "IInstruction.hpp"

class	MoveRight: public IInstruction
{
	public:
		MoveRight() {}
		virtual ~MoveRight() {}
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
};

class	MoveLeft: public IInstruction
{
	public:
		MoveLeft() {}
		virtual ~MoveLeft() {}
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
};

class	Increment: public IInstruction
{
	public:
		Increment() {}
		virtual ~Increment() {}
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
};

class	Decrement: public IInstruction
{
	public:
		Decrement() {}
		virtual ~Decrement() {}
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
};

class	Display: public IInstruction
{
	public:
		Display() {}
		virtual ~Display() {}
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
};

class	Input: public IInstruction
{
	public:
		Input() {}
		virtual ~Input() {}
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
};

class	OpenBracket: public IInstruction
{
	public:
		OpenBracket(std::stack<int> & brackets, unsigned int pos);
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
		void			setCorr(unsigned int pos);
		unsigned int	getCorr(void) const;
	
	private:
		unsigned int	_corr;
};

class	CloseBracket: public IInstruction
{
	public:
		CloseBracket(std::stack<int> & brackets, std::vector<IInstruction *> & instr, unsigned int pos);
		virtual void	execute(char * data, unsigned short & ptr, unsigned int & ip) const;
		unsigned int	getCorr(void) const;

	private:
		unsigned int	_corr;
};


#endif
