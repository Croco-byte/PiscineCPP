/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:29:15 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 15:22:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int		main(void)
{
	std::cout << "=== Testing with a vector<int> ===" << std::endl;
	
	std::cout << std::endl << "---> Creating a vector of size 20, filled with 5's, and searching for the first 5 (should be index 0)" << std::endl;
	std::vector<int> vectab(20,5);
	int v_0 = easyfind(vectab, 5);
	std::cout << "First occurence of 5 is at index " << v_0 << std::endl;

	std::cout << std::endl << "---> Modifying the 3rd element of vector to 45, and searching for the first 45 (should be index 3)" << std::endl;
	vectab[3] = 45;
	int v_1 = easyfind(vectab, 45);
	std::cout << "First occurence of 45 is at index " << v_1 << std::endl;

	std::cout << std::endl << "---> Searching 89, that is not in the vector (should throw an exception)" << std::endl;
	try
	{
		int	v_2 = easyfind(vectab, 89);
		std::cout << "First occurence of 89 is at index " << v_2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== Testing with a deque<int> ===" << std::endl;

	std::cout << std::endl << "---> Creating a deque of size 5, filled with 2's, and searching for the first 2 (should be index 0)" << std::endl;
	std::deque<int> deqtab(5,2);
	int d_0 = easyfind(deqtab, 2);
	std::cout << "First occurence of 5 is at index " << d_0 << std::endl;

	std::cout << std::endl << "---> Adding a 8 at the end of the deque and searching for the first 8 (should be index 5)" << std::endl;
	deqtab.push_back(8);
	int d_1 = easyfind(deqtab, 8);
	std::cout << "First occurence of 8 is at index " << d_1 << std::endl;

	std::cout << std::endl << "---> Searching 3, that is not in the deque (should throw an exception)" << std::endl;
	try
	{
		int	d_2 = easyfind(deqtab, 3);
		std::cout << "First occurence of 3 is at index " << d_2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== Testing with a list<int> (container supporting only bidimensional iterators) ===" << std::endl;

	std::cout << std::endl << "---> Creating a list of size 10, filled with 42's, and searching for the first 42 (should be index 0)" << std::endl;
	std::list<int> ltab(10,42);
	int l_0 = easyfind(ltab, 42);
	std::cout << "First occurence of 42 is at index " << l_0 << std::endl;

	std::cout << std::endl << "---> Modifying the element at index 9 as a 12 and searching for the first 12 (should be index 9)" << std::endl;
	std::list<int>::iterator l_it = ltab.begin();
	for (int i = 0; i < 9; i++)
		l_it++;
	*l_it = 12;
	int l_1 = easyfind(ltab, 12);
	std::cout << "First occurence of 12 is at index " << l_1 << std::endl;

	std::cout << std::endl << "---> Searching 3, that is not in the list (should throw an exception)" << std::endl;
	try
	{
		int	l_2 = easyfind(ltab, 3);
		std::cout << "First occurence of 3 is at index " << l_2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	} 

	return (0);
}
