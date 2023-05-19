#include "Table.h"

int main(){

    Row row1, row2;

    row1.addDoubleCell(-1.2);
    row1.addIntCell(-1);
    row1.addEmptyCell();
    row1.addStringCell("2.4");
    row1.addStringCell("sdssssssssssf");


    row2.addDoubleCell(1.2);
    row2.addIntCell(1);
    row2.addEmptyCell();
    row2.addStringCell("sdssssssssssf");

    Row row3;
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();

    Table table;

    table.addRow(&row1);
    // table.addRow(&row2); 
    // table.addRow(&row3);

    table.serializeTable("output.txt");

    Row row;
    row.printRow();
    deserializeRow("output.txt", row);
    // row.printRow();

    // Table table2;
    // table2.deserializeTable("output.txt");
    // table2.printTable();

    return 0;
}