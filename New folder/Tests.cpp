// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
// #include "ValidateData.h"
// #include "Utils.h" 
// #include "Row.h"

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

//     TEST_CASE("is word"){
//         CHECK_FALSE(!Validate::isWord("\"Quoted\""));
//         CHECK_FALSE(Validate::isWord("1234"));
//         CHECK_FALSE(Validate::isWord("\"Quo123ted\""));
//         CHECK_FALSE(!Validate::isWord("\"\""));
//         CHECK_FALSE(Validate::isWord("===="));
//     }
// }

// TEST_SUITE("Utils tests"){

//     TEST_CASE("Is number"){
//         CHECK_FALSE(!Utils::isNumber('1'));
//         CHECK_FALSE(Utils::isNumber('v'));
//     }

//     TEST_CASE("isArithmeticOperation"){
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

//     TEST_CASE("conteins Only Double Numbers"){
//         CHECK_FALSE(!Utils::containsOnlyDoubleNumbers("=1.3+4.5"));
//         CHECK_FALSE(!Utils::containsOnlyDoubleNumbers("=1.3*4.5"));
//         CHECK_FALSE(Utils::containsOnlyDoubleNumbers("=1.3+45"));
//         CHECK_FALSE(Utils::containsOnlyDoubleNumbers("=13+4.5"));
//     }

//     TEST_CASE(""){
//         Utils::convertedValue("=1.1^1");
//         Utils::convertedValue("=11+4.5");
//         Utils::convertedValue("=1.1-45");
//         Utils::convertedValue("=44/11");
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

// }