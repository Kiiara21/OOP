#pragma once
#include "Table.h"
#include "Chair.h"
#include "Bed.h"

class FurnitureHouse {

private:

    static const size_t INITIAL_CAPACITY = 2;
    static const size_t INCREASE_STEP = 2;

    Furniture** m_furnitures;    

    size_t m_numberOfFurnitures;
    size_t m_capacity;


    void resize(){
        Furniture** newFurnitures = new Furniture*[m_capacity * INCREASE_STEP];
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            newFurnitures[i] = m_furnitures[i];
        }

        delete[] m_furnitures;
        m_furnitures = newFurnitures;
        m_capacity *= INCREASE_STEP;
    }

    void copy(const FurnitureHouse& other){
        m_furnitures = new Furniture* [other.m_capacity];
        
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            m_furnitures[i] = other.m_furnitures[i]->clone();
        }

        m_numberOfFurnitures = other.m_numberOfFurnitures;
        m_capacity = other.m_capacity;
    }
    
    void erase(){
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            delete[] m_furnitures[i];
        }
        delete[] m_furnitures;
    }

    void add(Furniture* furniture){
        if(m_numberOfFurnitures == m_capacity){
            resize();
        }

        for(int i = 0; i < furniture->getQuantity(); ++i){
            m_furnitures[m_numberOfFurnitures++] = furniture;
        }
    }


public:

    FurnitureHouse(){
        m_furnitures = new Furniture* [INITIAL_CAPACITY];
        m_numberOfFurnitures = 0;
        m_capacity = INITIAL_CAPACITY;
    }

    ~FurnitureHouse(){
        erase();
    }

    FurnitureHouse(const FurnitureHouse& other){
        copy(other);
    }

    FurnitureHouse& operator=(const FurnitureHouse& other){
        if(&other != this){
            erase();
            copy(other);
        }
        return *this;
    }

    size_t getNumberOfFurnitures() const { return m_numberOfFurnitures; }

    void addTable(int width, int height, int length, int quantity, TypeTableSet type){
        add(new Table(width, height, length, quantity, type));
    }

    void addChair(int width, int height, int length, int quantity, TypeChairSet type){
        add(new Chair(width, height, length, quantity, type));
    }

    void addBed(int width, int height, int length, int quantity){
        add(new Bed(width, height, length, quantity));
    }

    void remove(int id){
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            if(m_furnitures[i]->getId() == id){
                if(m_furnitures[i]->getQuantity() == 0){
                    m_furnitures[i] = m_furnitures[m_numberOfFurnitures - 1];
                    m_numberOfFurnitures--;
                }
                else if(m_furnitures[i]->getQuantity() != 0) {
                    m_furnitures[i]->decreasesQuantity();
                    m_numberOfFurnitures--;
                }
            }
        }
    }

    void showCharacteristicsById(int id){
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            std::cout << m_furnitures[i]->getId() << "\n";
            if(m_furnitures[i]->getId() == id){
                m_furnitures[i]->getInfo();
            }
        }
    }

    int getIdOfМostЕxpensiveFurniture(){
        int maxId = 0;
        int maxPrice = 0;
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            if(m_furnitures[i]->price() > maxPrice){
                maxPrice = m_furnitures[i]->price();
                maxId = m_furnitures[i]->getId();
            }
        }

        return maxId;
    }

    void showMostExpenisiveFurnitureCharacteristics(){
        int mostExpensiveFurnitureId = getIdOfМostЕxpensiveFurniture();
        for(int i = 0; i < m_numberOfFurnitures; ++i){
            if(m_furnitures[i]->getId() == mostExpensiveFurnitureId){
                m_furnitures[i]->getInfo();
            }
        }
    }

};