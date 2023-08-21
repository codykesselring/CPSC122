#include "Song.h"

// TODO: finish this function
/*
Function: convertToLowercase(string s)
Description: Takes a string s and converts all its characters to lowercase
Input Parameters: A string s
Returns: The modified string with all characters in lowercase
*/
string convertToLowercase(string s) {
  for (int i=0; i < s.size(); i++){
    s[i] = tolower(s[i]);
  }
	return s;
}

// TODO: finish Song default value constructor
/*
Function: Song::Song()
Description: Default constructor for the Song class that initializes the object with default values
Input Parameters: None
Returns: None
*/
Song::Song() {
  title = "";
  artist = "";
  genre = "";
  rating = 1;
	next = NULL;
}

// TODO: finish Song explicit value constructor
/*
Function: Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam)
Description: Constructor for the Song class that sets the object's fields to the values passed in the input parameters
Input Parameters: Four parameters: titleParam (string), artistParam (string), genreParam (string), and ratingParam (int)
Returns: None
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
  setTitle(titleParam);
	setArtist(artistParam);
	setGenre(genreParam);
	setRating(ratingParam);
	next = NULL;
}

// TODO: finish Song copy constructor
/*
Function: Song::Song(const Song& other)
Description: Copy constructor for the Song class that creates a new Song object with the same fields as the input Song object
Input Parameters: A constant reference to another Song object
Returns: None
*/
Song::Song(const Song& other) {
  title = other.title;
  artist = other.artist;
  genre = other.genre;
  rating = other.rating;
	next = NULL;
}

/*
Function: Song::getTitle()
Description: Getter method for the Song object's title field
Input Parameters: None
Returns: The title of the Song object
*/
string Song::getTitle() {
	return title;
}

/*
Function: Song::setTitle(string newTitle)
Description: Setter method for the Song object's title field
Input Parameters: A new title (string)
Returns: None
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

/*
Function: Song::getArtist()
Description: Getter method for the Song object's artist field
Input Parameters: None
Returns: The artist of the Song object
*/
string Song::getArtist() {
	return artist;
}

/*
Function: Song::setArtist(string newArtist)
Description: Setter method for the Song object's artist field
Input Parameters: A new artist (string)
Returns: None
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

/*
Function: Song::getGenre()
Description: Getter method for the Song object's genre field
Input Parameters: None
Returns: The genre of the Song object
*/
string Song::getGenre() {
	return genre;
}

/*
Function: Song::setGenre(string newGenre)
Description: Setter method for the Song object's genre
Input Parameters: A new genre
Returns: None
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

/*
Function: int Song::getRating()
Description: Getter method for the Song object's rating field
Input Parameters: None
Returns: The rating of the Song object
*/
int Song::getRating() {
	return rating;
}
/*
Function: Song::setRating(string newRating)
Description: Setter method for the Song object's artist field
Input Parameters: A new rating (int)
Returns: None
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
Function: Song * Song::getNext()
Description: Getter method for the Song object's next field (pointer to the next Song object in a linked list)
Input Parameters: None
Returns: The pointer to the next Song object in the linked list
*/
Song * Song::getNext() {
	return next;
}

/*
Function: Song::setNext(Song * newNext)
Description: Setter method for the Song object's next song
Input Parameters: A pointer to the next Song object in a linked list
Returns: None
*/
void Song::setNext(Song * newNext) {
	next = newNext;
}

// TODO: finish this function
/*
Function: string Song::getStringAttributeValue(string attribute)
Description: sets the sort attribute to one of the elements provided by user
Input Parameters: A string representing the name of a Song object attribute (title, artist, genre, or rating)
Returns: The value of the corresponding attribute in the current Song object
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

// TODO: finish this function
/*
Function: Song::displaySong()
Description: displays the elements of a song
Input Parameters: None
Returns: None
*/
void Song::displaySong() {
  cout << "Title: " << title << "\nArtist: " << artist << "\nGenre: " << genre << "\nRating: " << rating << endl << endl;
}

