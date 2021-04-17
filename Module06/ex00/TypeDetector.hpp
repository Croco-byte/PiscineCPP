/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDetector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:52:14 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 13:37:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDETECTOR_HPP
# define TYPEDETECTOR_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>

class	TypeDetector
{
	public:
		TypeDetector();
		TypeDetector(TypeDetector const & src);
		~TypeDetector();
		TypeDetector &	operator=(TypeDetector const & rhs);

		void			analyzeType(std::string const & input);

		static bool		isChar(std::string const & input);
		static bool		isInt(std::string const & input);
		static bool		isFloat(std::string const & input);
		static bool		isDouble(std::string const & input);

		std::string		getType(void) const;

	private:
		std::string		_type;

};

#endif
