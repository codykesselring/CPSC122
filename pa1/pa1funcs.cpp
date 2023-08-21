#include "pa1funcs.h"

void fillArray(string morseChar[91]){
    /*
    started 2/1/2023 finished 2/1/2023
    This function adds the morse code strings to their corresponding positions of A-Z and 0-9 in their ascii positions
    Parameters: string array that needs filled
    returns: nothing, only assigns strings to array
    Pre: array is initialized with 91 elements
    post: array is filled with morse code
    */
    morseChar['A'] = ".-";
    morseChar['B'] = "-...";
    morseChar['C'] = "-.-.";
    morseChar['D'] = "-..";
    morseChar['E'] = ".";
    morseChar['F'] = "..-.";
    morseChar['G'] = "--.";
    morseChar['H'] = "....";
    morseChar['I'] = "..";
    morseChar['J'] = ".---";
    morseChar['K'] = "-.-";
    morseChar['L'] = ".-..";
    morseChar['M'] = "--";
    morseChar['N'] = "-.";
    morseChar['O'] = "---";
    morseChar['P'] = ".--.";
    morseChar['Q'] = "--.-";
    morseChar['R'] = ".-.";
    morseChar['S'] = "...";
    morseChar['T'] = "-";
    morseChar['U'] = "..-";
    morseChar['V'] = "...-";
    morseChar['W'] = ".--";
    morseChar['X'] = "-..-";
    morseChar['Y'] = "-.--";
    morseChar['Z'] = "--..";
    morseChar['0'] = "-----";
    morseChar['1'] = ".----";
    morseChar['2'] = "..---";
    morseChar['3'] = "...--";
    morseChar['4'] = "....-";
    morseChar['5'] = ".....";
    morseChar['6'] = "-....";
    morseChar['7'] = "--...";
    morseChar['8'] = "---..";
    morseChar['9'] = "----.";
}

char morseToEnglish(string character, string chars[91]){
    /*
    started 2/1/2023 finished 2/1/2023
    Description: runs through the array to check if the morse code string matches the string in the array and returns the index to be converted to the ascii value
    Parameters: morse code string and string of morse code elements
    returns: index of the morse code element
    Pre: array is initialized with 91 elements and character is filled with morse code character
    post: index of the morse code string in the array
    */
    for(int i=0;i<91;i++){
        if(character == chars[i]){
            return i;
        } 
    }
    return 0;
}


string englishToMorse(char character, string chars[91]){
     /*
    started 2/1/2023 finished 2/1/2023
    Description: runs through the array to check if the english character matches the index of the character to the morse code string
    Parameters: morse code string and english character from english file
    returns: morse code string from array
    Pre: array is initialized with 91 elements and character is filled with english character
    post: morse code string at characters index
    */
    for(int i=0;i<91;i++){
        if(character == (char)i){
            return chars[i];
        } 
    }
  return "";
}