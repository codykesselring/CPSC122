#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute; // NEW: keep track of what attribute the library is currently ordered by
	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); // NEW: copy constructor
		~SongLibrary();
		Song * getHead() const; // UPDATED: name
		void setHead(Song *); // UPDATED: name
		string getSortAttribute() const; // NEW: getter for sortAttribute
		void setSortAttribute(string); // NEW: setter for sortAttribute
		
		void performLoad(string);
		void performSave(string);
		void performSort(); // UPDATED: no parameter for sort attribute, using Song's sortAttribute member variable
		Song * performSearch(string, string, bool *, int *); // UPDATED: parameter list and return type
		void performInsertSongInOrder(Song *); // NEW: replaces addSong()
		void performRemoveSong(Song *); // UPDATED: parameter list
		void performEditSong(Song *, string, string); // UPDATED: parameter list
    void sortAttributeFunc();
    void loadSongFile();
    void saveFileName();
    void addSong();
    void searchAttribute();
    void removeUserSong();
    void editSongIndex();
    void displayLibrary();
};

#endif
