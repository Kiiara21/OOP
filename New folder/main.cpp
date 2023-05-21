#include "Table.h"
#include "debug_new.h"

int main(){

    Row row1, row2;

    row1.addDoubleCell(-1.2);
    row1.addIntCell(-1);
    row1.addEmptyCell();
    row1.addStringCell("-2.4.2");
    row1.addStringCell("\"Quoted\"");
    row1.addStringCell(""); // when add empty strig this will be empty cell


    row2.addDoubleCell(44);
    row2.addIntCell(12);
    row2.addEmptyCell();
    row2.addStringCell("");

    Row row3;
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();

    Table table;

    table.addRow(&row1);
    table.addRow(&row2); 
    table.addRow(&row3);

    table.serializeTable("output.txt");

    Table table2;
    table2.deserializeTable("output.txt");
    std::cout << std::endl;
    checkMemoryLeaks();

    return 0;
}