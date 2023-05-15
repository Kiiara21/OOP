#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Cell.h"
#include "IntCell.h"
#include "StringCell.h"
#include "DoubleCell.h"
#include "Table.h"
#include <string>

using std::string;

TEST_SUITE("Cell tests"){
    TEST_CASE("init string cell"){
        StringCell stringCell("123");
        CHECK_EQ(stringCell.getId(), 1);
        CHECK_EQ(stringCell.getData(), "123");
    }

    TEST_CASE("init int cell"){
        IntCell intCell(123);
        CHECK_EQ(intCell.getId(), 2);
        CHECK_EQ(intCell.getData(), 123);
    }

    TEST_CASE("init string cell"){
        DoubleCell doubleCell(123.456);
        CHECK_EQ(doubleCell.getId(), 3);
        CHECK_EQ(doubleCell.getData(), 123.456);
    }

}

TEST_SUITE("Table tests"){
    TEST_CASE("Size of empty table"){
        Table table;
        CHECK_EQ(table.getSize(), 0);
    }

    TEST_CASE("Add in table"){
        Table table;
        StringCell cellToAdd("123");
        table.addCell(cellToAdd);
        CHECK_EQ(table.getSize(), 1);
    }
    
}