/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:53:30 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 11:54:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class	PowerFist: public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const & src);
		virtual ~PowerFist();
		PowerFist & operator=(PowerFist const & rhs);

		virtual void	attack(void) const;
};




#endif
