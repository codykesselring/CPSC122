#include "SongLibrary.h"

/*
name: SongLibrary::SongLibrary()
description: Constructor for the SongLibrary class. Initializes an empty list with default sort attribute as title.
input parameters: none
returns: none
*/
SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

/*
name: SongLibrary::SongLibrary(const SongLibrary& other)
description: Copy constructor for the SongLibrary class. Copies all the data from another instance of the class to create a new instance.
input parameters: const SongLibrary& other - reference to another instance of the SongLibrary class to be copied
returns: none
*/
// TODO: finish SongLibrary copy constructor
SongLibrary::SongLibrary(const SongLibrary& other) {
	head = NULL; // TODO: fix this
  sortAttribute = other.getSortAttribute();
  Song *currSong = other.getHead();
  while(currSong != NULL){
    Song* newSong = new Song(*currSong);
    performInsertSongInOrder(newSong);
    currSong = currSong->getNext();
  }
}

/*
name: SongLibrary::~SongLibrary()
description: Destructor for the SongLibrary class. Deletes all the Song objects in the linked list.
input parameters: none
returns: none
*/
// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {
  if(head == NULL) {
      return;
  }
  Song * cur = head;
  Song * prev = NULL;
  while(cur != NULL) {
      prev = cur;
      cur = cur->getNext();
      delete prev;
  }
}

/*
name: Song * SongLibrary::getHead() const
description: Returns a pointer to the first Song object in the linked list.
input parameters: none
returns: pointer to a Song object
*/
Song * SongLibrary::getHead() const {
	return head;
}

// TODO: finish this function
/*
name: void SongLibrary::setHead(Song * newHead)
description: Sets the head pointer of the linked list to a new Song object.
input parameters: Song * newHead - pointer to a new Song object to be set as the head
returns: none
*/
void SongLibrary::setHead(Song * newHead) {
  if(head!=NULL){
    Song *currSong = head;
    while(currSong!=NULL){
      Song *nextSong = currSong->getNext();
      delete currSong;
      currSong = nextSong;
    }
  }
  head = newHead;
}

/*
name: string SongLibrary::getSortAttribute() const
description: Returns the current sort attribute of the SongLibrary instance.
input parameters: none
returns: string - the current sort attribute
*/
string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

/*
name: void SongLibrary::setSortAttribute(string newSortAttribute)
description: Sets the sort attribute of the SongLibrary instance to a new value.
input parameters: string newSortAttribute - the new sort attribute to be set
returns: none
*/
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

/*
name: void SongLibrary::loadSongFile()
description: Prompts the user for a file name and loads data from that file into the SongLibrary instance.
input parameters: none
returns: none
*/
// TODO: finish this function
void SongLibrary::loadSongFile(){
  string file;
  cout << "Enter input file name" << endl;
  getline(cin, file);
  performLoad(file);
}
/*
name: void SongLibrary::performLoad(string filename)
description: Loads data from a file into the SongLibrary instance.
input parameters: string filename - the name of the file to be loaded
returns: none
*/
void SongLibrary::performLoad(string filename) {
	string titleParam;
	string artistParam;
	string genreParam;
	string ratingParam;
  string newline;
	int rating = 0;
	ifstream inFile;

  Song * currSong = head;
	Song * prevSong = NULL;
  while (currSong != NULL) {
		prevSong = currSong;
		currSong = currSong->getNext();
		prevSong->setNext(NULL);
		delete prevSong;
	}
	head = NULL;
  
  inFile.open(filename);
  if (!inFile.good()) {
		cout << "ERROR: Cannot open file of path: " << filename << endl;
		return;
	}
  while(!inFile.eof()){
    getline(inFile, titleParam);
    titleParam = convertToLowercase(titleParam);
    getline(inFile, artistParam);
    artistParam = convertToLowercase(artistParam);
    getline(inFile, genreParam);
    genreParam = convertToLowercase(genreParam);
    getline(inFile, ratingParam);
    rating = stoi(ratingParam);
    if (inFile.peek() == '\n') { // check if the next character is a newline
      getline(inFile, newline);
      if (inFile.peek() == '\n') { // check if there are two consecutive newlines
          getline(inFile, newline);
      }
    }
    if (titleParam == "" || artistParam == "" || genreParam == "" || ratingParam == "") {
			break;
		}
    Song * userSong = new Song(titleParam, artistParam, genreParam, rating);
    performInsertSongInOrder(userSong);
  }
  inFile.close();
}

// TODO: finish this function
/*
name: saveFileName
description: Prompts the user to enter a file name and saves the song library to a file with that name.
input parameters: None
returns: None
*/
void SongLibrary::saveFileName(){
  string file;
  cout << "Enter output file name" << endl;
  getline(cin, file);
  performSave(file);
}
/*
name: performSave
description: Saves the song library to a file with the given filename. Outputs an error message if the file cannot be opened.
input parameters: string filename - the name of the file to save the song library to
returns: None
*/
void SongLibrary::performSave(string filename) {
	string titleParam;
	string artistParam;
	string genreParam;
	string ratingParam;
  string newline = "\n";
	ofstream outFile;

  outFile.open(filename);
  if (!outFile.good()) {
		cout << "ERROR: Cannot open file of path: '" << filename << "' " << endl;
		return;
	}
  Song * currSong = head;
  while(currSong!=NULL){
    outFile << currSong->getTitle();
    outFile << newline;
    outFile << currSong->getArtist();
    outFile << newline;
    outFile << currSong->getGenre();
    outFile << newline;
    outFile << currSong->getRating();
    outFile << newline << newline;
    currSong = currSong->getNext();
  }
  outFile.close();
}

// TODO: finish this function
/*
name: sortAttributeFunc
description: Prompts the user to enter an attribute to sort the song library by, and sorts the song library by that attribute.
input parameters: None
returns: None
*/
void SongLibrary::sortAttributeFunc(){
  string sortAttributeParam;
  cout << "Enter sort attribute: ";
  getline(cin, sortAttributeParam);
  setSortAttribute(sortAttributeParam);
  performSort();
}
/*
name: performSort
description: Sorts the song library by the currently set sort attribute. Clears the current song list to prevent memory leaks.
input parameters: None
returns: None
*/
void SongLibrary::performSort() {
  // first we must clear the list to prevent memory leaks
  Song * currSong = head;
	Song * prevSong = NULL;
	SongLibrary newLibrary(*this);

	while (currSong != NULL) {
		prevSong = currSong;
		currSong = currSong->getNext();
		prevSong->setNext(NULL);
		delete prevSong;
	}
	
	head = NULL;
	currSong = newLibrary.getHead();
	while (currSong != NULL) {
		Song * newSong = new Song(*currSong);
		performInsertSongInOrder(newSong);
		currSong = currSong->getNext();
	}
}

// TODO: finish this function
/*
name: searchAttribute
description: Prompts the user to enter an attribute and a value to search for in the song library. Performs the search and stores the found song.
input parameters: None
returns: None
*/
void SongLibrary::searchAttribute(){
  string attribute, attributeValue;
  int index = 0;
	bool found = false;
  Song * foundSong = new Song;
  
  cout << "Search by what attribute (Title, genre, etc...): ";
  getline(cin, attribute);
  attribute = convertToLowercase(attribute);
  cout << "What is the value of the attribute (Title = the twist): ";
  getline(cin, attributeValue);
  attributeValue = convertToLowercase(attributeValue);
  setSortAttribute(attributeValue);
  foundSong = performSearch(attribute, attributeValue, &found, &index);
  foundSong->displaySong();
}

/*
name: performSearch
description: Searches the song library for a song with the given attribute and value. Sets the "found" flag to true if the song is found, and sets the "index" parameter to the index of the song in the song library.
input parameters: string searchAttribute - the attribute to search for (e.g. title, artist, genre)
string searchAttributeValue - the value of the attribute to search for
bool * found - pointer to a bool flag indicating whether the song was found or not
int * index - pointer to an integer where the index of the song will be stored
returns: Song * - pointer to the found song (or NULL if the song is not found)
*/
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	Song * currSong = head;
	int currIndex = 0;
	*found = false;
	while (currSong != NULL) {
		if (currSong->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
			*found = true;
			*index = currIndex;
			return currSong;
		}
		currSong = currSong->getNext();
		currIndex++;
	}
	return NULL; // TODO: fix this
}

// TODO: finish this function
/*
name: addSong
description: Prompts the user to enter information for a new song, creates a Song object, and adds the song to the song library.
input parameters: None
returns: None
*/
void SongLibrary::addSong(){
  Song userSong;
  string titleParam;
	string artistParam;
	string genreParam;
	string ratingParam;
	int rating = 0;

  cout << "Input title: ";
	getline(cin, titleParam);

	cout << "Input artist: ";
	getline(cin, artistParam);

	cout << "Input genre: ";
	getline(cin, genreParam);

	cout << "Input rating: ";
	getline(cin, ratingParam);
	rating = stoi(ratingParam);

  userSong = Song(titleParam, artistParam, genreParam, rating);
  performInsertSongInOrder(&userSong);
}

/*
name: performInsertSongInOrder
description: Inserts the given song into the song library in order, based on the current sort attribute.
input parameters: Song * songToInsert - pointer to the song to insert
returns: None
*/
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	if(head == NULL){
    head = songToInsert;
  }
  else{
    Song * currSong = head;
    Song * prevSong = NULL;
    while(currSong != NULL && (currSong->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute))){
      prevSong = currSong;
      currSong = currSong->getNext();
    }
    if(prevSong == NULL){
      songToInsert->setNext(head);
      head = songToInsert;
    }
    else{
      songToInsert->setNext(currSong);
      prevSong->setNext(songToInsert);
    }
  }
}


// TODO: finish this function
/*
name: removeUserSong
description: Prompts the user to enter an attribute and a value to search for in the song library. If the song is found, removes it from the song library.
input parameters: None
returns: None
*/
void SongLibrary::removeUserSong(){
  string attribute, attributeValue;
  int index = 0;
	bool found = false;
  Song * foundSong = NULL;
  
  cout << "Search by what attribute (Title, genre, etc...): ";
  getline(cin, attribute);
  attribute = convertToLowercase(attribute);
  cout << "What is the value of the attribute (Title = the twist): ";
  getline(cin, attributeValue);
  attributeValue = convertToLowercase(attributeValue);
  foundSong = performSearch(attribute, attributeValue, &found, &index);
  cout << "search secured!" << endl;
  if(found == true){
    performRemoveSong(foundSong);
    cout << "Song removed at index " << index << endl;
  }
  
}
/*
name: performRemoveSong
description: Removes the given song from the song library.
input parameters: Song * songToRemove - pointer to the song to remove
returns: None
*/
void SongLibrary::performRemoveSong(Song * songToRemove) {
	if(head != NULL){
    Song * currSong = head;
    Song * prevSong = NULL;
    if(currSong == songToRemove){
      head=currSong->getNext();
      delete currSong;
    }
    else{
      while(currSong!=NULL && (currSong!=songToRemove)){
        prevSong = currSong;
        currSong = currSong->getNext();  
      }
      if(currSong!=NULL){
        prevSong->setNext(currSong->getNext());
        delete currSong;
      }
    }
  }
}

// TODO: finish this function 
/*
name: editSongIndex
description: Allows the user to edit a song in the library by specifying the song's index, the attribute to change, and the new value for that attribute.
input parameters: None
returns: None
*/
void SongLibrary::editSongIndex(){
  string indexString, attribute, attributeValue;
  int index;
  Song * currSong = head;
  cout << "Index of song to edit: ";
  getline(cin, indexString);
  index = stoi(indexString);
  cout << "What attribute (title, genre, etc...): ";
  getline(cin, attribute);
  cout << "What would you like to change it to: ";
  getline(cin, attributeValue);
  attribute = convertToLowercase(attribute);
  attributeValue = convertToLowercase(attributeValue);
  for(int i=0; i<index; i++){
    currSong = currSong->getNext();
  }
  performEditSong(currSong, attribute, attributeValue);
}

/*
name: performEditSong
description: Performs the actual edit operation on a Song object by changing the value of one of its attributes.
input parameters:
    songToEdit: a pointer to the Song object that should be edited
    attribute: a string specifying which attribute of the song should be changed
    newAttributeValue: a string containing the new value for the specified attribute
returns: None
*/
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
  int rating;
  if(attribute == "title"){
    songToEdit->setTitle(newAttributeValue);
  }
  else if(attribute == "artist"){
    songToEdit->setArtist(newAttributeValue);
  }
  else if(attribute == "genre"){
    songToEdit->setGenre(newAttributeValue);
  }
  else if(attribute == "rating"){
    rating = stoi(newAttributeValue);
    if(rating>5){
      rating = 5;
    }else if(rating < 1){
      rating = 1;
    }
    songToEdit->setRating(rating);  
  }
}
/*
name: displayLibrary
description: Displays all of the songs currently in the library, along with their respective attributes.
input parameters: None
returns: None
*/
void SongLibrary::displayLibrary(){
  if(head == NULL){
    cout << "Song library empty." << endl;
  } 
  Song * currSong = head;
	int count = 0;
  cout << "Song Library:" << endl;
	while (currSong != NULL) {
		currSong->displaySong();
		currSong = currSong->getNext();
		count++;
	}
	cout << endl;
}