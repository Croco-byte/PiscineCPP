/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Writer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:47:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 12:26:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_HPP
# define WRITER_HPP

#include <iostream>
#include <fstream>

class	Writer
{

	public:
		Writer(std::string filename, std::string s1, std::string s2);
		~Writer();

		void	setLine(std::string line);
		void	replace(void);
		void	write(void);


	protected:
		std::string		_filename;
		std::string		_line;
		std::string		_s1;
		std::string		_s2;
		std::ofstream	_ofs;

};


#endif
