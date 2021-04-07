/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Writer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:51:49 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 12:45:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Writer.hpp"

Writer::Writer(std::string filename, std::string s1, std::string s2): _filename(filename + ".replace"), _s1(s1), _s2(s2)
{
	this->_ofs.open(this->_filename.c_str(), std::ofstream::app);
	if (!this->_ofs)
		throw std::string("[X] Error: Couldn't open file for writing");
}

Writer::~Writer()
{}


void	Writer::replace(void)
{
	std::size_t	pos;

	do
	{
		pos = this->_line.find(this->_s1);
		if (pos != std::string::npos)
			this->_line.replace(pos, this->_s1.size(), this->_s2);
	} while (pos != std::string::npos);
}

void	Writer::write(void)
{
	this->_ofs << this->_line << std::endl;
}






/* --- MUTATORS --- */
void	Writer::setLine(std::string line)
{ this->_line = line; }
