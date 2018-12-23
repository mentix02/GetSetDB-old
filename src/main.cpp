/*
    author: mentix02
    date: 21.11.18
*/

#include <ctime>
#include "utils.h"
#include <dirent.h>
#include "database.h"

/*

    main.cpp provides the main program loop
    "interpreter" that provides a REPL-like
    shell for executing commands to manage Databases

*/

using namespace std;

const string version = "1.0.2";

const string commands[] = {
    "use", // uses an existing database
    "new", // creates a new database
    "bye", // exits the GSD shell
    "drop", // deleted an existing database
    "help", // displays a list of commands
    "list", // lists all existing databases
    "rename", // TODO renames an existing database
    "version", // displays GetSetDB's version running
    "datetime", // shows current date and time of a database
};

int main() {

    print_banner();

    string database_name; // used in multiple places for specifiying database name

    string command = input(); // get command for the first time

    while (command != "bye" && command != "exit") { // while loop till true

        if (command.substr(0, 3) == "use") {

            if (command.length() <= 4) { // check for correct format and database name
                print_error("database name not specified");
                command = input();
                continue;
            }

            database_name = command.substr(4, sizeof(command));

            ifstream check("/tmp/gsdbdata/" + database_name + ".gsdb"); // check if database exists

            if (check.good()) {

                print_info("using `" + database_name + "`");
                Database database(database_name);
                database.shell();

            } else {
                print_error("database " + database_name + " does not exist");
            }

            check.close();

        }

        else if (command.substr(0, 3) == "new") { // create a new database

            if (command.length() <= 4) { // check if database name was provided
                print_warning("database name not specified");
                command = input();
                continue;
            }


            database_name = command.substr(4, sizeof(command));

            ifstream check(path(database_name));

            if (check.good()) {
                print_warning("database `" + database_name + "` already exists");
                command = input();
                continue;
            }

            print_success("created database `" + database_name + "`");

            Database database(database_name);

        }

        else if (command.substr(0, 4) == "drop") {

            if (command.length() <= 5) {
                print_error("database name not specified");
                command = input();
                continue;
            } else if (command[4] == ' ') {

                database_name = command.substr(5, sizeof(command));
                string path = "/tmp/gsdbdata/" + database_name + ".gsdb";

                int delete_success = remove(path.c_str()); // 0 for success, else for failure

                // check for deletion

                if (delete_success != 0) {
                    print_error("database `" + database_name + "` not found");
                } else {
                    print_success("deleted database `" + database_name + "`");
                }

            }

        }

        else if (command.substr(0, 4) == "help") {
            print_banner();
            print_info("version " + version);
        }

        else if (command.substr(0, 4) == "list") {

            string file_name;      // to store file name

            DIR *dir;             // directory listing
            struct dirent *ent;   // specific functions

            int file_counter = 0; // to counter number of files

            if ((dir = opendir("/tmp/gsdbdata/")) != NULL) {

                while ((ent = readdir(dir)) != NULL) {
                    file_name = ent->d_name;
                    if (file_name == "." || file_name == "..") {
                        continue;
                    }
                    print(to_string(++file_counter) + ". " + file_name.substr(0, file_name.find_last_of("."))); // prints database by removing extension
                }

                print_info("found " + to_string(file_counter) + " databases on disk");

            } else {
                print_warning("directory `data` not found");
            }

        }

        else if (command.substr(0, 8) == "datetime") {

            time_t now = time(0);
            char* dt = ctime(&now);
            print("[i] " + (string)dt, ' ');

        }

        else if (command.length() == 0) {

            // for blank input
            command = input();
            continue;

        }

        else {
            // error handling when command isn't not recognized
            print_error("command `" + command + "` not recognized");
        }

        command = input();

    }
    cout << "[i] quitting\n";
    print("--------------------------------------------------------------");
    return 0;
}
