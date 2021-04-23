/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInstruction.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:22:54 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 20:11:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

class	IInstruction
{
	public:
		virtual			~IInstruction() {}
		virtual	void	execute(char * data, unsigned short & ptr, unsigned int & ip) const = 0;
};

#endif
