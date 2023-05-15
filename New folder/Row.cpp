#include "Row.h"

void Row::resize(){
    Cell** newRow = new Cell*[m_capacity * INCREASE_STEP];
    for(int i = 0; i < m_size; ++i){
        newRow[i] = m_row[i];
    }

    delete[] m_row;
    m_row = newRow;
    m_capacity *= INCREASE_STEP;
}

void Row::copy(const Row& other){
    m_row = new Cell*[other.m_capacity];
    for(int i = 0; i < m_size; ++i){
        m_row[i] = other.m_row[i]->clone();
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

void Row::erase(){
    for(int i = 0; i < m_size; ++i){
        delete m_row[i];
    }
    delete[] m_row;
}

void Row::add(Cell* cell){
    if(m_size == m_capacity){
        resize();
    }
    m_row[m_size++] = cell;
}

Row::Row(){
    m_row = new Cell*[INITIAL_CAPACITY];
    m_size = 0;
    m_capacity = INITIAL_CAPACITY;
}

Row::Row(const Row& other){
    copy(other);
}

Row& Row::operator=(const Row& other){
    if(&other != this){
        erase();
        copy(other);
    }
    return *this;
}

Row::~Row(){
    erase();
}

void Row::AddEmptyCell(){
    add(new Cell());
}

void Row::addIntCell(const int data){
    add(new IntCell(data));
}

void Row::addStringCell(const string data){
    add(new StringCell(data));
}

void Row::addDoubleCell(const double data){
    add(new DoubleCell(data));
}

void Row::printRow() const{
    for(int i = 0; i < m_size; ++i){
        m_row[i]->print();
        std::cout << " ";
    }
}

void Row::writeRowToFile(const std::string& fileName){
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open()){
        std::cout << "catch ex";
        return;
    }
    for(int i = 0; i < m_size; ++i){
        m_row[i]->writeToFile(fileName);
    }
    file << "\n";
}


