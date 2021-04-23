/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:15:19 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 12:19:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_HPP
# define FILLER_HPP

class	Filler
{
	private:
		Filler();

		int	_value;

	public:
		Filler(int value) { this->_value = value; }
		Filler(Filler const & src) { this->_value = src._value; }
		~Filler() {}
		Filler & operator=(Filler const & rhs) { this->_value = rhs._value; return (*this); }

		int	operator()(int offset)
		{
			this->_value += offset;
			return (this->_value);
		}
};



#endif
