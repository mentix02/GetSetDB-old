#include <fstream>
#include "parser.h"

using namespace std;

void Parser::open(string name) {
    file_name = name;
}

bool Parser::key_exists(string key) {

    string line;

    ifstream file(path(file_name));

    while (getline(file, line)) {
        if (key == line.substr(0, line.find(" "))) {
            return true;
        }
    }

    file.close();
    return false;

}

string Parser::get_value(string key) {
    if (key_exists(key)) {
        string line, value;
        ifstream refile(path(file_name));
        while (getline(refile, line)) {

            if (key == line.substr(0, line.find(" "))) {

                value = line.substr(line.find(" ") + 3, sizeof(line));

                return value;
            }
        }
        refile.close();
    } else {
        return "--not found";
    }
    return "--not found";
}
