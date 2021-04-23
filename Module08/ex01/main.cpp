/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:58:45 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 12:49:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Filler.hpp"

int		main(void)
{
	std::cout << std::endl << "=== Creating a Span of max size 10, adding 1 2 3 4 5 to it, displaying content, and spans (shortest should be 1, longest 4) ===" << std::endl;

	Span s_1(10);

	s_1.addNumber(1);
	s_1.addNumber(2);
	s_1.addNumber(3);
	s_1.addNumber(4);
	s_1.addNumber(5);
	s_1.displayContent();
	std::cout << "Shortest span is	[" << s_1.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_1.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Adding a 100 to our Span of max size 10, displaying content, and spans (shortest should be 1, longest 99)" << std::endl;
	s_1.addNumber(100);
	s_1.displayContent();
	std::cout << "Shortest span is	[" << s_1.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_1.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Adding a 1 to our Span of max size 10, displaying content, and spans (shortest should be 0, longest 99)" << std::endl;
	s_1.addNumber(1);
	s_1.displayContent();
	std::cout << "Shortest span is	[" << s_1.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_1.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Adding -2147483648 and 2147483647 to our Span of max size 10, displaying content, and spans (shortest should be 0, longest 4294967295)" << std::endl;
	s_1.addNumber(-2147483648);
	s_1.addNumber(2147483647);
	s_1.displayContent();
	std::cout << "Shortest span is	[" << s_1.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_1.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Trying to add two other numbers to our Span of max size 10. This should throw an exception since we already have 9 elements in Span" << std::endl;
	try
	{
		s_1.addNumber(2);
		s_1.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Creating an empty Span of max size 10000, and trying to calculate spans (this should throw an exception) ===" << std::endl;
	Span	s_2(10000);
	try
	{
		s_2.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Filling the Span of max size 10000 with number range 1 - 10000, and calculating spans (shortest should be 1, longest 9999)" << std::endl;
	Filler	fill(0);
	std::vector<int> v_1(10000, 0);
	for (std::vector<int>::iterator it = v_1.begin(); it != v_1.end(); it++)
		*it = fill(1);
	s_2.addNumber(v_1.begin(), v_1.end());
	std::cout << "Shortest span is	[" << s_2.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_2.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Filling the Span of max size 10000 with 1 3 5 7 [...] 19999, and calculating spans (shortest should be 2, longest 19998)" << std::endl;
	s_2.clearContent();
	for (std::vector<int>::iterator it = v_1.begin(); it != v_1.end(); it++)
		*it = fill(2);
	s_2.addNumber(v_1.begin(), v_1.end());
	std::cout << "Shortest span is	[" << s_2.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_2.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Trying to fill the Span of max size 10000 with 10001 numbers (this should throw an exception)" << std::endl;
	s_2.clearContent();
	try
	{
		std::vector<int> v_2(10001, 0);
		s_2.addNumber(v_2.begin(), v_2.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Filling a Span of max size 50000 with 50000 0's and calculating spans (shortest and longest should be 0)" << std::endl;
	Span s_3(50000);
	std::vector<int> v_3(50000, 0);
	s_3.addNumber(v_3.begin(), v_3.end());
	std::cout << "Shortest span is	[" << s_3.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_3.longestSpan() << "]" << std::endl;

	std::cout << std::endl << "=== Filling the Span of max size 50000 with numbers in range 1 - 50000 and calculating spans (shortest should be 1, longest 49999)" << std::endl;
	s_3.clearContent();
	for (std::vector<int>::iterator it = v_3.begin(); it != v_3.end(); it++)
		*it = fill(1);
	s_3.addNumber(v_3.begin(), v_3.end());
	std::cout << "Shortest span is	[" << s_3.shortestSpan() << "]" << std::endl;
	std::cout << "Longest span is		[" << s_3.longestSpan() << "]" << std::endl;


	return (0);
}
