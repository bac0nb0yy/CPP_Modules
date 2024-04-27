#include "Account.hpp"
#include <iomanip>
#include <iostream>

Account::Account(int initial_deposit) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
			  << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";withdrawal:";
	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	time_t currentTimeSec = time(NULL);
	tm* localTime = localtime(&currentTimeSec);

	std::cout << "[" << std::setfill('0') << std::setw(4)
			  << localTime->tm_year + 1900 << std::setfill('0') << std::setw(2)
			  << localTime->tm_mon + 1 << std::setfill('0') << std::setw(2)
			  << localTime->tm_mday << "_" << std::setfill('0') << std::setw(2)
			  << localTime->tm_hour << std::setfill('0') << std::setw(2)
			  << localTime->tm_min << std::setfill('0') << std::setw(2)
			  << localTime->tm_sec << "] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;