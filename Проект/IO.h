#pragma once
#include "Table.h"

class IO {

private:

    static std::string m_currentFile;
    static bool m_saved, m_closed, m_changes;
    static Table table;

public:

    static void menu();

    static void open();
    static void close();

    static void save();
    static void saveAs();

    static void print();

    static void help();
    static void edit();


};