#include "PA5.h"
/*
displayMenu()
created 3/22/2023, modified 2/22/2023
Description: displays the menu options that the user can choose from
*/
void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Display library" << endl;
	cout << "2) Load library" << endl;
	cout << "3) Store library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Add song to library" << endl;
	cout << "7) Remove song from library" << endl;
	cout << "8) Edit song in library" << endl;
	cout << "9) Quit" << endl;
}
/*
getValidChoice()
created 3/22/2023, modified 2/22/2023
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
displayMenu()
created 3/22/2023, modified 2/22/2023
Description: calls the function based on the menu option the user selectes
*/
void executeUserChoice(int choice, SongLibrary& lib) {
	switch (choice) {
		case 1:
			lib.displayLibrary();
			break;
		case 2:
			// TODO: call a helper member function, something like lib.loadLibrary();
      lib.loadSongFile();
			break;
		case 3: 
			// TODO: call a helper member function, something like lib.saveLibrary();
      lib.saveFileName();
			break;
		case 4:
			// TODO: call a helper member function, something like lib.sortLibrary();
      lib.sortAttribute();
			break;
		case 5:
			// TODO: call a helper member function, something like lib.searchLibrary();
      lib.defineAttribute();
			break;
		case 6:
		 	// TODO: call a helper member function, something like lib.addSongToLibrary();
      lib.addSong();
		 	break;
		case 7:
			// TODO: call a helper member function, something like lib.removeSongFromLibrary();
      lib.removeSongIndex();
			break;
		case 8:
			// TODO: call a helper member function, something like lib.editSongInLibrary();
      lib.editSongAttribute();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}
/*
displayMenu()
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
	cout << "Thanks for using the CPSC 122 Music Manager!!" << endl;
}
