#pragma once
#include <iostream>
#include <cstring>

struct Pair {
    char* word;
    char* description;
};

class Word {

private:
    Pair m_pair;
    void copy();
    void deleteDynamic();
    void copy(const Word& other);

public:

    Word();
    ~Word();
    Word(const Word& other);
    Word& operator=(const Word& other);

    char* getWord() { return m_pair.word; }
    char* getDescription() { return m_pair.description; }

    void init(const char* word, const char* description);
    void print() const;
    bool operator==(const char* word);
};