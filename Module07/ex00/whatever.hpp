/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:34:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 16:02:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void		swap(T & a, T & b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &	min(T const & a, T const & b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T const &	max(T const & a, T const & b)
{
	return ((a > b) ? a : b);
}

class Awesome {
	public:
		Awesome( int n ) : _n( n ) {}
		Awesome () : _n(0) {}
		Awesome &	operator=( Awesome const & rhs ) { this->_n = rhs.getValue(); return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int	getValue(void) const { return (this->_n); }
	private:
		int _n;
};


#endif
