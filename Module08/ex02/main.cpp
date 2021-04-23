/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:33:49 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 17:26:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int		main(void)
{
	std::cout << "=== Testing initialization with different container types (deque, vector, list), copy constructor and '=' operator ===" << std::endl; 
	std::cout << std::endl << "---> Creating an empty MutantStack with default container type (deque)" << std::endl;

	MutantStack<int> d_mstack;
	std::cout << "[deque] "; d_mstack.displayStack();

	std::cout << std::endl << "---> Creating a MutantStack from a deque<int> container with ten '5'" << std::endl;
	MutantStack<int> d_mstack2(std::deque<int>(10,5));
	std::cout << "[deque] "; d_mstack.displayStack();
	std::cout << "[deque] "; d_mstack2.displayStack();

	std::cout << std::endl << "---> Creating a MutantStack from a vector<std::string>, and another from a list<float>" << std::endl;
	MutantStack<std::string, std::vector<std::string> > v_mstack(std::vector<std::string>(3, "Hey"));
	MutantStack<float, std::list<float> > l_mstack(std::list<float>(5, 3.14));

	std::cout << "[deque] "; d_mstack.displayStack();
	std::cout << "[deque] "; d_mstack2.displayStack();
	std::cout << "[vector] "; v_mstack.displayStack();
	std::cout << "[list] "; l_mstack.displayStack();

	std::cout << std::endl << "---> Creating another vector MutantStack from the other vector based MutantStack (testing copy constructor)" << std::endl;
	MutantStack<std::string, std::vector<std::string> > v_mstack2(v_mstack);

	std::cout << "[deque] "; d_mstack.displayStack();
	std::cout << "[deque] "; d_mstack2.displayStack();
	std::cout << "[vector] "; v_mstack.displayStack();
	std::cout << "[list] "; l_mstack.displayStack();
	std::cout << "[vector] "; v_mstack2.displayStack();

	std::cout << std::endl << "---> Assigning seconde deque MutantStack to the first one (testing '=' operator)" << std::endl;
	d_mstack = d_mstack2;

	std::cout << "[deque] "; d_mstack.displayStack();
	std::cout << "[deque] "; d_mstack2.displayStack();
	std::cout << "[vector] "; v_mstack.displayStack();
	std::cout << "[list] "; l_mstack.displayStack();
	std::cout << "[vector] "; v_mstack2.displayStack();

	std::cout << std::endl << "=== Testing push, pop, top and size operations ===" << std::endl;

	std::cout << std::endl << "---> Poping an element from first and last MutantStacks" << std::endl;
	d_mstack.pop();
	v_mstack2.pop();
	std::cout << "[deque] "; d_mstack.displayStack();
	std::cout << "[deque] "; d_mstack2.displayStack();
	std::cout << "[vector] "; v_mstack.displayStack();
	std::cout << "[list] "; l_mstack.displayStack();
	std::cout << "[vector] "; v_mstack2.displayStack();

	std::cout << std::endl << "---> Pushing string 'Hello' to third MutantStack, 42.2 2.42 42.42 to fourth MutantStack" << std::endl;
	v_mstack.push("Hello");
	l_mstack.push(42.2);
	l_mstack.push(2.42);
	l_mstack.push(42.42);
	std::cout << "[deque] "; d_mstack.displayStack();
	std::cout << "[deque] "; d_mstack2.displayStack();
	std::cout << "[vector] "; v_mstack.displayStack();
	std::cout << "[list] "; l_mstack.displayStack();
	std::cout << "[vector] "; v_mstack2.displayStack();

	std::cout << std::endl << "---> Displaying top element of each MutantStack (i.e the last one)" << std::endl;
	std::cout << d_mstack.top() << std::endl;
	std::cout << d_mstack2.top() << std::endl;
	std::cout << v_mstack.top() << std::endl;
	std::cout << l_mstack.top() << std::endl;
	std::cout << v_mstack2.top() << std::endl;

	std::cout << std::endl << "---> Displaying size of each MutantStack" << std::endl;
	std::cout << d_mstack.size() << std::endl;
	std::cout << d_mstack2.size() << std::endl;
	std::cout << v_mstack.size() << std::endl;
	std::cout << l_mstack.size() << std::endl;
	std::cout << v_mstack2.size() << std::endl;

	std::cout << std::endl << "=== Testing iterators === " << std::endl;
	std::cout << std::endl << "---> Declaring an iterator pointing to the beginning of each MutantStack, and displaying the dereferenced iterator (should show first element of each stack)" << std::endl;
	
	MutantStack<int>::iterator d_it = d_mstack.begin();
	MutantStack<int>::iterator d_it2 = d_mstack2.begin();
	MutantStack<std::string, std::vector<std::string> >::iterator v_it = v_mstack.begin();
	MutantStack<float, std::list<float> >::iterator l_it = l_mstack.begin();
	MutantStack<std::string, std::vector<std::string> >::iterator v_it2 = v_mstack2.begin();
	std::cout << *d_it << std::endl;
	std::cout << *d_it2 << std::endl;
	std::cout << *v_it << std::endl;
	std::cout << *l_it << std::endl;
	std::cout << *v_it2 << std::endl;

	std::cout << std::endl << "---> Incrementing the third MutantStack of 1, and changing the seconde value to 'Bonjour'" << std::endl;
	++v_it;
	*v_it = "Bonjour";

	std::cout << std::endl << "---> Iterating through the third MutantStack and displaying each values thanks to iterators. This should print all values of third MutantStack, and show that the second element was modified" << std::endl;
	--v_it;
	for (; v_it != v_mstack.end(); v_it++)
		std::cout << *v_it << " ";
	std::cout << std::endl;

	std::cout << std::endl << "---> Declaring a REVERSE const iterator on fourth MutantStack, and displaying its content with it. This should print all values of fourth MutantStack, in reverse order" << std::endl;
	MutantStack<float, std::list<float> >::const_reverse_iterator l_rev_const_it = l_mstack.rbegin();
	for (; l_rev_const_it != l_mstack.rend(); l_rev_const_it++)
		std::cout << *l_rev_const_it << " ";
	std::cout << std::endl;

	return (0);
}
