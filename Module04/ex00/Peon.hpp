/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:59:19 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:17:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class	Peon: public Victim
{
	public:
		Peon(std::string name);
		Peon(Peon const & src);
		~Peon();
		Peon & operator=(Peon const & src);

		virtual void	getPolymorphed(void) const;

	private:
		Peon();

};

#endif
