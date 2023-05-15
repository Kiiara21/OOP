#include "Table.h"
#include <sstream>

// void readTableFromFile(const std::string& fileName, Table& table){

//     std::ifstream inputFile(fileName);
//     // ex

//     std::string line;
//     while(std::getline(inputFile, line)){
//         Row row;
//         std::istringstream iss(line);
//         std::string cell;
//         while(std::getline(iss, cell, '|')){
//             std::cout << cell;
//             row.addStringCell(cell);
//         }
//         table.addRow(&row);
//         // std::cout << "\n" << table.getSize() << "\n";
//     }
//     // table.writeTableInFile("output2.txt");

// }

int main(){

    Row row1, row2;

    row1.addDoubleCell(1.2);
    row1.addIntCell(1);
    row1.AddEmptyCell();
    row1.addStringCell("sdf");

    row2.addDoubleCell(1.2);
    row2.addIntCell(1);
    row2.AddEmptyCell();
    row2.addStringCell("sdf");

    Table table;

    table.addRow(&row1);
    table.addRow(&row2); 

    table.writeTableInFile("output.txt");
    return 0;
}