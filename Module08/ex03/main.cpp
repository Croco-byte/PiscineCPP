/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:20:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 21:05:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <stdio.h>
#include "Instructions.hpp"

int		main(void)
{
	char						*data = new char[300000]();
	unsigned short				ptr(0);
	unsigned int				ip(0);
	char						symbol(0);
	std::stack<int>				brackets;
	std::vector<IInstruction *>	instructions;
	std::ifstream				file("beer.bf");

	while (file.get(symbol))
	{
		switch (symbol)
		{
			case '>': instructions.push_back(new MoveRight);									break;
			case '<': instructions.push_back(new MoveLeft);										break;
			case '+': instructions.push_back(new Increment);									break;
			case '-': instructions.push_back(new Decrement);									break;
			case '.': instructions.push_back(new Display);										break;
			case ',': instructions.push_back(new Input);										break;
			case '[': instructions.push_back(new OpenBracket(brackets, ip));					break;
			case ']': instructions.push_back(new CloseBracket(brackets, instructions, ip));		break;
		}
		ip++;
	}

	ip = 0;
	while (ip < instructions.size())
	{
		instructions[ip]->execute(data, ptr, ip);
		ip++;
	}

	for (std::vector<IInstruction *>::iterator it = instructions.begin(); it != instructions.end(); it++)
		delete *it;
	delete [] data;
	return (0);
}










/* --- Working basic Brainfuck interpreter --- */

/* typedef struct	s_instr
{
	char	c;
	int		corr;
}				t_instr;

int		main(void)
{
	char			*data = new char[300000]();
	unsigned short	ptr(0);
	char			symbol(0);
	size_t			i(0);
	t_instr			instr;

	std::vector<t_instr>	instructions;
	std::stack<int>			brackets;

	std::ifstream file("beer.bf");

	while (file.get(symbol))
	{
		instr.c = symbol;
		instr.corr = -1;
		if (symbol == '[')
			brackets.push(i);
		if (symbol == ']')
		{
			instructions[brackets.top()].corr = i;
			instr.corr = brackets.top();
			brackets.pop();
		}
		instructions.push_back(instr);
		i++;
	}


	i = 0;

	while (i < instructions.size())
	{
		switch (instructions[i].c)
		{
			case '>': ++ptr;					break;
			case '<': --ptr;					break;
			case '+': data[ptr]++;				break;
			case '-': data[ptr]--;				break;
			case '.': std::cout << data[ptr];	break;
			case ',': data[ptr] = getchar();	break;
			case '[':
				if (data[ptr] == 0)
				{
					i = instructions[i].corr;
				}
				break;
			case ']':
				if (data[ptr] != 0)
				{
					i = instructions[i].corr;
				}
				break;
			default: break;
		}
		i++;
	}

	std::cout << std::endl;




	delete [] data;
	return (0);
} */
