#include "Account.class.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int				Account::_nbAccounts = 0;
int				Account::_totalAmount = 0;
int				Account::_totalNbDeposits = 0;
int				Account::_totalNbWithdrawals = 0;

int				Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int				Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int				Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int				Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void			Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

void			Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool			Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
}

int				Account::checkAmount(void) const
{
	return this->_amount; 
}

void			Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void			Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*timeinfo;

	time(&now);
	timeinfo = localtime(&now);
	std::cout << "[" << timeinfo->tm_year + 1900;
	std::cout << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_mon;
	std::cout << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_mday << "_";
	std::cout << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_hour;
	std::cout << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_min;
	std::cout << std::setw(2) << std::right << std::setfill('0') << timeinfo->tm_sec << "] ";
}

Account::Account(void)
{
	return ;
}
