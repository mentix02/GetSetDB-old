#include "database.h"

using namespace std;

string database_commands[] = {
    "del", // remove a pair
    "set", // assign a key a value
    "all", // list all keys
    "get", // get a value from key
    "name", // returns database name
};

void Database::shell() {

    string command;
    string key, value;
    string sub_command_section;

    command = input(prompt);

    while (command != "exit" && command != "bye") {

        if (command.substr(0, 3) == "set") {

            if (command.length() <= 4) {

                print_error("key and value not specified");

            } else {

                fstream file;

                file.open(path(name), ios::app);
                sub_command_section = command.substr(4, sizeof(command)); // get second part of string

                key = sub_command_section.substr(0, sub_command_section.find_last_of(" ")); // derive key and value
                value = sub_command_section.substr(sub_command_section.find_last_of(" ") + 1, sizeof(sub_command_section));

                file << key << " : " << value << "\n";
                file.close();
            }

        }

        else if (command.substr(0, 3) == "all") {

            string line;
            int counter = 0;
            ifstream file(path(name));

            while (getline(file, line)) {

                print(to_string(++counter) + ". " + line.substr(0, line.find(" ")));

            }

        }

        else if (command.substr(0, 3) == "get") {

            if (command.length() <= 4) {
                print_error("key not specified");
            } else {

                key = command.substr(4, sizeof(command));

                parser.open(name);
                string value = parser.get_value(key);
                if (value != "--not found") {
                    print_success(value);
                } else {
                    print_error("key `" + key + "` not found");
                }
            }

        }

        else if (command.substr(0, 4) == "name") {
            print_info(name);
        }

        else {
            print_error("command `" + command + "` not recognized");
        }

        command = input(prompt);

    }

}

void Database::create_file() {
    ofstream file(path(name));
    file.close();
}

Database::Database(string db_name)
{
    name = db_name; // assign prive variable name

    ifstream exists(path(name));

    if (!exists.good()) {

        create_file(); // create actual file

    }

    parser.open(name); // intialize parser

    prompt = "(" + name + ") > ";

}
