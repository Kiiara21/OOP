// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
// #include "ValidateData.h"
// #include "Utils.h" 
// #include "Table.h"

// TEST_SUITE("validation data tests"){

//     TEST_CASE("Number Has Only One Dot"){
//         CHECK_FALSE(!Validate::inNumberHasOnlyOneDot("1.1"));
//         CHECK_FALSE(!Validate::inNumberHasOnlyOneDot("1111.6"));
//         CHECK_FALSE(!Validate::inNumberHasOnlyOneDot("-1111.6"));
//         CHECK_FALSE(!Validate::inNumberHasOnlyOneDot("+1111.6"));
//         CHECK_FALSE(Validate::inNumberHasOnlyOneDot("1.1.1"));
//     }

//     TEST_CASE("Valid Number Has Only Number"){
//         CHECK_FALSE(!Validate::inValidNumberHasOnlyNumbers("-11"));
//         CHECK_FALSE(!Validate::inValidNumberHasOnlyNumbers("11"));
//         CHECK_FALSE(!Validate::inValidNumberHasOnlyNumbers("+11"));
//         CHECK_FALSE(!Validate::inValidNumberHasOnlyNumbers("1111.6"));
//         CHECK_FALSE(Validate::inValidNumberHasOnlyNumbers("1.1.b"));
//         CHECK_FALSE(!Validate::inValidNumberHasOnlyNumbers("-11.1"));
//         CHECK_FALSE(!Validate::inValidNumberHasOnlyNumbers("+11.1"));
//     }

//     TEST_CASE("Valid string"){
//         CHECK_FALSE(!Validate::isValidData("1111.6"));
//         CHECK_FALSE(Validate::isValidData("1.1.b"));
//     }

// }

// TEST_SUITE("Utils tests"){

//     TEST_CASE("is letter"){
//         CHECK_FALSE(!Utils::isLetter('q'));
//         CHECK_FALSE(Utils::isLetter('1'));
//         CHECK_FALSE(Utils::isLetter('\"'));
//         CHECK_FALSE(Utils::isLetter('='));
//     }

//     TEST_CASE("is error string"){
//         CHECK_FALSE(!Utils::isErrorString("ERROR"));
//         CHECK_FALSE(Utils::isErrorString("error"));
//         CHECK_FALSE(Utils::isErrorString("blabla"));
//     }

//     TEST_CASE("is formula"){
//         CHECK_FALSE(!Utils::isFormula("=10+10"));
//         CHECK_FALSE(!Utils::isFormula("=R2C4/R5C34"));
//         CHECK_FALSE(Utils::isFormula("1=R2C4/R5C34"));
//         CHECK_FALSE(Utils::isFormula("blabla"));
//         CHECK_FALSE(Utils::isFormula("========="));
//     }

//     TEST_CASE("is formula with references"){
//         CHECK_FALSE(!Utils::hasReferencesOfCells("=R2C4/R5C34"));
//         CHECK_FALSE(Utils::hasReferencesOfCells("=10+10"));
//         CHECK_FALSE(Utils::hasReferencesOfCells("1=R2C4/R5C34"));
//         CHECK_FALSE(!Utils::hasReferencesOfCells("=R2C4/10"));
//         CHECK_FALSE(Utils::hasReferencesOfCells("blabla"));
//         CHECK_FALSE(Utils::hasReferencesOfCells("========="));
//     }

//     TEST_CASE("take converted value"){
//         Cell* convCell = Utils::convertedValue("=10+10");
//         CHECK_EQ(convCell->getValueAsString(), "20");
//     }

//     TEST_CASE("is word"){
//         CHECK_FALSE(!Utils::isWord("\"Quoted\""));
//         CHECK_FALSE(Utils::isWord("1234"));
//         CHECK_FALSE(Utils::isWord("\"Quo123ted\""));
//         CHECK_FALSE(!Utils::isWord("\"\""));
//         CHECK_FALSE(Utils::isWord("===="));
//     }

//     TEST_CASE("Is number"){
//         CHECK_FALSE(!Utils::isNumber('1'));
//         CHECK_FALSE(Utils::isNumber('v'));
//     }

//     TEST_CASE("is arithmetic operation"){
//         CHECK_FALSE(!Utils::isArithmeticOperation('+'));
//         CHECK_FALSE(!Utils::isArithmeticOperation('-'));
//         CHECK_FALSE(!Utils::isArithmeticOperation('*'));
//         CHECK_FALSE(!Utils::isArithmeticOperation('/'));
//         CHECK_FALSE(!Utils::isArithmeticOperation('^'));
//         CHECK_FALSE(Utils::isArithmeticOperation('v'));
//         CHECK_FALSE(Utils::isArithmeticOperation('='));
//         CHECK_FALSE(Utils::isArithmeticOperation('1'));
//     }

//     TEST_CASE("Count Lines In File"){
//         size_t numberOfLineInFile = Utils::countLinesInFile("tables.txt");
//         CHECK_EQ(numberOfLineInFile, 4);
//     }

//     TEST_CASE("Is integer"){
//         CHECK_FALSE(!Utils::isInteger("1"));
//         CHECK_FALSE(Utils::isInteger("1.1"));
//         CHECK_FALSE(Utils::isInteger("Hello world"));
//     }

//     TEST_CASE("Is double"){
//         CHECK_FALSE(!Utils::isDouble("1.1"));
//         CHECK_FALSE(Utils::isDouble("1"));
//         CHECK_FALSE(Utils::isDouble("Hello world"));
//     }
    
//     TEST_CASE("Is empty string"){
//         CHECK_FALSE(!Utils::isEmptyString(""));
//         CHECK_FALSE(Utils::isEmptyString("1"));
//         CHECK_FALSE(Utils::isEmptyString("Hello world"));
//     }

//     TEST_CASE("Has sign"){
//         CHECK_FALSE(!Utils::hasSign("-123"));
//         CHECK_FALSE(!Utils::hasSign("+123"));
//         CHECK_FALSE(!Utils::hasSign("-12.3"));
//         CHECK_FALSE(!Utils::hasSign("+12.3"));
//         CHECK_FALSE(Utils::hasSign("123"));

//     }

//     TEST_CASE("Is positive"){
//         CHECK_FALSE(!Utils::isPositive("+123"));
//         CHECK_FALSE(!Utils::isPositive("123"));
//         CHECK_FALSE(!Utils::isPositive("+12.3"));
//         CHECK_FALSE(!Utils::isPositive("12.3"));
//         CHECK_FALSE(Utils::isPositive("-123"));
//     }

//     TEST_CASE("Is negative"){
//         CHECK_FALSE(!Utils::isNegative("-123"));
//         CHECK_FALSE(!Utils::isNegative("-12.3"));
//         CHECK_FALSE(Utils::isNegative("123"));
//         CHECK_FALSE(Utils::isNegative("12.3"));
//         CHECK_FALSE(Utils::isNegative("+123"));
//         CHECK_FALSE(Utils::isNegative("+12.3"));
//     }

//     TEST_CASE(""){
//         Utils::convertedValue("=1.1^1");
//         Utils::convertedValue("=11+4.5");
//         Utils::convertedValue("=1.1-45");
//         Utils::convertedValue("=44/11");
//     }

//     TEST_CASE("formula has Only Literals"){
//         CHECK_FALSE(!Utils::hasOnlyLiterals("=10+10"));
//         CHECK_FALSE(Utils::hasOnlyLiterals("=10+10k"));
//         CHECK_FALSE(Utils::hasOnlyLiterals("=R1C4*R7C99"));    
//     }

//     TEST_CASE("remove R and C from formula"){
//         std::string reference = "R10C25", rowIndex = "", colIndex = "";
//         Utils::removeRandC(reference, rowIndex, colIndex);
//         CHECK_EQ(std::stoi(rowIndex), 10);
//         CHECK_EQ(std::stoi(colIndex), 25);
//     }

//     TEST_CASE("translate cell"){
//         std::string value1 = "abc";
//         std::string value2 = "";
//         std::string value3 = "123.456";
//         std::string value4 = "123";

//         CHECK_EQ(Utils::translateCell(value1), "0");
//         CHECK_EQ(Utils::translateCell(value2), "0");
//         CHECK_EQ(Utils::translateCell(value3), "123.456");
//         CHECK_EQ(Utils::translateCell(value4), "123");
//     }

//     TEST_CASE("get operation"){
//         std::string formula1 = "=10+10";
//         std::string formula2 = "=10/10";
//         std::string formula3 = "=R1C3*R5C1";
//         CHECK_EQ(Utils::getOperation(formula1), '+');
//         CHECK_EQ(Utils::getOperation(formula2), '/');
//         CHECK_EQ(Utils::getOperation(formula3), '*');
//     }

//     TEST_CASE("get operation position"){
//         std::string formula1 = "=10+10";
//         std::string formula2 = "=1/10";
//         std::string formula3 = "=R1C3*R5C1";
//         CHECK_EQ(Utils::getOperationPosition(formula1), 3);
//         CHECK_EQ(Utils::getOperationPosition(formula2), 2);
//         CHECK_EQ(Utils::getOperationPosition(formula3), 5);
//     }    
// }

// TEST_SUITE("Cells tests"){

//     TEST_SUITE("String cell tests"){
//         TEST_CASE("Get value as string"){
//             StringCell stringCell("Hello world");
//             CHECK_EQ(stringCell.getValueAsString(), "Hello world");
//         }

//         TEST_CASE("Serialize string cell"){
//             StringCell stringCell("Hello world");
//             std::ofstream os("stringTestFile.txt", std::ios::app);
//             stringCell.serializeCell(os);
//             StringCell stringCell2;
//             std::ifstream inputFile("stringTestFile.txt");
//             inputFile >> stringCell2;
//             CHECK_EQ(stringCell.getValueAsString(), stringCell2.getValueAsString());
//         }
//     }

//     TEST_SUITE("Int cell tests"){
//         TEST_CASE("Get value as string"){
//             IntCell intCell(1);
//             CHECK_EQ(intCell.getValueAsString(), "1");
//         }

//         TEST_CASE("Serialize int cell"){
//             IntCell intCell(1);
//             std::ofstream os("intTestFile.txt", std::ios::app);
//             intCell.serializeCell(os);
//             IntCell intCell2;
//             std::ifstream inputFile("intTestFile.txt");
//             inputFile >> intCell2;
//             CHECK_EQ(intCell.getValueAsString(), intCell2.getValueAsString());
//         }
//     }

//     TEST_SUITE("Double cell tests"){
//         TEST_CASE("Get value as string"){
//             DoubleCell doubleCell(1.1);
//             CHECK_EQ(doubleCell.getValueAsString(), "1.1");
//         }

//         TEST_CASE("Serialize double cell"){
//             DoubleCell doubleCell(1.1);
//             std::ofstream os("doubleTestFile.txt", std::ios::app);
//             doubleCell.serializeCell(os);
//             DoubleCell doubleCell2;
//             std::ifstream inputFile("doubleTestFile.txt");
//             inputFile >> doubleCell2;
//             CHECK_EQ(doubleCell.getValueAsString(), doubleCell2.getValueAsString());
//         }
//     }

//     TEST_SUITE("Empty cell tests"){
//         TEST_CASE("Get value as string"){
//             EmptyCell emptyCell;
//             CHECK_EQ(emptyCell.getValueAsString(), "");
//         }

//         TEST_CASE("Serialize empty cell"){
//             EmptyCell emptyCell("");
//             std::ofstream os("emptyTestFile.txt", std::ios::trunc);
//             emptyCell.serializeCell(os);
//             EmptyCell emptyCell2;
//             std::ifstream inputFile("emptyTestFile.txt");
//             inputFile >> emptyCell2;
//             std::cout << emptyCell.getValueAsString() << " " << emptyCell2.getValueAsString();
//             CHECK_EQ(emptyCell.getValueAsString(), emptyCell2.getValueAsString());
//         }
//     }
// }

// TEST_SUITE("Row tests"){
//     TEST_CASE("add empty cell"){
//         Row row;
//         row.addEmptyCell();
//         CHECK_EQ(row[0]->getValueAsString(), "");
//         CHECK_EQ(row.getSize(), 1);
//     }

//     TEST_CASE("add int cell"){
//         Row row;
//         row.addIntCell(1);
//         CHECK_EQ(row[0]->getValueAsString(), "1");
//         CHECK_EQ(row.getSize(), 1);
//     }

//     TEST_CASE("add double cell"){
//         Row row;
//         row.addDoubleCell(1.1);
//         CHECK_EQ(row[0]->getValueAsString(), "1.1");
//         CHECK_EQ(row.getSize(), 1);
//     }

//     TEST_CASE("add empty cell"){
//         Row row;
//         row.addStringCell("blabla");
//         CHECK_EQ(row[0]->getValueAsString(), "blabla");
//         CHECK_EQ(row.getSize(), 1);
//     }

//     TEST_CASE("serializing row"){
//         Row row;
//         row.addIntCell(1);
//         row.addIntCell(1);
//         row.addIntCell(1);
//         std::ofstream os("rowTestsFile.txt", std::ios::trunc);
//         row.serializeRow(os);
//         CHECK_EQ(row[0]->getValueAsString(), "1");
//         CHECK_EQ(row[1]->getValueAsString(), "1");
//         CHECK_EQ(row[2]->getValueAsString(), "1");

//         CHECK_EQ(row.getSize(), 3);
//     }
// }

// TEST_SUITE("Table tests"){
//     TEST_CASE("add empty row"){
//         Table table;
//         table.addEmptyRow(4);
//         CHECK_EQ(table.getSize(), 1);
//         for(int i = 0; i < 4; ++i){
//             CHECK_EQ(table[0]->operator[](i)->getValueAsString(), "");
//         }
//     }

//     TEST_CASE("add non empty row"){
//         Table table;
//         Row* row = new Row;
//         row->addDoubleCell(1.4);
//         row->addEmptyCell();
//         row->addIntCell(4);
//         row->addStringCell("hello world");
        
//         table.addRow(row);
//         CHECK_EQ(table.getSize(), 1);
//         CHECK_EQ(table[0]->operator[](0)->getValueAsString(), "1.4");
//         CHECK_EQ(table[0]->operator[](1)->getValueAsString(), "");
//         CHECK_EQ(table[0]->operator[](2)->getValueAsString(), "4");
//         CHECK_EQ(table[0]->operator[](3)->getValueAsString(), "hello world");
//         delete row;
//     }

//     TEST_CASE("Serialize and deserialize table test"){
//         Table table;
//         Row* row = new Row;
//         row->addDoubleCell(1.4);
//         row->addEmptyCell();
//         row->addIntCell(4);
//         row->addStringCell("hello world");
//         table.addRow(row);

//         // std::ofstream os("tableTestsFile.txt", std::ios::trunc);
//         // table.serializeTable(os);

//         Table table2;
//         std::ifstream is("tableTestsFile.txt");
//         table2.deserializeTable(is);
//         CHECK_EQ(table.getSize(), table2.getSize());
//         CHECK_EQ(table[0]->operator[](0)->getValueAsString(), table2[0]->operator[](0)->getValueAsString());
//         CHECK_EQ(table[0]->operator[](1)->getValueAsString(), table2[0]->operator[](1)->getValueAsString());
//         CHECK_EQ(table[0]->operator[](2)->getValueAsString(), table2[0]->operator[](2)->getValueAsString());
//         CHECK_EQ(table[0]->operator[](3)->getValueAsString(), table2[0]->operator[](3)->getValueAsString());

//         delete row;
//     }
// }