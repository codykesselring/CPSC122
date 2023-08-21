/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2023
Date: March 27, 2023
Programming Assignment: PA5                                                                      
Description: this header initializes the SongLibrary class which stores a private array along with the total elements inside the array; the functions consist of getters and setters, along with corresponding to the menu optionss in PA5.h 
*/
#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		int numSongs;
		Song * songs;
		
		// TODO: add your additional private member functions here
	public:
		SongLibrary();
		~SongLibrary();
		int getNumSongs();
		void setNumSongs(int);
		Song * getSongsArray();
		void setSongsArray(Song *);

		void displayLibrary();
		void performLoad(string);
		void performSave(string);
		void performSort(string);
		bool performSearch(string, string, Song *, int *);
		void performAddSong(Song);
		void performRemoveSong(int);
		void performEditSong(int, string, string);

		// TODO: add your additional public member functions here
    void addSong();
    void loadSongFile();
    void saveFileName();
    void removeSongIndex();
    void defineAttribute();
    void sortAttribute();
    void editSongAttribute();
};

#endif
