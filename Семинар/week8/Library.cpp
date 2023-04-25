#include "Library.h"

void Library::copy(const Library& other){
    m_pairs = new (std::nothrow) Pair [other.m_capacity];
    if(m_pairs == nullptr){
        throw std::bad_alloc();
    }

    for(int i = 0; i < other.m_size; ++i){
        m_pairs[i] = other.m_pairs[i];
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

void Library::erase(){
    delete[] m_pairs;
}

void Library::resize(){
    Pair* newPairs = new (std::nothrow) Pair [m_capacity*INCREASE_STEP];
    if(newPairs == nullptr){
        throw std::bad_alloc();
    }

    for(int i = 0; i < m_size; ++i){
        newPairs[i] = m_pairs[i];
    }
    
    erase();
    m_pairs = newPairs;
    m_capacity *= INCREASE_STEP;
}

Library::Library(){
    m_pairs = new (std::nothrow) Pair [INITIAL_CAPACITY];
    if(m_pairs == nullptr){
        throw std::bad_alloc();
    }

    m_size = 0;
    m_capacity = INITIAL_CAPACITY; 
}

Library::Library(const Pair* pairs, const size_t numberOfPairs){
    m_pairs = new (std::nothrow) Pair [numberOfPairs];
    if(m_pairs == nullptr){
        throw std::bad_alloc();
    }

    for(int i = 0; i < numberOfPairs; ++i){
        m_pairs[i] = pairs[i];
    }
    m_size = numberOfPairs;
    m_capacity = numberOfPairs * INCREASE_STEP;
}

Library::Library(const Library& other){
    copy(other);
}

Library::~Library(){
    erase();
}

Library& Library::operator=(const Library& other){
    if(&other != this){
        erase();
        copy(other);
    }

    return *this;
}

int Library::operator[] (const string name) const{

    if(name == ""){
        throw std::invalid_argument("Name is empty string");
    }

    for(int i = 0; i < m_size; ++i){
        if(m_pairs[i].book.getName() == name){
            return m_pairs[i].count;
        }
    }

    return -1;
}

void Library::takeBook(Book& bookToTake){
    for(int i = 0; i < m_size; ++i){
        if(m_pairs[i].book == bookToTake){
            m_pairs[i] = m_pairs[m_size-1];
            m_size--;
            break;
        }
    }
}

void Library::sortLibrary(){
    for(int i = 0; i < m_size; ++i){
        for(int j = i + 1; j < m_size; ++j){
            if(m_pairs[i].book.getName() < m_pairs[j].book.getName()){
                Pair temp = m_pairs[i];
                m_pairs[i] = m_pairs[j];
                m_pairs[j] = temp;
            }
        }
    }
}

Book* Library::allBooksWithAuthor(const Author& author){
    int k = 0;
    Book* resultBooks = new (std::nothrow) Book [m_size];
    if(resultBooks == nullptr){
        throw std::bad_alloc();
    }

    for(int i = 0; i < m_size; ++i){
        if(m_pairs[i].book.hasAuthor(author.getName(), author.getLastName())){
            resultBooks[k] = m_pairs[i].book;
            k++;
        }
    }
    return resultBooks;
}

bool Library::hasBookInLibrary(const Book& book){
    for(int i = 0; i < m_size; ++i){
        if(m_pairs[i].book == book){
            return true;
        }
    }

    return false;
}

void writeToFile(std::ostream fileToWriteIn, const Library& library){
    fileToWriteIn << library;
}

void readFromFile(std::istream fileToReadFrom, Library& library){
    fileToReadFrom >> library;
}

std::ostream& operator<< (std::ostream& out, const Library& library){
    for(int i = 0; i < library.m_size; ++i){
        out << library.m_pairs[i].book << " " << library.m_pairs[i].count << "\n";
    }
    return out;
}

std::istream& operator>> (std::istream& in, Library& library){
    for(int i = 0; i < library.m_size; ++i){
        in >> library.m_pairs[i].book;
        in >> library.m_pairs[i].count;
    }
    return in;
}
