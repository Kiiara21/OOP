#include "Dictionary.h"

void Dictionary::copy(const Dictionary& other){
    m_words = new (std::nothrow) Word [other.m_capacity];
    if(!m_words){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < other.m_size; ++i){
        m_words[i] = other.m_words[i];
    }

    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

void Dictionary::erase(){
    delete[] m_words;
}

void Dictionary::resize(){
    Word* newWords = new (std::nothrow) Word [m_capacity * INCREASE_STEP];
    if(!newWords){
        std::cout << "Memory problem!";
        return;
    }

    for(int i = 0; i < m_size; ++i){
        newWords[i] = m_words[i];
    }

    erase();
    m_words = newWords;
    m_capacity *= INCREASE_STEP;
}

bool Dictionary::isEmpty() const{
    return m_size == 0;
}

bool Dictionary::isFull() const{
    return m_size == m_capacity;
}


Dictionary::Dictionary(){
    m_words = new (std::nothrow) Word [INITIAL_CAPACITY];
    if(!m_words){
        std::cout << "Memory problem!";
    }
    m_size = 0;
    m_capacity = INITIAL_CAPACITY;
}

Dictionary::~Dictionary(){
    erase();
}

Dictionary::Dictionary(const Dictionary& other){
    copy(other);
}

Dictionary& Dictionary::operator=(const Dictionary& other){
    if(&other != this){
        erase();
        copy(other);
    }

    return *this;
}

void Dictionary::init(Word* words, const int size){
    m_words = new (std::nothrow) Word [size];
    if(!m_words){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < size; ++i){
        m_words[i] = words[i];
    }

    m_size = size;
    m_capacity = size;
}

void Dictionary::print(){   
    for(int i = 0; i< m_size; ++i){
        m_words[i].print();
    }
}

void Dictionary::add(const Word& toAdd){
    if(isFull()){
        resize();
    }
    m_words[m_size++] = toAdd;
}

void Dictionary::remove(const char* word){
    for(int i = 0; i < m_size; ++i){
        if(m_words[i] == word){
            m_words[i] = m_words[m_size - 1];
            m_size--;
            return;
        }
    }
    std::cout << "Don`t have such word!";
}

char* Dictionary::findMeaning(const char* word){
    for(int i = 0; i < m_size; ++i){
        if(m_words[i] == word){
            return m_words[i].getDescription();
        }
    }
    std::cout << "Don`t have such word!";
    return nullptr;
}

char* Dictionary::getByIndex(int index){
    assert(index <= m_size);
    for(int i = 0; i< m_size; ++i){
        if(i == index){
            return m_words[i].getDescription();
        }
    }
    std::cout << "Don`t have such word!";
    return nullptr;
}


void Dictionary::swap(Word& w1, Word& w2){
    Word temp = w1;
    w1 = w2;
    w2 = temp;
}

void Dictionary::sort(){
    for(int i = 0; i < m_size; ++i){
        for(int j = i+1; j < m_size; ++j){
            if(strcmp(m_words[i].getWord(), m_words[j].getWord()) < 0){
                swap(m_words[i], m_words[j]);
            }
        }
    }
}

void Dictionary::deleteDynamic(){
    erase();
}   
