/* 
Cody Kesselrin
2/1/2023
CPSC122
PA1
converts english to morse code and vice versa
*/

#include "pa1funcs.h"

int main() {
    ifstream inputFile;
    ofstream outputFile;
    char spaceCheck, engChar;
    int charCount=0;
    string morseChar, conversion, inputName, outputName, character;
    string morseChars[91];
    cout << "The input file should be a file containg letters or morse code and the output file is the file that the input will be translated to"<< endl;
    cout << "Type \"-m \nenglish.txt \noutput.txt\" to convert english message to morse code or \"-t morse.txt output.txt\" to do the opposesite for example" << endl;
    getline(cin, conversion);
    getline(cin, inputName);
    getline(cin, outputName);
    fillArray(morseChars);
    if(conversion == "-m"){
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
                cout << engChar;
                if(inputFile.eof()){
                    break;
                }
                if(engChar == ' '){
                    outputFile << "  ";
                    charCount++;
                }else if(engChar == '\n'){
                    outputFile << endl;
                }else{
                    outputFile << englishToMorse(engChar, morseChars) << ' ';
                    charCount++;
                }
            }
        }
    }
    else if(conversion == "-t"){
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
                cout << character << " @ " << endl;
                for(int i=0; i<character.size(); i++){
                    morseChar="";
                    if(character.at(i) == ' ' && character.at(i+1) == ' '){
                        outputFile << ' ';
                        charCount++;
                    } 
                    else{
                        while(character.at(i) != ' ' && character.at(i) != character.size()){
                            cout << morseChar << " * " << character.at(i) << " beans " << (int)character.at(i) << endl;
                            morseChar+=character.at(i);
                            charCount++;
                            cout << morseChar << " *after " << endl;
                            if(i<character.size()-1){
                                i++;
                            }
                            else{
                                break;
                            }
                        }
                        cout << morseChar << " line 83"<< endl;
                        engChar = morseToEnglish(morseChar, morseChars);
                        cout << (int)engChar << endl;
                       
                        if(i == character.size()-1){
                            outputFile << engChar << endl;
                        }
                        else if(engChar == 0){
                            outputFile << " ";
                        }else{
                            outputFile << engChar;
                        }
                    }
                }
            }
        }
    }
    cout << charCount << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}