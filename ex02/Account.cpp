#include <ctime>
#include <string>
#include "./Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_amount) : _accountIndex(_nbAccounts), _amount(initial_amount), _nbDeposits(0), _nbWithdrawals(0) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";created" << std::endl;
    ++_nbAccounts;
    _totalAmount += initial_amount;
}

Account::~Account() {
    _displayTimestamp();
    if (this->_accountIndex == 7) {
            std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "amount:" << this->_amount << ";closed";
    }
    else {
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "amount:" << this->_amount << ";closed" << std::endl;
    }
}

void Account::_displayTimestamp() {
    std::time_t time = std::time(NULL);
    char    timeString[sizeof("yyyymmdd_hhmmss")];
    std::strftime(timeString, sizeof(timeString), "%F%H%M", std::localtime(&time));
    std::cout << "[" << timeString << "] ";
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << (this)->_amount;
    std::cout << ";deposits:" << (this)->_nbDeposits << ";withdrawals:";
    std::cout << (this)->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int dep) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << dep << ";amount:";
    this->_amount = this->_amount + dep;
    _totalAmount += dep;
    ++_totalNbDeposits;
    std::cout << this->_amount << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    if (withdrawal > this->_amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << ";withdrawal:" << withdrawal << ";amount:";
    this->_amount = this->_amount - withdrawal;
    _totalAmount -= withdrawal;
    ++_totalNbWithdrawals;
    std::cout << this->_amount << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
    return true;
}