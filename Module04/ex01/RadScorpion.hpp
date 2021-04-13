/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:27:43 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 12:31:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class	RadScorpion: public Enemy
{
	public:
		RadScorpion();
		RadScorpion(RadScorpion const & src);
		virtual ~RadScorpion();
		RadScorpion & operator=(RadScorpion const & rhs);
};


#endif
