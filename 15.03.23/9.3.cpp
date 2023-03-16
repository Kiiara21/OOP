#include <iostream>
#include <cstring>

const size_t MAX_WORD_SIZE = 100;
const size_t MAX_VALUE_SIZE = 500;

struct DictionaryElement{
    char word[100];
    char value[500];
};

class Dictionary {

private:
    DictionaryElement m_elements[500];  
    size_t m_size;
public:
    Dictionary(){
        m_size = 0;
        for(int i = 0; i < m_size; ++i){
            strcpy(m_elements[i].word, "");
            strcpy(m_elements[i].value, "");
        }
    }

    Dictionary(DictionaryElement* elements, size_t size){
        m_size = 0;
        for(int i = 0; i < m_size; ++i){
            strcpy(m_elements[i].word, elements[i].word);
            strcpy(m_elements[i].value, elements[i].value);
        }
    }

    void print() const{
        for(int i = 0; i < m_size; ++i){
            std::cout << m_elements[i].word << " - " << m_elements[i].value << std::endl;
        }
    }

    size_t getSize() const { return m_size; }

    bool addElement(DictionaryElement& newElement){
        for(int i = 0; i < m_size; ++i){
            if(strcmp(newElement.word, m_elements[i].word) == 0){
                std::cout << "\nThis word already exist in our dictionary!\n";
                return false;
            }
        }
        strcpy(m_elements[m_size].word, newElement.word);
        strcpy(m_elements[m_size].value, newElement.value);
        m_size++;
        std::cout << "\nSuccessfull add new element!\n";
        return true;
    }

    bool removeElement(const char* word){
        for(int i = 0; i < m_size; ++i){
            if(strcmp(m_elements[i].word, word) == 0){
                strcpy(m_elements[i].word, m_elements[m_size].word);
                strcpy(m_elements[i].value, m_elements[m_size].value);
                m_size--;
                return true;
            }
        }
        std::cout << "\nThere is no have such element!\n";
        return false;
    }

    bool findValue(const char* word){
        for(int i = 0; i < m_size; ++i){
            if(strcmp(m_elements[i].word, word) == 0){
                std::cout << "\nValue: " << m_elements[i].value;
                return true;
            }
        }
        std::cout << "\nThere is no have such element!\n";
        return false;
    }

    // void printAlphabeticaly() const{
    //     sort(m_elements);
    //     print();
    // }
};

int main(){
    DictionaryElement elem1;
    strcpy(elem1.word, "bla");
    strcpy(elem1.value, "vla");

    Dictionary dict;
    dict.addElement(elem1);
    dict.print();
    std::cout << dict.getSize();
    dict.findValue("bla");
    dict.removeElement("bla");
    dict.print();
    std::cout << std::endl << dict.getSize();
    dict.findValue("bla");
    

    return 0;
}