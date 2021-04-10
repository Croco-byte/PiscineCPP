/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:33:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:32:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

class	Human
{
	public:
		Human();
		~Human();

		std::string 	identify(void);
		const Brain&	getBrain(void);

	private:
		Brain	const _brain;


};

#endif
