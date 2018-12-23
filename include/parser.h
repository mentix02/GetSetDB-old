#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include "utils.h"

using namespace std;

class Parser
{
    public:
        void open(string name);
        bool key_exists(string key);
        string get_value(string key);

    protected:

    private:
        string file_name;
};

#endif // PARSER_H
