/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:34:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 12:59:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed (Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const & src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	protected:
		int					_raw;
		static int const	_byteNb = 8;

};

#endif
