#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "table.h"

TEST_CASE ("print"){
    Table t;
    t.print();   
}