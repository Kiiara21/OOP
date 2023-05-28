// #include "Table.h"
#include "IO.h"

int main(){

    Row row1, row2;

    row1.addStringCell("123");
    row1.addStringCell("123.456.789");
    row1.addDoubleCell(123.456);
    row1.addStringCell("Hello world");
    row1.addStringCell("123abc");
    row1.addIntCell(1);
    row1.addIntCell(2);


    row2.addStringCell("=1+1");
    row2.addStringCell("=10/0");
    row2.addStringCell("=R0C0-R1C10");
    row2.addStringCell("=R0C0-R1C0");
    row2.addStringCell("=R0C0-R0C3");
    row2.addStringCell("=R0C0-R0C2");


    Row row3;
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addEmptyCell();
    row3.addStringCell("=R0C0/R1C2");
    row3.addStringCell("=R0C0/R0C2");
    row3.addStringCell("=R0C0*R1C2");
    row3.addStringCell("=R0C0^R1C0");
    row3.addStringCell("=R0C0^R0C2");

    Table table;

    table.addRow(&row1);
    table.addRow(&row2); 
    table.addEmptyRow(5);
    table.addRow(&row3);

    // std::ofstream outputFile("tables.txt", std::ios::trunc);
    // table.serializeTable(outputFile); // have to serialize table before start the menu

    IO::menu();

    return 0;
}