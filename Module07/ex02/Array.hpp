/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:20:10 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 16:09:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
	private:
		T *				_array;
		unsigned int	_size;

	public:
		Array<T>();
		Array<T>(unsigned int n);
		Array<T>(Array<T> const & src);
		~Array<T>();
		Array<T> &	operator=(Array<T> const & rhs);
		T &			operator[](unsigned int i) const;

		unsigned int	size(void) const;

		class	OutOfBoundException: public std::exception
		{
			public:
				virtual const char *	what() const throw() { return ("ERROR: The element you're trying to access is out of bounds."); }
		};
};

template <typename T>
std::ostream & operator<<(std::ostream & out, Array<T> const & input)
{
	out << "Array [size " << input.size() << "] :	";
	for (unsigned int i = 0; i < input.size(); i++)
		out << " |" << input[i] << "|";
	out << std::endl;
	return (out);
}

/* --- Implementation of template class ---
**	Usually I would create another file, Array.ipp and include it here
**	to keep declaration and implementation separate.
*/

template <typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_array = new T[0]();
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const & src)
{
	this->_size = src.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src[i];
}

template <typename T>
Array<T>::~Array<T>()
{
	delete [] this->_array;
}

template <typename T>
Array<T> &	Array<T>::operator=(Array<T> const & rhs)
{
	delete [] this->_array;
	this->_size = rhs.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = rhs[i];
	return (*this);
}

template <typename T>
T &			Array<T>::operator[](unsigned int i) const
{
	if (i > this->_size - 1)
		throw Array<T>::OutOfBoundException();
	return (this->_array[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{ return (this->_size); }




/* --- Just a testing class to test complex types --- */

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
		int		getValue(void) const { return (this->_n); }
		void	setValue(int new_n) { this->_n = new_n; }
	private:
		int _n;
};

std::ostream &	operator<<(std::ostream & out, Awesome const & input)
{
	out << "Awesome n°" << input.getValue();
	return (out);
}




#endif
