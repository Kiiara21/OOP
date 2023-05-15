#pragma once
#include "CrudRepository.h"
#include "FurnitureHouse.h"

// T = furniture*

template <class T, class ID>
class FurnitureHouseMemory : public CrudRepository<T, ID> {

private:

public:

    void create(const T& object){
        FurnitureHouse furnitureHouse;
        for(int i = 0; i < ID; ++i){
            furnitureHouse.add(other[i]);
        }
    }

    const T& read(ID id) const;

    void update(ID id, const T& newObject);
    void d_remove(ID id);

};

