/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:04:57 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 15:55:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <math.h>
#include <sstream>

class	Converter
{
	private:
		Converter();

		char		_cvalue;
		int			_ivalue;
		float		_fvalue;
		double		_dvalue;
		bool		_status[4];

		enum Type {
			TypeChar,
			TypeInt,
			TypeFloat,
			TypeDouble,
			TypeInvalid
		};
		Type		_inputType;

	public:
		Converter(std::string const & type, std::string const & input);
		Converter(Converter const & src);
		~Converter();
		Converter & operator=(Converter const & rhs);

		void		fromChar(std::string const & input);
		void		fromInt(std::string const & input);
		void		fromFloat(std::string const & input);
		void		fromDouble(std::string const & input);
		void		fromInvalid(void);
		void		setImpossible(Type type);

		void		displayConverted(void) const;
};

std::ostream const & operator<<(std::ostream const & out, Converter const & input);


#endif
