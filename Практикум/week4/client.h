#include "date.h"
#include "money.h"
#include <cstring>

class Client{

private:
    char* m_name;
    char* m_EGN;
    Date m_birthData;
    Money m_money;

    void copy(const Client& other);
    void erase();

public:

    Client() : m_name(nullptr), m_EGN(nullptr), m_birthData(10,10,10), m_money() {} 
    Client(const Client& other);
    Client& operator=(const Client& other);
    ~Client();
    
    Client(const char* name, const char* identificationNumber, const Date& birthday, const Money& money);
    
    void setName(const char* name);
    void setEGN(const char* identificationNumber);
    void setBirthDate(const Date& birthday);
    void setMoney(const Money& money);

    const char* getName() const { return m_name; }
    const char* getEGN() const { return m_EGN; }
    Date getDate() const { return m_birthData; }
    Money getMoney() const { return m_money; }

    friend std::ostream& operator<<(std::ostream& out, const Client& client);
};