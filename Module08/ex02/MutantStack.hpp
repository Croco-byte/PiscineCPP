/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:09:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 16:38:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

template < typename T, class Container=std::deque<T> >
class	MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack<T, Container>();
		MutantStack<T, Container>(Container from_container);
		MutantStack<T, Container>(MutantStack<T, Container> const & src);
		virtual ~MutantStack<T, Container>();
		MutantStack<T, Container> & operator=(MutantStack<T, Container> const & rhs);

		typedef typename std::stack<T, Container>::container_type::iterator					iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator					begin(void);
		const_iterator					begin(void) const;
		reverse_iterator			rbegin(void);
		const_reverse_iterator		rbegin(void) const;
		iterator					end(void);
		const_iterator					end(void) const;
		reverse_iterator			rend(void);
		const_reverse_iterator		rend(void) const;

		void						displayStack(void) const;
};

#include "MutantStack.ipp"

#endif
