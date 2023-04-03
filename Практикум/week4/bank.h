#include "client.h"

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

class Bank{

private:
    char* m_bankName;
    Client* m_clients;
    ConvertionRate m_rates[6];

    size_t m_size;
    size_t m_capacity;

    void copy(const Bank& other);
    void erase();
    void resize();
    bool isEmpty() const;
    bool isFull() const;

public:
    
    Bank();
    Bank(const Bank& other);
    Bank& operator=(const Bank& other);
    ~Bank();

    Bank(const char* name, ConvertionRate rates[6]);

    void setName(const char* name);

    void addClient(const Client& client);
    bool removeClient(const char* identificationNumber);
    size_t getClientIndex(const char* identificationNumber) const;
    bool deposit(const char* identificationNumber, const Money& toDeposit);
    bool withdraw(const char* identificationNumber, const Money& toWithdraw);
    bool transfer(const char* sourceClientIdentificationNumber, const char* destinationClientIdentifinationNumber, Money moneyToTransfer);
    bool convertClientMoney(const char* identificationNumber, Currency newCurrency);
    const Client& operator[](std::size_t index) const;
    const Client& operator[](const char* identificationNumber) const; 
    friend std::ostream& operator<<(std::ostream& out, const Bank& bank);

};
