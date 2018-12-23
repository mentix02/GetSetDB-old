#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include "utils.h"
#include "parser.h"
#include <iostream>
#include <unordered_map>

using namespace std;


/*
    Database.h provides an interface for the main program loop
    to manage specfic database and perform CRUD operations on
    the key-value pairs inside of the .gsdb files
*/

class Database
{
    public:

        void create_file(); // creates file in `data/` directory

        Database(std::string); // constructor for creating new database

        void shell();

    protected:

    private:
        Parser parser;
        string name, prompt;
        unordered_map<string, string> data;
};

#endif // DATABASE_H
