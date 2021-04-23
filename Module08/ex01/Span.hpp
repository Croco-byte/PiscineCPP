/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:25:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 12:41:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

class	Span
{
	private:
		Span();

		std::vector<int>	_ints;
		unsigned int		_max;


	public:
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span &	operator=(Span const & rhs);

		void	addNumber(int n);
		long	longestSpan(void) const;
		long	shortestSpan(void) const;

		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end);

		class ContainerFullException: public std::exception
		{
			public:
				const char *	what() const throw() { return ("ERROR: Can't add number, container already full"); }
		};

		class NotEnoughSpaceException: public std::exception
		{
			public:
				const char *	what() const throw() { return ("ERROR: Can't add range, container doesn't have enough space left"); }
		};

		class NoSpanPossibleException: public std::exception
		{
			public:
				const char *	what() const throw() { return ("ERROR: Can't find a span with 1 number or less"); }
		};

		void	clearContent(void);
		void	displayContent(void) const;

};

template <typename Iterator>
void	Span::addNumber(Iterator begin, Iterator end)
{
	if (end - begin > this->_max)
		throw NotEnoughSpaceException();
	else
		std::copy(begin, end, std::back_inserter(this->_ints));
}

#endif
