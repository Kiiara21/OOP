#include "bank.h"

void Bank::copy(const Bank& other){
    setName(other.m_bankName);
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    m_clients = new (std::nothrow) Client [m_capacity];
    if(!m_clients){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_size; ++i){
        m_clients = other.m_clients;
    }
}

void Bank::setName(const char* name){
    assert(name != nullptr);
    delete m_bankName;
    m_bankName = new (std::nothrow) char [strlen(name) + 1];
    if(!m_bankName){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_bankName, name);
}

void Bank::erase(){
    delete[] m_bankName;
    delete[] m_clients;
}

void Bank::resize(){
    Client* newClients = new (std::nothrow) Client [m_capacity * INCREASE_STEP];
    if(!newClients){
        std::cout << "Memory problem!";
        return;
    }

    for(int i = 0; i < m_size; ++i){
        newClients[i] = m_clients[i];
    }

    delete[] m_clients;
    m_clients = newClients;
    m_capacity *= INCREASE_STEP;
}

bool Bank::isEmpty() const {
    return m_size == 0;
}

bool Bank::isFull() const {
    return m_size == m_capacity;
}

Bank::Bank(){
    m_bankName = nullptr;

    m_clients = new (std::nothrow) Client[INITIAL_CAPACITY];
    if(!m_clients){
        std::cout << "Memory problem!";
        return;
    }

    m_capacity = INITIAL_CAPACITY;
    m_size = 0;
}

Bank::Bank(const Bank& other){
    copy(other);
}

Bank& Bank::operator=(const Bank& other){
    if(&other != this){
        erase();
        copy(other);   
    }
    return *this;
}

Bank::~Bank(){
    erase();
}

Bank::Bank(const char* name, ConvertionRate rates[6]){
    setName(name);
    for(int i = 0; i < 6; ++i){
        m_rates[i] = rates[i];
    }
}

void Bank::addClient(const Client& client){
    if(isFull()){
        resize();
    }
    m_clients[m_size++] = client;
}

bool Bank::removeClient(const char* identificationNumber){
    if(isEmpty()){
        std::cout << "Bank is empty!";
        return false;
    }

    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN() == identificationNumber){
            m_clients[i] = m_clients[m_size - 1];
            m_size--;
            return true;
        }
    }

    return false;
}

size_t Bank::getClientIndex(const char* identificationNumber) const {
    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN() == identificationNumber){
            return i;
        }
    }
    return -1;
}

bool Bank::deposit(const char* identificationNumber, const Money& toDeposit){
    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN() == identificationNumber){
            m_clients[i].setMoney(m_clients[i].getMoney() + toDeposit);
            std::cout << "\nAfter deposit: " << m_clients[i].getMoney() << std::endl;
            return true;
        }
    }
    return false;
}

bool Bank::withdraw(const char* identificationNumber, const Money& toWithdraw){
    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN() == identificationNumber){
            m_clients[i].setMoney(m_clients[i].getMoney() - toWithdraw);
            std::cout << "\nAfter withdrow: " << m_clients[i].getMoney() << std::endl;
            return true;
        }
    }
    return false;
}

bool Bank::transfer(const char* sourceClientIdentificationNumber, const char* destinationClientIdentifinationNumber, Money moneyToTransfer){

    bool sourceClientExist = 0, destinationClientExist = 0;
    int indexOfSorceClient, indexOfDestinationClient;

    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN() == sourceClientIdentificationNumber){
            sourceClientExist = true;            
            indexOfSorceClient = i;
            break;
        }
    }  

    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN() == destinationClientIdentifinationNumber){
            destinationClientExist = true;     
            indexOfDestinationClient = i;
            break;     
        }
    }    

    if(sourceClientExist && destinationClientExist){
        Money sourceClientMoney = m_clients[indexOfSorceClient].getMoney();
        Money destinationClientMoney = m_clients[indexOfDestinationClient].getMoney();

        if(sourceClientMoney >= moneyToTransfer){
            m_clients[indexOfSorceClient].setMoney(sourceClientMoney - moneyToTransfer);
            m_clients[indexOfDestinationClient].setMoney(destinationClientMoney + moneyToTransfer);
            return true;
        } 
        else {
            std::cout << "Source client don`t have money to transfer!";
            return false;
        }
    }

    std::cout << "Some of clients don`t exist!";
    return false;
    
} // fix - При различни валути може да се наложи конвертиране на парите

bool Bank::convertClientMoney(const char* identificationNumber, Currency newCurrency){
    Currency oldCurr;

    for(int i = 0; i < m_size; ++i){
        ConvertionRate cr;
        if(m_clients[i].getEGN() == identificationNumber){
            oldCurr = m_clients[i].getMoney().getCurrency();
            for(int i = 0; i < 6; ++i){
                if(m_rates[i].oldCurrency == oldCurr && m_rates[i].newCurrency == newCurrency){
                    cr = m_rates[i];
                }
            }
            m_clients[i].getMoney().hardConvert(cr);
            return true;
        }
        return false;
    }

    return false;
}

const Client& Bank::operator[](std::size_t index) const{
    for(int i = 0; i < m_size; ++i){
        if(i == index){
            return m_clients[i];
        }
    }
    return Client();
}

const Client& Bank::operator[](const char* identificationNumber) const{
    for(int i = 0; i < m_size; ++i){
        if(m_clients[i].getEGN()){
            return m_clients[i];
        }
    }
    return Client();
} 

std::ostream& operator<<(std::ostream& out, const Bank& bank){
    out << bank.m_bankName << std::endl;
    for(int i = 0; i < bank.m_size; ++i){
        out << bank.m_clients[i] << "\n";
    }
    for(int i = 0; i < 6; ++i){
        out << bank.m_rates[i].exchangeRate << " " << bank.m_rates[i].oldCurrency << " " << bank.m_rates[i].newCurrency << "\n";
    }

    return out;
}
