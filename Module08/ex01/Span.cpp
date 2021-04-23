/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:46:44 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 12:41:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _ints(), _max(0)
{}

Span::Span(unsigned int n): _ints(), _max(n)
{}

Span::Span(Span const & src): _ints(), _max(src._max)
{
	if (this != &src)
		this->_ints = src._ints;
}

Span::~Span()
{}

Span &	Span::operator=(Span const & rhs)
{
	if (this != &rhs)
		this->_ints = rhs._ints;
	this->_max = rhs._max;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_ints.size() >= this->_max)
		throw Span::ContainerFullException();
	this->_ints.push_back(n);
}

long	Span::shortestSpan(void) const
{
	long	minDiff;
	long	diff;

	if (this->_ints.size() <= 1)
		throw Span::NoSpanPossibleException();

	std::vector<int>::const_iterator first = this->_ints.begin();
	std::vector<int>::const_iterator next = first + 1;
	minDiff = std::abs(*(next++) - *(first));

	while (first != this->_ints.end() - 1)
	{
		while (next != this->_ints.end())
		{
			diff = std::abs(*next - *first);
			if (diff < minDiff)
				minDiff = diff;
			next++;
		}
		first++;
	}

	return (minDiff);
}

long	Span::longestSpan(void) const
{
	long	max;
	long	min;
	long	result;

	if (this->_ints.size() <= 1)
		throw Span::NoSpanPossibleException();
	max = *(std::max_element(this->_ints.begin(), this->_ints.end()));
	min = *(std::min_element(this->_ints.begin(), this->_ints.end()));
	result = max - min;
	return (result);
}


void	Span::clearContent(void)
{
	this->_ints.clear();
}

void	Span::displayContent(void) const
{
	std::cout << "Content of Span[size " << this->_ints.size() << "]:	";
	for (std::vector<int>::const_iterator it = this->_ints.begin(); it != this->_ints.end(); it++)
		std::cout << "|" << *it << "| ";
	std::cout << std::endl;
}
