/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:21:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 15:18:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>

class	NotFoundException: public std::exception
{
	public:
		const char *	what() const throw() { return ("Couldn't find the specified element in container"); }
};

template <typename T>
int		easyfind(T const & container, int toFind)
{
	int		result(0);

	typename T::const_iterator it = find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NotFoundException();

	while (it != container.begin())
	{
		result++;
		it--;
	}
	return (result);
}



#endif
