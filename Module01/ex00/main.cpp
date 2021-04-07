/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:35:34 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 19:04:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poney.hpp"

void	ponyOnTheStack(void)
{
	Poney stack_poney("Bob", "Apples", 23, "Brown");
	
	std::cout << "This poney was created on the stack	--> Address " << &stack_poney << std::endl;
	std::cout << "> PONEY STATS -- | name: " << stack_poney.get_name() << " | favorite meal: " << stack_poney.get_fav_meal() << " | age: " << stack_poney.get_age() << " | color: " << stack_poney.get_color() << " |" << std::endl;
	std::cout << std::endl << "Poney on the stack had a name change ! He is now called Stan." << std::endl;
	std::cout << std::endl;
	stack_poney.set_name("Stan");
	std::cout << "> PONEY STATS -- | name: " << stack_poney.get_name() << " | favorite meal: " << stack_poney.get_fav_meal() << " | age: " << stack_poney.get_age() << " | color: " << stack_poney.get_color() << " |" << std::endl;
}

void ponyOnTheHeap(void)
{
	Poney *heap_poney = new Poney("Franck", "Wheat", 12, "White");
	
	std::cout << "This poney was created on the heap	--> Address " << heap_poney << std::endl;
	std::cout << "> PONEY STATS -- | name: " << heap_poney->get_name() << " | favorite meal: " << heap_poney->get_fav_meal() << " | age: " << heap_poney->get_age() << " | color: " << heap_poney->get_color() << " |" << std::endl;
	std::cout << std::endl << "Poney on the heap changed his mind concerning his favorite food. He now prefers burgers." << std::endl;
	std::cout << std::endl;
	heap_poney->set_fav_meal("Burgers");
	std::cout << "> PONEY STATS -- | name: " << heap_poney->get_name() << " | favorite meal: " << heap_poney->get_fav_meal() << " | age: " << heap_poney->get_age() << " | color: " << heap_poney->get_color() << " |" << std::endl;
	delete(heap_poney);
}


int		main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
