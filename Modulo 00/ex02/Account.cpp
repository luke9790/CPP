#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t timestamp = std::time(NULL);
	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&timestamp)->tm_year
                << std::setw(2) << 1 + std::localtime(&timestamp)->tm_mon
                <<  std::setw(2) << std::localtime(&timestamp)->tm_mday
                <<  "_"
                <<  std::setw(2) << std::localtime(&timestamp)->tm_hour
                <<  std::setw(2) << std::localtime(&timestamp)->tm_min
                <<  std::setw(2) << std::localtime(&timestamp)->tm_sec
                << "] " << std::flush;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return _totalAmount;
}
int	Account::getNbDeposits( void ) {
	return	_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
			<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_totalNbDeposits++;
	_totalAmount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"
			<< deposit << ";amount:" << _amount + deposit << ";nb_deposits:"
			<< _nbDeposits << std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (_amount - withdrawal < 0) {
		std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	else {
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:"
			<< withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:"
			<< _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		return true;
	}
}
int		Account::checkAmount( void ) const {
	return _amount;
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
		<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	_nbAccounts++;
	_amount = initial_deposit;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}