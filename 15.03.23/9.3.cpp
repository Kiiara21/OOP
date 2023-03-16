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

    Dictionary operator+(Dictionary& other){
        Dictionary result;

        if(m_size + other.m_size > 500){
            while(m_size + other.m_size < 500){
                other.m_size--;
                if(other.m_size == 0){
                    m_size--;
                }
            }
        } 

        if(m_size == other.m_size){
            for(int i = 0; i < m_size; ++i){
                result.addElement(m_elements[i]);
                result.addElement(other.m_elements[i]);
            }
        }

        else if(m_size < other.m_size){
            for(int i = 0; i < m_size; ++i){
                result.addElement(m_elements[i]);
                result.addElement(other.m_elements[i]);
            }
            for(int i = m_size; i < other.m_size; ++i){
                result.addElement(other.m_elements[i]);
            }
        }

        else if(other.m_size < m_size){
            for(int i = 0; i < other.m_size; ++i){
                result.addElement(m_elements[i]);
                result.addElement(other.m_elements[i]);
            }
            for(int i = other.m_size; i < m_size; ++i){
                result.addElement(m_elements[i]);
            }
        }
        result.m_size = m_size + other.m_size;
        return result;
    }
};

int main(){
    DictionaryElement elem1, elem2;
    strcpy(elem1.word, "bla");
    strcpy(elem1.value, "vla");

    strcpy(elem2.word, "blabla");
    strcpy(elem2.value, "vlavla");

    Dictionary dict;
    dict.addElement(elem1);

    Dictionary dict2, dict3;
    dict2.addElement(elem2);
    dict2.addElement(elem1);

    dict3 = dict + dict2;
    std::cout << dict3.getSize();
    dict3.print();

    return 0;
}