#include "PA6.h"

/*
displayMenu()
created 4/1/2023, modified 4/1/2023
Description: displays the menu options that the user can choose from
*/
void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Insert song in order" << endl;
	cout << "7) Remove song" << endl;
	cout << "8) Edit song" << endl;
	cout << "9) Exit" << endl;
}
/*
getValidChoice()
created 4/1/2023, modified 4/1/2023
Description: takes the user input for the menu option that the user wants to select and makes sure it's a valid option
Returns: the integer choice the user enters
*/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}
/*
executeUserChoice()
created 3/22/2023, modified 2/22/2023
Description: calls the function based on the menu option the user selectes
*/
void executeUserChoice(int choice, SongLibrary& lib) {
	switch (choice) {
		case 1:
			// TODO: call a member function, something like lib.loadLibrary();
      lib.loadSongFile();
			break;
		case 2:
			// TODO: call a member function, something like lib.saveLibrary();
      lib.saveFileName();
			break;
		case 3: 
			// TODO: call a member function, something like lib.displayLibrary();
      lib.displayLibrary();
			break;
		case 4:
			// TODO: call a member function, something like lib.sortLibrary();
      lib.sortAttributeFunc();
			break;
		case 5:
			// TODO: call a member function, something like lib.searchLibrary();
      lib.searchAttribute();
			break;
		case 6:
			// TODO: call a member function, something like lib.insertSongInLibraryOrder();
      lib.addSong();
			break;
		case 7:
			// TODO: call a member function, something like lib.removeSongFromLibrary();
      lib.removeUserSong();
			break;
		case 8:
			// TODO: call a member function, something like lib.editSongInLibrary();
      lib.editSongIndex();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}
/*
runMusicManager()
created 3/22/2023, modified 2/22/2023
Description: initializes the song library and calls the functions used to let the user select 
*/
void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}

