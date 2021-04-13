/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:28:32 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 20:09:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class	Victim
{
	public:
		Victim(std::string name);
		Victim(Victim const & src);
		~Victim();
		Victim & operator=(Victim const & rhs);

		virtual void		getPolymorphed(void) const;

		const std::string	&getName(void) const;

	protected:
		Victim();
		std::string	_name;

	private:
};

std::ostream &	operator<<(std::ostream & out, Victim const & input);


#endif
