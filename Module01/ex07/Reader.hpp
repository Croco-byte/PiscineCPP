/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:11:06 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 15:32:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	READER_HPP
# define READER_HPP

#include <iostream>
#include <fstream>

class	Reader
{
	public:
		Reader(std::string filename);
		~Reader();

		std::string		getLine(void);
		std::ifstream&	getIfs(void);

	private:
		std::string		_filename;
		std::string		_line;
		std::ifstream	_ifs;

};


#endif
