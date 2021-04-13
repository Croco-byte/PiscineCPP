/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Traveller.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:16:26 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:17:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAVELLER_HPP
# define TRAVELLER_HPP

#include "Victim.hpp"

class	Traveller: public Victim
{
	public:
		Traveller(std::string name);
		Traveller(Traveller const & src);
		~Traveller();
		Traveller & operator=(Traveller const & src);

		virtual void	getPolymorphed(void) const;

	private:
		Traveller();

};



#endif
