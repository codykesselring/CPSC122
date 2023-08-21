#include "SongLibrary.h"
/*
SongLibrary::SongLibrary()
created 3/22/2023, modified 2/22/2023
Description: sets the default values of class SongLibrary
*/
SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

/*
SongLibrary::~SongLibrary()
created 3/22/2023, modified 2/22/2023
Description: This is the destructor of the SongLibrary class. It frees up the dynamically allocated memory that was used to store the songs.
*/
SongLibrary::~SongLibrary() {
	if(songs != NULL){
    delete [] songs;
    songs = NULL;
  }
  numSongs = 0;
}

/*
getNumSongs()
created 3/22/2023, modified 2/22/2023
Description: retrieves the private variable "numSongs" from class Song
*/
int SongLibrary::getNumSongs() {
	return numSongs;
}

/*
setNumSongs()
created 3/22/2023, modified 2/22/2023
Description: sets the private variable "numSongs" from class Song with the inputted parameter
*/
void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

/*
getSongsArray()
created 3/22/2023, modified 2/22/2023
Description: returns a pointer to the songs array that is used to store the songs in the library.
*/
Song * SongLibrary::getSongsArray() {
	return songs;
}

/*
setSongsArray()
created 3/22/2023, modified 2/22/2023
Description: sets the songs array to a new array of songs that is passed as a parameter
*/
void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

/*
displayLibrary()
created 3/22/2023, modified 3/22/23
Description: This function displays the titles, artists, genres and ratings of all the songs that are currently stored in the library.
Returns: N/A
Pre: The class' variables were initialized and the songs array was allocated dynamically.
Post: The songs are displayed
*/
void SongLibrary::displayLibrary() {
  string newline = "\n";
  for(int i = 0; i<numSongs; i++){
    cout << songs[i].getTitle();
    cout << newline;
    cout << songs[i].getArtist();
    cout << newline;
    cout << songs[i].getGenre();
    cout << newline;
    cout << songs[i].getRating();
    cout << newline << newline;
  }
}

/*
loadSongFile()
created 3/22/2023, modified 3/22/23
Description: asks the user for the name of the file they wanted songs loaded from then passes the string into performLoad()
*/
void SongLibrary::loadSongFile(){
  string file;
  cout << "Enter input file name" << endl;
  getline(cin, file);
  performLoad(file);
}

/*
Function: performLoad()
Date Created: 3/22/22
Date Last Modified: 3/27/22
Description: This function loads the songs from a file specified by the user, and adds them to the SongLibrary.
Input parameters: The filename of the file containing the songs.
Returns: NA
Pre: The file specified by the filename must exist and contain songs in a specific format.
Post: The songs from the file are added to the SongLibrary.
*/
void SongLibrary::performLoad(string filename) {
  string titleParam;
	string artistParam;
	string genreParam;
	string ratingParam;
  string newline;
	int rating = 0;
	ifstream inFile;
  numSongs = 0;
  songs = NULL;
  
  inFile.open(filename);
  if (!inFile.good()) {
		cout << "ERROR: Cannot open file of path: '" << filename << "' " << endl;
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

    Song userSong(titleParam, artistParam, genreParam, rating);
    performAddSong(userSong);
  }
  inFile.close();
}

/*
saveFileName()
created 3/22/2023, modified 3/22/23
Description: asks the user for the name of the file they wanted songs loaded into then passes the string into performSave()
*/
void SongLibrary::saveFileName(){
  string file;
  cout << "Enter output file name" << endl;
  getline(cin, file);
  performSave(file);
}

/*
Function: performSave()
Date Created: 3/20/22
Date Last Modified: 3/24/22
Description: This function saves the songs in the SongLibrary to a file specified by the user.
Input parameters: The filename of the file to save the songs to
Returns: NA
Pre: The user must have specified a valid filename
Post: The songs in the SongLibrary are saved to the specified file
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
  for(int i = 0; i<numSongs; i++){
    outFile << songs[i].getTitle();
    outFile << newline;
    outFile << songs[i].getArtist();
    outFile << newline;
    outFile << songs[i].getGenre();
    outFile << newline;
    outFile << songs[i].getRating();
    outFile << newline << newline;
  }
  outFile.close();
}

/*
saveFileName()
created 3/24/2023, modified 3/24/23
Description: asks the user for the name of the attribute they want their library sorted by and passes the attribute into performSort()
*/
void SongLibrary::sortAttribute(){
  string attribute;
  cout << "What attribute do you want to sort by (title, genre, etc..): ";
  getline(cin, attribute);
  performSort(attribute);
}

/*
Function: performSort()
Date Created: 3/24/22
Date Last Modified: 3/25/22
Description: This function sorts the songs in the SongLibrary based on a specified attribute (artist, genre, title, rating).
Input parameters: The attribute to sort the songs by.
Returns: NA
Pre: The attribute must be one of the valid sorting attributes
Post: The songs in the SongLibrary are sorted based on the specified attribute
*/
void SongLibrary::performSort(string attribute) {
  if(attribute == "artist"){
    for(int i=0; i<numSongs-1; i++){
      for(int j=i+1; j<numSongs; j++){
        if(songs[i].getArtist()>songs[j].getArtist()){
          Song temp = songs[i];
          songs[i] = songs[j];
          songs[j] = temp;
        }
      }
    }
  }
  else if(attribute == "genre"){
    for(int i=0; i<numSongs-1; i++){
      for(int j=i+1; j<numSongs; j++){
        if(songs[i].getGenre()>songs[j].getGenre()){
          Song temp = songs[i];
          songs[i] = songs[j];
          songs[j] = temp;
        }
      }
    }
  }
  else if(attribute == "title"){
    for(int i=0; i<numSongs-1; i++){
      for(int j=i+1; j<numSongs; j++){
        if(songs[i].getTitle()>songs[j].getTitle()){
          Song temp = songs[i];
          songs[i] = songs[j];
          songs[j] = temp;
        }
      }
    }
  }
  else if(attribute == "rating"){
    for(int i=0; i<numSongs-1; i++){
      for(int j=i+1; j<numSongs; j++){
        if(songs[i].getRating()>songs[j].getRating()){
          Song temp = songs[i];
          songs[i] = songs[j];
          songs[j] = temp;
        }
      }
    }
  }
}

/*
saveFileName()
created 3/24/2023, modified 3/25/23
Description: asks the user to enter the parameters to be passed into the performSearch() function and passes them true and displays if the song was found or not
*/
void SongLibrary::defineAttribute(){
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
  found = performSearch(attribute, attributeValue, foundSong, &index);
  cout << "search secured!" << endl;
  if(found == true){
    cout << "The song with attribute: " << attribute << " with value of \"" << attributeValue << "\" was found at index " << index << endl;
    cout << "Song information: \n";
    songs[index].displaySong();
  }else{
    cout << "The song with attribute: " << attribute << " with value of \"" << attributeValue << "\" was not found." << endl;
  }
}

/*
Function: SongLibrary::performSearch()
Date Created: 3/24/22
Date Last Modified: 3/27/22
Description: This function performs a search on the song library based on the given searchAttribute and searchAttributeValue.
The function searches for a song with a matching attribute and value, and stores the found song and its index.
Input parameters:
- searchAttribute: the attribute to search for
- searchAttributeValue: the value of the attribute to search for
- foundSong: a pointer to a Song object
- index: a pointer to an integer where the index of the found song will be stored
Returns: true if a song with the given attribute and value is found, false otherwise
Pre: The SongLibrary object must have been initialized with songs in it
Post: If a song is found, its details are stored in the Song object pointed to by foundSong and its index is stored in the integer pointed to by index
*/
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
  if(searchAttribute == "title"){
    for(int i = 0; i<numSongs; i++){
      if(songs[i].getTitle() == searchAttributeValue){
        *index = i;
        *foundSong = songs[i];
        return true;
      }
    }
  }
  else if(searchAttribute == "artist"){
    for(int i = 0; i<numSongs; i++){
      if(songs[i].getArtist() == searchAttributeValue){
        *index = i;
        *foundSong = songs[i];
        return true;
      }
    }
  }
  else if(searchAttribute == "genre"){
    for(int i = 0; i<numSongs; i++){
      if(songs[i].getGenre() == searchAttributeValue){
        *index = i;
        *foundSong = songs[i];
        return true;
      }
    }
  }
  else if(searchAttribute == "rating"){
    for(int i = 0; i<numSongs; i++){
      if(to_string(songs[i].getRating()) == searchAttributeValue){
        *index = i;
        *foundSong = songs[i];
        return true;
      }
    }
  }
  *index=-1;
  foundSong = NULL;
	return false;
}

/*
addSong()
created 3/24/2023, modified 3/24/23
Description: asks the user to enter the parameters to be passed into the addSong() function and passes them into the function
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
  performAddSong(userSong);
}

/*
Function: SongLibrary::performAddSong()
Date Created: 3/22/22
Date Last Modified: 3/25/22
Description: This function adds a new song to the song library
Input parameters:
- newSong: a Song object containing the details of the new song to be added
Returns: NA
Pre: The SongLibrary object must have been initialized
Post: A new song is added to the song library
*/
void SongLibrary::performAddSong(Song newSong) {
	if(numSongs == 0){
    songs = new Song[1];
    songs[0] = newSong;
    numSongs = 1;
  }else{
    Song * copySongsArr = new Song[numSongs+1];
    for(int i = 0; i<numSongs; i++){
      copySongsArr[i] = songs[i];
    }
    copySongsArr[numSongs] = newSong;
    numSongs++;
    delete [] songs;
    songs = copySongsArr;
  }
}

/*
removeSongIndex()
created 3/24/2023, modified 3/24/23
Description: asks the user to enter the index of the song they want removed
*/
void SongLibrary::removeSongIndex(){
  int index;
  cout << "Enter the index of the song you want removed: ";
  cin >> index;
  if(numSongs < index){
    cout << "There is no song at index " << index << endl;
    return;
  }
  performRemoveSong(index);
}

/*
Function: SongLibrary::performRemoveSong()
Date Created: 3/23/22
Date Last Modified: 3/27/22
Description: This function removes a song from the song library
Input parameters:
- indexToRemove: the index of the song to be removed
Returns: NA
Pre: The SongLibrary object must have been initialized with songs in it
Post: The song at the given index is removed from the song library
*/
void SongLibrary::performRemoveSong(int indexToRemove) { 
  int count = 0;
  if(songs == NULL){
    cout << "Song library is empty" << endl;
    return;
  }
  else if(numSongs == 1){
    numSongs--;
    delete [] songs;
    songs = NULL;
    return;
  }
	Song * copySongsArr = new Song[numSongs-1];
  for(int i=0; i<numSongs-1; i++){
    if(i == indexToRemove){
      count++;
    }
    copySongsArr[i] = songs[i+count]; 
  }
  numSongs--;
  delete [] songs;
  songs = copySongsArr;
}

/*
removeSongIndex()
created 3/24/2023, modified 3/27/23
Description: asks the user to enter the attribute and attribute value of the song they want to edit and passes it into the performEditSong()
*/
void SongLibrary::editSongAttribute(){
  string indexString, attribute, attributeValue;
  int index;
  cout << "Index of song to edit: ";
  getline(cin, indexString);
  index = stoi(indexString);
  if(index < numSongs-1 || index<0){
    cout << "There is no song at index " << index << endl;
    return;
  }
  cout << "What attribute (title, genre, etc...): ";
  getline(cin, attribute);
  cout << "What would you like to change it to: ";
  getline(cin, attributeValue);
  attribute = convertToLowercase(attribute);
  attributeValue = convertToLowercase(attributeValue);
  
  performEditSong(index, attribute, attributeValue);
}

/*
Function: performEditSong()
Date Created: 3/24/23
Date Last Modified: 3/27/23
Description: This function edits a song's attribute (title, artist, genre, or rating) at the given index. If the rating is edited, the function ensures that it falls within the range of 1-5
Input parameters:
- indexToEdit: The index of the song to edit
- attribute: The attribute of the song to edit (title, artist, genre, or rating)
- newAttributeValue: The new value of the attribute to set
Returns: NA
Pre: The SongLibrary object must be properly initialized with valid song objects.
Post: The specified song attribute at the given index will be updated to the new value, or an error message will be printed if the rating is out of range
*/
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
  int rating; 
  if(attribute == "title"){
    songs[indexToEdit].setTitle(newAttributeValue);
  }
  else if(attribute == "artist"){
    songs[indexToEdit].setArtist(newAttributeValue);
  }
  else if(attribute == "genre"){
    songs[indexToEdit].setGenre(newAttributeValue);
  }
  else if(attribute == "rating"){
    rating = stoi(newAttributeValue);
    if(rating>5){
      rating = 5;
    }else if(rating < 1){
      rating = 1;
    }
    if(rating>5 || rating <1){
      cout << "Rating out of range 1-5" << endl;
      return;
    }
    songs[indexToEdit].setRating(rating);
  }
}