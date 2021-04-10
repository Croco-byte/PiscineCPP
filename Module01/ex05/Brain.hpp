/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:15:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:32:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class	Brain
{
	public:
		Brain();
		Brain(int IQ);
		~Brain();

		std::string	identify(void) const;

	private:

		int		_IQ;

};



#endif
