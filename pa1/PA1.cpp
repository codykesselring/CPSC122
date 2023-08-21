/* 
Cody Kesselrin
2/1/2023
CPSC122
PA1
converts english to morse code and vice versa
I accidentally pushed all files to repo -- required files are input and output text, pa1.cpp, pa1funcs.cpp, and pa1funcs.h
*/

#include "pa1funcs.h"

int main() {
    ifstream inputFile;
    ofstream outputFile;
    char engChar;
    int charCount=0;
    string morseChar, conversion, inputName, outputName, character;
    string morseChars[91];
    cout << "Type: \n-m \nenglish.txt \noutput.txt to convert english message to morse code or \n-t \nmorse.txt \noutput.txt to do the opposite" << endl;
    getline(cin, conversion);
    getline(cin, inputName);
    getline(cin, outputName);
    fillArray(morseChars);
    if(conversion == "-m"){ //translates english to morse code
        inputFile.open(inputName);
        outputFile.open(outputName);
        if (inputFile.is_open()) {
            cout << "Successfully opened input file" << endl;
        }
        else {
            cout << "Failed to open input file" << endl;
            exit(-1);
        }

        if(inputFile.is_open()){
            while(!inputFile.eof()){
                inputFile.get(engChar);
                engChar = toupper(engChar);
                if(inputFile.eof()){
                    break;
                }
                if(engChar == ' '){
                    outputFile << "  ";
                }else if(engChar == '\n'){
                    outputFile << endl;
                }else{
                    outputFile << englishToMorse(engChar, morseChars) << ' ';
                    charCount++;
                }
            }
        }
    }
    else if(conversion == "-t"){ //translates morse to english
        inputFile.open(inputName);
        outputFile.open(outputName);
        if (inputFile.is_open()) {
            cout << "Successfully opened input file" << endl;
        }
        else {
            cout << "Failed to open input file" << endl;
            exit(-1);
        }
        if(inputFile.is_open()){
            while(!inputFile.eof()){
                getline(inputFile, character);
                for(int i=0; i<character.size(); i++){
                    morseChar="";
                    if(character.at(i) == ' ' && character.at(i+1) == ' '){
                        outputFile << ' ';
                        charCount++;
                    } 
                    else{
                        while(character.at(i) != ' ' && character.at(i) != character.size()){ //iterates until the file reaches a space or newline
                            //morseChar adds the character of the morse code
                            morseChar+=character.at(i);
                            if(i<character.size()-1){
                                i++;
                            }
                            else{
                                break;
                            }
                        }
                        engChar = morseToEnglish(morseChar, morseChars);
                        if(i == character.size()-1){
                            charCount++;
                            outputFile << engChar << endl;
                        }
                        else if(engChar == 0){
                            outputFile << ' ';
                        }else{
                            charCount++;
                            outputFile << engChar;
                        }
                    }
                }
            }
        }
    }
    cout << "Characters converted: " << charCount << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}