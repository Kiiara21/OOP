#include "IO.h"

Table IO::table;
std::string IO::m_currentFile;
bool IO::m_saved, IO::m_closed = true, IO::m_changes;


void IO::menu(){
    std::string command;

    std::cout << ">> ";
    do{
        std::cout << "\nEnter command: ";
        std::cin >> command;
        if(command == "exit"){
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

        else if(command == "help"){
            help();
        }

        else if(command == "print"){
            print();
        }

        else if(command == "edit"){
            edit();
        }
        else std::cout << "Invalid command! Please enter valid command (open, close, save, saveAs, help, exit, print or edit.)";

    }
    while (true);
}

void IO::open() {
    do {
        std::cout << "Enter valid file name: ";
        std::cin >> IO::m_currentFile;
        std::ifstream inputFile(IO::m_currentFile);

        if (inputFile.is_open()) {
            table.deserializeTable(inputFile);
            IO::m_saved = false;
            IO::m_closed = false;
            IO::m_changes = false;

            inputFile.close();
            std::cout << "Successfully opened " << IO::m_currentFile << std::endl;
            break; // Valid file name provided, exit the loop
        }
        else {
            std::cout << "File does not exist!" << std::endl;
        }
    } while (true);
}


void IO::close(){
    if(IO::m_changes && !IO::m_saved){
        std::string input;
        std::cout << "File has not been saved!\nsave/saveas/cancel?\n>";
        std::cin >> input;

        if(input == "save"){
            save();
        }
        else if (input == "saveAs"){
            saveAs();
        }
    }

    IO::m_currentFile = "";
    IO::table.clear();
    IO::m_closed = true;
    std::cout << "\nSuccessfully closed!\n";
}


void IO::save(){
    std::cout << "\nSuccessfully saved!\n";
}

void IO::saveAs(){
    std::cout << "\nSuccessfully saved as!\n";
}


void IO::help(){

}


void IO::print(){

}

void IO::edit(){

}
