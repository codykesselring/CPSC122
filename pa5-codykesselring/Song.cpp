#include "Song.h"

/*
convertToLowercase()
created 3/22/2023, modified 2/22/2023
Description: converts a string to all lower case letters
Returns: lower case striing
Pre: upper case string
Post: lower case string
*/
string convertToLowercase(string s) {
  for (int i=0; i < s.size(); i++){
    s[i] = tolower(s[i]);
  }
	return s;
}

/*
Song::Song()
created 3/22/2023, modified 2/22/2023
Description: sets the default values of class Song
*/
Song::Song() {
  title = "";
  artist = "";
  genre = "";
  rating = 1;
}

// TODO: finish Song explicit value constructor
/*
Song::Song(params)
created 3/22/2023, modified 2/22/2023
Description: sets the private values within the song class to the parameters inputed
Returns: NA
Pre: default song
Post: song with new values
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
  title = titleParam;
  artist = artistParam;
  genre = genreParam;
  rating = ratingParam;
}
/*
getTitle()
created 3/22/2023, modified 2/22/2023
Description: retrieves the private variable "title" from class Song
*/
string Song::getTitle() {
	return title;
}
/*
setTitle()
created 3/22/2023, modified 2/22/2023
Description: sets the private variable "title" from class Song
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}
/*
getArtist()
created 3/22/2023, modified 2/22/2023
Description: retrieves the private variable "arist" from class Song
*/
string Song::getArtist() {
	return artist;
}
/*
setArtist()
created 3/22/2023, modified 2/22/2023
Description: sets the private variable "artist" from class Song
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}
/*
getGenre()
created 3/22/2023, modified 2/22/2023
Description: retrieves the private variable "genre" from class Song
*/
string Song::getGenre() {
	return genre;
}
/*
setGenre()
created 3/22/2023, modified 2/22/2023
Description: sets the private variable "genre" from class Song
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}
/*
getGenre()
created 3/22/2023, modified 2/22/2023
Description: retrieves the private variable "rating" from class Song
*/
int Song::getRating() {
	return rating;
}
/*
getGenre()
created 3/22/2023, modified 2/22/2023
Description: sets the private variable "genre" from class Song making sure it's bound between [1,5]
*/
void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

/*
displaySong()
created 3/22/2023, modified 2/22/2023
Description: displays the contents of a selected song in class Song
*/
void Song::displaySong() {
  cout << "Title: " << title << endl;
  cout << "Artist: " << artist << endl;
  cout << "Genre: " << genre << endl;
  cout << "Rating: " << rating << endl;
}

/*
getStringAttributeValue()
created 3/22/2023, modified 2/22/2023
Description: retrievs the value of a selected attribute (i.e. Title = The Twist)
Returns: contents of selected attribute
*/
string Song::getStringAttributeValue(string attribute) {
  attribute = convertToLowercase(attribute);
	if (attribute == "title") {
		return getTitle();
	} else if (attribute == "artist") {
		return getArtist();
	} else if (attribute == "genre") {
		return getGenre();
	} else if (attribute == "rating") {
		return to_string(getRating());
	}
	return "";
}