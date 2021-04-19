/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:36:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 16:12:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int		main(void)
{
	std::cout << "=== Manipulating class 'Array' with integers ===" << std::endl << std::endl;
	
	try
	{
		std::cout << std::endl << "----> Creating an empty 'Array<int>'" << std::endl;
		Array<int> i_1;
		
		std::cout << i_1;

		std::cout << std::endl << "----> Creating another 'Array<int>' with 10 elements" << std::endl;
		Array<int> i_2(10);
		
		std::cout << i_1;
		std::cout << i_2;

		std::cout << std::endl << "----> Testing copy constructor : creating another 'Array<int>' with the 10 elements array" << std::endl;
		Array<int> i_3(i_2);

		std::cout << i_1;
		std::cout << i_2;
		std::cout << i_3;

		std::cout << std::endl << "----> Testing the [] operator : modifying third array's 5th element to '42'" << std::endl;
		i_3[4] = 42;

		std::cout << i_1;
		std::cout << i_2;
		std::cout << i_3;

		std::cout << std::endl << "----> Testing assignation operator : assigning third array to first and second array. All arrays should be equal, and no mem leak" << std::endl;
		i_1 = i_3;
		i_2 = i_3;

		std::cout << i_1;
		std::cout << i_2;
		std::cout << i_3;

		std::cout << std::endl << "----> Modifying elements 1, 2, 3 of first array to confirm deep copy (other arrays should not be affected)" << std::endl;
		i_1[0] = 12;
		i_1[1] = 36;
		i_1[2] = 48;

		std::cout << i_1;
		std::cout << i_2;
		std::cout << i_3;

		std::cout << std::endl << "----> Trying to access an element that is out of bound (first array, element 15). This should throw an exception." << std::endl;
		i_1[15] = 15;
		std::cout << "This should never be displayed" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== Manipulating class 'Array' with strings ===" << std::endl << std::endl;

	try
	{
		std::cout << "----> Creating an empty 'Array<std::string>'" << std::endl;
		Array<std::string> s_1;

		std::cout << s_1;

		std::cout << std::endl << "----> Creating an 'Array<std::string>' of size 5" << std::endl;
		Array<std::string> s_2(5);

		std::cout << s_1;
		std::cout << s_2;

		std::cout << std::endl << "----> Filling second array with greetings :)" << std::endl;
		s_2[0] = "Hello";
		s_2[1] = "Bonjour";
		s_2[2] = "Salut";
		s_2[3] = "Yo";
		s_2[4] = "Bonsoir";

		std::cout << s_1;
		std::cout << s_2;

		std::cout << std::endl << "----> Using assignation operator to deep copy second array into first array" << std::endl;
		s_1 = s_2;

		std::cout << s_1;
		std::cout << s_2;

		std::cout << std::endl << "----> Trying to access an out of bounds element. This should throw an exception" << std::endl;
		s_2[5] = "Bruh";
		std::cout << "This should never be displayed" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "=== Manipulating class 'Array' with a complex type (class 'Awesome' objects) ===" << std::endl;

	try
	{
		std::cout << std::endl << "----> Creating an 'Array<Awesome>' of size 10 (so, 10 objects of the class 'Awesome' in the array)" << std::endl;
		Array<Awesome> a_1(10);

		std::cout << a_1;

		std::cout << std::endl << "----> Testing copy constructor : creating a new 'Array<Awesome>' from first one" << std::endl;
		Array<Awesome> a_2(a_1);

		std::cout << a_1;
		std::cout << a_2;

		std::cout << std::endl << "----> Changing elements 2 and 6 of the first array" << std::endl;
		a_1[1] = 22;
		a_1[5] = 44;

		std::cout << a_1;
		std::cout << a_2;

		std::cout << std::endl << "----> Trying to access an element that is out of bound. This should throw an exception" << std::endl;
		a_2[10].setValue(1212);
		std::cout << "This should never be displayed" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
