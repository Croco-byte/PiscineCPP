/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:13:14 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 12:55:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

Reader::Reader(std::string filename): _filename(filename)
{
	this->_ifs.open(this->_filename.c_str());
	if (!this->_ifs)
		throw std::string("[X] Error: Couldn't open file for reading");
}

Reader::~Reader()
{}

std::string		Reader::getLine(void)
{
	std::getline(this->_ifs, this->_line);
	return (this->_line);
}

std::ifstream&	Reader::getIfs(void)
{ return (this->_ifs); }
