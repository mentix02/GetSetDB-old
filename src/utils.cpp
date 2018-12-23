#include "utils.h"

string path(string database_name) {
    return "/tmp/gsdbdata/" + database_name + ".gsdb";
}

void print_banner() {

    print("--------------------------------------------------------------");
    print("   ____      _   ____       _   ____  ____  ");
    print("  / ___| ___| |_/ ___|  ___| |_|  _ \\| __ ) ");
    print(" | |  _ / _ \\ __\\___ \\ / _ \\ __| | | |  _ \\ ");
    print(" | |_| |  __/ |_ ___) |  __/ |_| |_| | |_) |");
    print("  \\____|\\___|\\__|____/ \\___|\\__|____/|____/ ");
    print("--------------------------------------------------------------");

}

string input(string prompt) {
    string command;
    cout << prompt;
    getline(cin, command);
    if (cin.eof()) {
        // if user presses CTRL+D
        print("bye");
        print_info("quitting");
        print("--------------------------------------------------------------");
        exit(EXIT_SUCCESS);
    }
    return command;
}

void print(string text, char ender) {
    cout << text << ender;
}

void print_info(string text, char ender) {
    print("[i] " + text, ender);
}

void print_error(string text, char ender) {
    print("[!] " + text, ender);
}

void print_success(string text, char ender) {
    print("[✓] " + text, ender);
}

void print_warning(string text, char ender) {
    print("[w] " + text, ender);
}
