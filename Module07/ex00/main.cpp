/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:38:25 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 12:59:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int		main(void)
{

	std::cout << "=== Trying min with ints ===" << std::endl;
	std::cout << "min( 8, 42 ) returns	" << min<int>(8, 42) << std::endl;
	std::cout << "min( 8, 8 ) returns	" << min<int>(8, 8) << std::endl;

	std::cout << std::endl << "=== Trying min with floats ===" << std::endl;
	std::cout << "min( 3.14, 7.4 ) returns	" << min<float>(3.14, 7.4) << std::endl;

	std::cout << std::endl << "=== Trying min with chars ===" << std::endl;
	std::cout << "min( 'a', 'w' ) returns	" << min<char>('a', 'w') << std::endl;
	std::cout << "min( '>', '>' ) returns	" << min<char>('>', '>') << std::endl;

	std::cout << std::endl << "=== Trying max with ints ===" << std::endl;
	std::cout << "max( 10, 9 ) returns	" << max<int>(10, 9) << std::endl;
	std::cout << "max( 3, 3 ) returns	" << max<int>(3, 3) << std::endl;

	std::cout << std::endl << "=== Trying max with floats ===" << std::endl;
	std::cout << "min( 3.787, 3.788 ) returns	" << max<float>(3.787, 3.788) << std::endl;

	std::cout << std::endl << "=== Trying max with chars ===" << std::endl;
	std::cout << "max( 'a', 'w' ) returns	" << max<char>('a', 'w') << std::endl;
	std::cout << "max( '>', '>' ) returns	" << max<char>('>', '>') << std::endl;


	
	std::cout << std::endl << "=== Trying swap with ints ===" << std::endl;
	int	ia = 5;
	int	ib = 9;
	std::cout << "Before swap: |a = " << ia << "; b = " << ib << "|";
	swap(ia, ib);
	std::cout << " --- After swap: |a = " << ia << "; b = " << ib << "|" << std::endl;

	std::cout << std::endl << "=== Trying swap with floats ===" << std::endl;
	float	fa = 8.4;
	float	fb = 3.2;
	std::cout << "Before swap: |a = " << fa << "; b = " << fb << "|";
	swap(fa, fb);
	std::cout << " --- After swap: |a = " << fa << "; b = " << fb << "|" << std::endl;

	std::cout << std::endl << "=== Trying swap with strings ===" << std::endl;
	std::string sa("Hello");
	std::string sb("Loutre");
	std::cout << "Before swap: |a = " << sa << "; b = " << sb << "|";
	swap(sa, sb);
	std::cout << " --- After swap: |a = " << sa << "; b = " << sb << "|" << std::endl;

	std::cout << std::endl << "=== Trying 42 subject main ===" << std::endl;
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max ( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl << "=== Trying with a complex type (class 'Awesome') ===" << std::endl;
	Awesome aw(56);
	Awesome aw2(37);
	Awesome aw3(14);
	std::cout << "|aw = 56; aw2 = 37; aw3 = 14|" << std::endl;
	std::cout << std::endl << "min ( aw, aw2 ) returns 'Awesome' instance with value :	" << min(aw, aw2).getValue() << std::endl;
	std::cout << "min ( aw, aw3 ) returns 'Awesome' instance with value :	" << min(aw, aw3).getValue() << std::endl;
	std::cout << "max ( aw2, aw3 ) returns 'Awesome' instance with value:	" << max(aw2, aw3).getValue() << std::endl;
	std::cout << "max ( aw, aw2 ) returns 'Awesome' instance with value :	" << max(aw, aw2).getValue() << std::endl;
	std::cout << std::endl << "Swapping aw and aw2" << std::endl;
	swap(aw, aw2);
	std::cout << "Now, aw has value " << aw.getValue() << " and aw2 has value " << aw2.getValue() << std::endl;
	std::cout << std::endl << "Swapping aw2 and aw3" << std::endl;
	swap(aw2, aw3);
	std::cout << "Now, aw2 has value " << aw2.getValue() << " and aw3 has value " << aw3.getValue() << std::endl;


	return (0);
}
