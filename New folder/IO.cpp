#include "IO.h"

#define TXTEXTENSION ".txt"

Table IO::table;
std::string IO::m_currentFile;
bool IO::m_saved, IO::m_closed = true, IO::m_changes;

void IO::menu(){
    IO::table.clear();

    std::string command;

    std::cout << ">> ";
    do{
        std::cout << "\nEnter command: ";
        std::cin >> command;
        if ((command == "print" || command == "save" || command == "saveAs" || command == "close") && IO::m_closed != false){
            std::cout << "Please, first open file!";
        }
        else if(command == "exit"){
            if(m_closed) {
                checkMemoryLeaks();
                break;
            }
            std::cout << "You have not closed " << IO::m_currentFile << std::endl;
        }
        else if(command == "open"){
            open();
        }
        else if(command == "close"){
            close();
        }
        else if(command == "save"){
            save();
        }
        else if(command == "saveAs"){
            saveAs();
        }
        else if(command == "edit"){
            edit();
        }
        else if(command == "help"){
            help();
        }
        else if(command == "print"){
            print();
        }
        else std::cout << "Invalid command! Please enter valid command (open, close, save, saveAs, help, exit, print or edit.)";

    }
    while (true);
}

void IO::open() {
    do {
        std::cout << "Enter valid file name: ";
        std::cin >> IO::m_currentFile;
        std::string fileNameExtension = IO::m_currentFile.substr(IO::m_currentFile.length() - 4, strlen(TXTEXTENSION));
        
        try {
            if (fileNameExtension != TXTEXTENSION) {
                throw std::runtime_error("File is not a text file");
            }
            
            std::ifstream inputFile(IO::m_currentFile);
            if (inputFile.is_open()) {
                table.deserializeTable(inputFile);
                IO::m_saved = false;
                IO::m_closed = false;
                IO::m_changes = false;

                inputFile.close();
                std::cout << "Successfully opened " << IO::m_currentFile << std::endl;
                break;
            } else {
                std::cout << "File does not exist!" << std::endl;
            }
        } 
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return;
        }

    } while (true);
}

void IO::close() {
    if (IO::m_changes && !IO::m_saved) {
        std::string input;
        std::cout << "File has not been saved!\nsave/saveAs/cancel?\n>";
        std::cin >> input;

        try {
            if (input == "save") {
                save();
            }
            else if (input == "saveAs") {
                saveAs();
            }
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return;
        }
    }

    IO::m_currentFile = "";
    IO::table.clear();
    IO::m_closed = true;
    std::cout << "\nSuccessfully closed!\n";
}

void IO::save(){
    std::ofstream outputFile(IO::m_currentFile, std::ios::trunc);

    IO::table.serializeTable(outputFile);

    IO::m_saved = true;
    IO::m_changes = false;
    outputFile.close();
    std::cout << "\nSuccessfully saved to \n" << IO::m_currentFile << std::endl;
}

void IO::saveAs() {
    try {
        std::cout << "\nEnter file name to create new file: ";
        std::cin >> IO::m_currentFile;
        std::string fileNameExtension = IO::m_currentFile.substr(IO::m_currentFile.length() - 4, strlen(TXTEXTENSION));
        
        if (fileNameExtension != TXTEXTENSION) {
            throw std::runtime_error("Try to save at a non-txt file");
        }
        
        std::ofstream newOutputFile(IO::m_currentFile, std::ios::trunc);
        IO::table.serializeTable(newOutputFile);
        
        IO::m_saved = true;
        IO::m_changes = false;
        newOutputFile.close();
        std::cout << "\nSuccessfully saved to\n" << IO::m_currentFile << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return;
    }
}

void IO::help(){
    std::cout 
            << "Supported commands are:\n"
            << "File commands:\n"
            << "open <file name>.txt - Opens txt file in the editor.\n"
            << "save - Saves the currently opened file.\n"
            << "saveas <file name>.txt - Saves the currently opened file as new file.\n"
            << "close - Closes the currently opened file if it has been saved.\n"
            << "edit - Edit cell on row and column with new value\n\n"
            
            << "Util commands are:\n"
            << "print - Prints out the file information about all the cells.\n"
            << "help - Prints out this menu.\n"
            << "exit - Exits the program and saves opened files if not saved.\n";
}

void IO::edit() {
    int row, col;
    std::string newValue;

    do {
        std::cout << "\nEnter valid row and column to edit cell: ";
        std::cin >> row >> col;
    } while (row < 0 || row >= table.getSize() || col < 0 || col >= table[row]->getSize());

    do
    {
        std::cout << "\nEnter valid value to edit with: ";
        std::cin >> newValue;
    } while (!Validate::isValidData(newValue));
    
    try {
        if (Utils::isEmptyString(newValue)) {
            Cell* newCell;
            IO::table[row]->addAtPosition(col, newCell);
        }
        else if (Utils::isInteger(newValue)) {
            Cell* newCell = new IntCell(std::stoi(newValue));
            IO::table[row]->addAtPosition(col, newCell);
        }
        else if (Utils::isDouble(newValue)) {
            Cell* newCell = new DoubleCell(std::stod(newValue));
            IO::table[row]->addAtPosition(col, newCell);
        }
        else {
            Cell* newCell = new StringCell(newValue);
            IO::table[row]->addAtPosition(col, newCell);
        }
    }
    catch (const std::out_of_range& e) {
        std::cout << "\nError: " << e.what() << std::endl;
    }
}

void IO::print(){
    IO::table.clear();
    std::ifstream inputFile(IO::m_currentFile);
    IO::table.deserializeTable(inputFile);
    IO::table.printTable();
}   
