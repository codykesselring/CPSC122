/*
 Name: Cody Kesselring
 Class: CPSC 122, Spring 2023
 Date: March 27, 2023
 Programming Assignment: PA5                                                                      
 Description: this header initializes the functions used for the menu UI that the user traverses to modify their song library
*/
#ifndef PA5_H
#define PA5_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = QUIT_OPTION;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif
