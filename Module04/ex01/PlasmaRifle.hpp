/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:44:01 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 11:46:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class	PlasmaRifle: public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const & src);
		virtual ~PlasmaRifle();
		PlasmaRifle & operator=(PlasmaRifle const & rhs);

		virtual void	attack(void) const;


};


#endif
