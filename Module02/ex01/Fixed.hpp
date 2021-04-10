/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:34:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:33:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(int const integrer);
		Fixed(float const floater);
		Fixed (Fixed const & src);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed & operator=(Fixed const & src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_raw;
		static int const	_byteNb = 8;

};

std::ostream &	operator<<(std::ostream & out, Fixed const & input);

#endif
