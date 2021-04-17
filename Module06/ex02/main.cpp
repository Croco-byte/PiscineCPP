/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:02:55 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 12:29:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <exception>

class	Base { public: virtual ~Base(void) {} };
class	A: public Base {};
class	B: public Base {};
class	C: public Base {};

Base *	generate(void)
{
	srand(time(NULL));
	int		random(rand() % 3);
	Base *	rslt;

	if (random == 0)
	{
		std::cout << "[INFO] Generated an instance of :	A" << std::endl << std::endl;
		return (rslt = new A);
	}
	else if (random == 1)
	{
		std::cout << "[INFO] Generated an instance of :	B" << std::endl << std::endl;
		return (rslt = new B);
	}
	else
	{
		std::cout << "[INFO] Generated an instance of :	C" << std::endl << std::endl;
		return (rslt = new C);
	}
}

void	identify_from_pointer(Base * p)
{
	A * a;
	B * b;
	C * c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "[FROM POINTER] Identified type :	A" << std::endl;
	if (b)
		std::cout << "[FROM POINTER] Identified type :	B" << std::endl;
	if (c)
		std::cout << "[FROM POINTER] Identified type :	C" << std::endl;
}

void	identify_from_reference(Base & p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "[FROM REFERENCE] Identified type :	A" << std::endl;
	}
	catch (std::exception &e)
	{}
	
	try
	{
		B & b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "[FROM REFERENCE] Identified type :	B" << std::endl;
	}
	catch (std::exception &e)
	{}

	try
	{
		C & c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "[FROM REFERENCE] Identified type :	C" << std::endl;
	}
	catch (std::exception &e)
	{}
}


int		main(void)
{
	Base *	p;

	p = generate();
	identify_from_pointer(p);
	std::cout << std::endl;
	identify_from_reference(*p);

	delete p;
	return (0);
}
