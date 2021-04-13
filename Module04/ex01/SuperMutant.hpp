/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:11:06 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 12:14:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class	SuperMutant: public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		virtual ~SuperMutant();
		SuperMutant & operator=(SuperMutant const & rhs);

		virtual void	takeDamage(int amount);

};



#endif
