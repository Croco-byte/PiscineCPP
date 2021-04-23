/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.ipp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:28:14 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 16:50:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template < typename T, class Container >
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

template < typename T, class Container >
MutantStack<T, Container>::MutantStack(Container from_container) : std::stack<T, Container>(from_container)
{}

template < typename T, class Container >
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const & src) : std::stack<T, Container>(src)
{}

template < typename T, class Container >
MutantStack<T, Container>::~MutantStack<T, Container>()
{}

template < typename T, class Container >
MutantStack<T, Container> &		MutantStack<T, Container>::operator=(MutantStack<T, Container> const & rhs)
{
	std::stack<T, Container>::operator=(rhs);
	return (*this);
}

template < typename T, class Container >
typename MutantStack<T, Container>::iterator				MutantStack<T, Container>::begin(void)
{ return (this->c.begin()); }

template < typename T, class Container >
typename MutantStack<T, Container>::const_iterator			MutantStack<T, Container>::begin(void) const
{ return (this->c.begin()); }

template < typename T, class Container >
typename MutantStack<T, Container>::reverse_iterator		MutantStack<T, Container>::rbegin(void)
{ return (this->c.rbegin()); }

template < typename T, class Container >
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin(void) const
{ return (this->c.rbegin()); }

template < typename T, class Container >
typename MutantStack<T, Container>::iterator				MutantStack<T, Container>::end(void)
{ return (this->c.end()); }

template < typename T, class Container >
typename MutantStack<T, Container>::const_iterator			MutantStack<T, Container>::end(void) const
{ return (this->c.end()); }

template < typename T, class Container >
typename MutantStack<T, Container>::reverse_iterator		MutantStack<T, Container>::rend(void)
{ return (this->c.rend()); }

template < typename T, class Container >
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend(void) const
{ return (this->c.rend()); }

template < typename T, class Container >
void	MutantStack<T, Container>::displayStack(void) const
{
	std::cout << "MutantStack:	";
	if (this->c.empty())
		std::cout << " |empty|";
	else
	{
		for (MutantStack<T, Container>::const_iterator it = this->c.begin(); it != this->c.end(); it++)
			std::cout << " |" << *it << "|";
	}
	std::cout << std::endl;
}
