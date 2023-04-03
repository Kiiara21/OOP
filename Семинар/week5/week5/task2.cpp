#include <iostream>
#include <cstring>
#include <cassert>

class ToDo{

private:

    char* m_description;
    int m_id;
    bool m_state;
    
    void copy(const ToDo& other);
    void erase();
public:

    ToDo();
    ToDo(const ToDo& other);
    ToDo& operator=(const ToDo& other);
    ~ToDo();

    ToDo(const char* description, int id, bool state);

    const char* getDescription() const;
    int getId() const;
    bool getState() const;

    void executeTask();

    void print() const;
};

void ToDo::copy(const ToDo& other){
    m_description = new (std::nothrow) char [strlen(other.m_description) + 1];
    if(!m_description){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_description, other.m_description);

    m_id = other.m_id;
    m_state = other.m_state;
}   

void ToDo::erase(){
    delete[] m_description;
}

ToDo::ToDo(){
    m_description = new (std::nothrow) char [1];
    m_description[0] = '\0';
    m_id = 1;
    m_state = false;
}

ToDo::ToDo(const char* description, int id, bool state){
    m_description = new (std::nothrow) char [strlen(description) + 1];
    if(!m_description){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_description, description);

    m_id = id;
    m_state = state;
}

ToDo::ToDo(const ToDo& other){
    copy(other);
}

ToDo& ToDo::operator=(const ToDo& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

ToDo::~ToDo(){
    erase();
}

const char* ToDo::getDescription() const{
    return m_description;
}

int ToDo::getId() const {
    return m_id;
}

bool ToDo::getState() const {
    return m_state;
}

void ToDo::executeTask(){
    if(m_state){
        std::cout << getDescription() << " is aready executed!\n";
        return;
    }
    std::cout << getDescription() << " - executing...\n";
    m_state = true;
}

void ToDo::print() const {
    std::cout << getDescription() << "\n" << getId() << "\n" << std::boolalpha << getState() << std::endl; 
}

int main(){
    ToDo task1("lay in the bed all day", 1, false);
    task1.print();
    task1.executeTask();
    task1.print();
    
    return 0;
}