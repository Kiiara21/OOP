// #include "Table.h"
#include "IO.h"
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
    row2.addStringCell("=10+10");
    row2.addStringCell("=10/0");


    Row row3;
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();

    Table table;

    table.addRow(&row1);
    table.addRow(&row2); 
    table.addEmptyRow(5);
    table.addRow(&row3);

    // std::ofstream outputFile("tables.txt", std::ios::trunc);
    // table.serializeTable(outputFile); // have to serialize table befure start the menu


    IO::menu();

    return 0;
}