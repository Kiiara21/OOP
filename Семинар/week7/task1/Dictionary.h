#pragma once
#include "word.h"
#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

class Dictionary {
private:

    Word *m_words;
    size_t m_size;
    size_t m_capacity;

    void copy(const Dictionary& other);
    void erase();
    void resize();

    bool isEmpty() const;
    bool isFull() const;

    void swap(Word& w1, Word& w2);

public:

    Dictionary();
    ~Dictionary();
    Dictionary(const Dictionary& other);
    Dictionary& operator=(const Dictionary& other);

    size_t getSize() const { return m_size; }

    void init(Word* words, const int size);
    void print();
    void add(const Word& toAdd);
    void remove(const char* word);
    char* findMeaning(const char*);
    char* getByIndex(int index);
    void sort();
    void deleteDynamic();
};  