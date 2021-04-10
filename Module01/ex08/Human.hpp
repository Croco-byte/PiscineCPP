/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:25:09 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:33:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>

class	Human
{
	public:
		Human();
		~Human();

		void	action(std::string const & action_name, std::string const & target);


	private:
		void	meleeAttack(std::string const & target);
		void	rangedAttack(std::string const & target);
		void	intimidatingShout(std::string const & target);


};



#endif
