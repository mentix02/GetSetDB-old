#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

void print_banner();

string path(string database_name);

string input(string prompt = "> ");

void print(string text, char ender='\n');

void print_info(string text, char ender='\n');

void print_error(string text, char ender='\n');

void print_success(string text, char ender='\n');

void print_warning(string text, char ender='\n');

#endif // UTILS_H
