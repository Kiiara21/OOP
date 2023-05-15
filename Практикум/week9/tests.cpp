#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Bed.h"
#include "Chair.h"
#include "Table.h"
#include "FurnitureHouse.h"

TEST_CASE("get bed price"){
    Bed bed(10, 10, 10, 2);
    CHECK_EQ(bed.price(), 2200);
}

TEST_CASE("get chair price"){
    Chair chair(10, 10, 10, 2, TypeChairSet::Wooden);
    CHECK_EQ(chair.price(), 900);
}

TEST_CASE("get table price"){
    Table table(10, 10, 10, 2, TypeTableSet::LivingRoom);
    CHECK_EQ(table.price(), 1500);
}

TEST_CASE("Get chair type"){
    Chair chair(10, 10, 10, 2, TypeChairSet::Metal);
    CHECK_EQ(chair.getType(), TypeChairSet::Metal);
}

TEST_CASE("Get table type"){
    Table table(10, 10, 10, 2, TypeTableSet::Кitchen);
    CHECK_EQ(table.getType(), TypeTableSet::Кitchen);
}

TEST_CASE("Get next id"){
    Table table(10, 10, 10, 2, TypeTableSet::LivingRoom);
    CHECK_EQ(table.getId(), 12);
}

TEST_CASE("Furniture house init"){
    FurnitureHouse fh;
    CHECK_EQ(fh.getNumberOfFurnitures(), 0);
}

TEST_CASE("Furniture quantity decrease"){
    Table table(10, 10, 10, 2, TypeTableSet::Кitchen);
    table.decreasesQuantity();
    CHECK_EQ(table.getQuantity(), 1);
}

TEST_CASE("Add furniture in house"){
    FurnitureHouse fh;
    fh.addTable(10, 10, 10, 2, TypeTableSet::Кitchen);
    CHECK_EQ(fh.getNumberOfFurnitures(), 2);
}

TEST_CASE("Remove furniture from house"){
    FurnitureHouse fh;
    fh.addTable(10, 10, 10, 2, TypeTableSet::Кitchen);
    std::cout << fh.getNumberOfFurnitures();
    fh.remove(18);
    CHECK_EQ(fh.getNumberOfFurnitures(), 1);
}

TEST_CASE("Most expensive furniture"){
    FurnitureHouse fh;
    fh.addTable(10, 10, 10, 2, TypeTableSet::Кitchen);
    fh.addTable(1, 1, 10, 2, TypeTableSet::Кitchen);
    fh.showCharacteristicsById(20);
    CHECK_EQ(fh.getIdOfМostЕxpensiveFurniture(), 20);
}

