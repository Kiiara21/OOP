#include "word.h"

void Word::copy(){
    Pair newPair;
    newPair.description = new (std::nothrow) char [strlen(m_pair.description) + 1]; 
    if(!newPair.description){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(newPair.description, m_pair.description);
    
    newPair.word = new (std::nothrow) char [strlen(m_pair.word) + 1]; 
    if(!newPair.word){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(newPair.word, m_pair.word);
    
}

void Word::print() const{
    std::cout << m_pair.word << " - " << m_pair.description << std::endl;
}

void Word::deleteDynamic(){
    delete[] m_pair.description;
    delete[] m_pair.word;
    m_pair.word = nullptr;
    m_pair.description = nullptr;
}

void Word::init(const char* word, const char* description){
    m_pair.word = new (std::nothrow) char [strlen(word) + 1]; 
    if(!m_pair.word){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_pair.word, word);

    m_pair.description = new (std::nothrow) char [strlen(description) + 1]; 
    if(!m_pair.description){
        std::cout << "Memory problem!";
        return;
    }
    strcpy(m_pair.description, description);
}

void Word::copy(const Word& other){
    m_pair = other.m_pair;
}

Word::Word(){
    m_pair.word = nullptr;
    m_pair.description = nullptr;
}

Word::~Word(){
    deleteDynamic();
}

Word::Word(const Word& other){
    copy(other);
}

Word& Word::operator=(const Word& other){
    if(&other != this){
        deleteDynamic();
        copy(other);
    }
    return *this;
}


bool Word::operator==(const char* word){
    return (strcmp(m_pair.word, word) == 0);
}
