/*
Name: Cody Kesselring
Class: CPSC 122, Spring 2023
Date: March 27, 2023
Programming Assignment: PA5                                                                      
Description: this header initializes the Song class which stores the private variables title, artist, genre, and rating of a spicific song, the functions get, set, and display attributes of Song
*/
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
	public:
		Song();
		Song(string, string, string, int);
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);

		void displaySong();
		string getStringAttributeValue(string);
};

#endif
