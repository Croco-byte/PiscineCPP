/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:40:07 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 13:38:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void		Account::_displayTimestamp(void)
{
	std::time_t	curr = std::time(0);
	std::tm*	now = std::localtime(&curr);
	std::cout << "[" << (now->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << (now->tm_mon);
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << (now->tm_mday);
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << (now->tm_hour);
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << (now->tm_min);
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << (now->tm_sec);
	std::cout << "] ";
//	std::cout << "[19920104_091532] ";
}

void		Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void		Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->checkAmount() - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}








/* ---- ACCESSORS ---- */
int	Account::checkAmount(void) const
{ return (this->_amount); }

int	Account::getNbAccounts(void)
{ return (Account::_nbAccounts); }

int	Account::getTotalAmount(void)
{ return (Account::_totalAmount); }

int	Account::getNbDeposits(void)
{ return (Account::_totalNbDeposits); }

int	Account::getNbWithdrawals(void)
{ return (Account::_totalNbWithdrawals); }
