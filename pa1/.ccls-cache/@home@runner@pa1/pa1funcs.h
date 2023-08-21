#ifndef PA1FUNCS_H
#define PA1FUNCS_H

#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <cctype>

using namespace std;

void fillArray(string arr[91]);
string englishToMorse(char character, string chars[91]);
char morseToEnglish(string character, string chars[91]);

#endif