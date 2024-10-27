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
    std::cout << "amount:" << this->_amount << ";created:" << std::endl;
    ++_nbAccounts;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";closed:" << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t time = std::time(nullptr);
    char    timeString[std::size("yyyymmdd_hhmmss")];
    std::strftime(std::data(timeString), std::size(timeString), "%F%H%M%S", std::localtime(&time));
    std::cout << " [" << timeString << "] ";
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals;
}

void Account::displayStatus() const{
    for (int i = 0;i < _nbAccounts;++i) {
        _displayTimestamp();
        std::cout << "index:" << i << ";amount" << (this + 1)->_amount;
        std::cout << ";deposits" << (this + 1)->_nbDeposits << ";withdrawals:";
        std::cout << (this + 1)->_nbWithdrawals << std::endl;
    }
}

void Account::makeDeposit(int dep) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount" << this->_amount;
    std::cout << ";deposit" << dep << ";amount:";
    this->_amount = this->_amount + dep;
    _totalAmount += this->_amount;
    ++_totalNbDeposits;
    std::cout << this->_amount << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount" << (this + 1)->_amount;
    if (withdrawal > this->_amount) {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << ";withdrawal" << withdrawal << ";amount:";
    this->_amount = this->_amount - withdrawal;
    _totalAmount += this->_amount;
    ++_totalNbWithdrawals;
    std::cout << this->_amount << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
    return true;
}