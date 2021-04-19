/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:13:19 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 13:11:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

/* ---- Custom test main ---- */
/*	Only works by deleting the 'const' qualifier for the function pointer taken as third parameter by the 'iter' function
**	This 'const' qualifier is necessary to make the correction code work, but IMO makes little sense.
*/

/* 
template <typename T>
void	inc(T & n) { n += 1; }

void	up(char & c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
}

int		main(void)
{
	std::cout << "=== Trying with an array of integers, and 'increments' function with ints ===" << std::endl;
	int		int_array[5] = { 0, 1, 2, 3, 4 };

	std::cout << "Before iter, int array has values :	";
	for (int i = 0; i < 5; i++)
		std::cout << int_array[i];
	
	iter(int_array, 5, &inc<int>);
	
	std::cout << std::endl << "After iter, int array has values :	";
	for (int i = 0; i < 5; i++)
		std::cout << int_array[i];
	std::cout << std::endl;

	std::cout << std::endl << "=== Trying with an array of chars, and 'increments' function with chars ===" << std::endl;
	char	char_array[5] = { 'a', 'b', 'c', 'd', 'e' };

	std::cout << "Before iter, char array has values :	";
	for (int i = 0; i < 5; i++)
		std::cout << char_array[i];
	
	iter(char_array, 5, &inc<char>);
	
	std::cout << std::endl << "After iter, char array has values :	";
	for (int i = 0; i < 5; i++)
		std::cout << char_array[i];
	std::cout << std::endl;

	std::cout << std::endl << "=== Trying with strings, and 'up' value capitalizing the content of string ===" << std::endl;
	char str[] = "Bonjour bonjour!";
	std::cout << "Before iter, string has value :	" << str << std::endl;
	
	iter(str, 16, &up);
	
	std::cout << "After iter, string has value :	" << str << std::endl;



	return (0);
}
*/

/* ---- 42 test main ---- */

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
