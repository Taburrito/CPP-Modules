/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:44:14 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/23 16:30:22 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

void	Account::_displayTimestamp(void)
{
	std::time_t time = std::time(NULL);
	std::tm* timedata = std::localtime(&time);

	std::cout << "[";
	std::cout << (timedata->tm_year + 1900);

	if ((timedata->tm_mon + 1) < 10)
		std::cout << "0";
	std::cout << (timedata->tm_mon + 1);

	if ((timedata->tm_mday) < 10)
		std::cout << "0";
	std::cout << timedata->tm_mday << "_";

	if (timedata->tm_hour < 10)
		std::cout << "0";
	std::cout << timedata->tm_hour;

	if (timedata->tm_min < 10)
		std::cout << "0";
	std::cout << timedata->tm_min;

	if (timedata->tm_sec < 10)
		std::cout << "0";
	std::cout << timedata->tm_sec << "] ";
}

// ************************************************************************** //
//                           Constructor&Destructor                           //
// ************************************************************************** //

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	return;
}

Account::~Account(void)
{
	return;
}

// ************************************************************************** //
//                                    Gets                                    //
// ************************************************************************** //

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
// ************************************************************************** //

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits ++;
	return;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	if (this->_amount < withdrawal)
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++ ;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}



