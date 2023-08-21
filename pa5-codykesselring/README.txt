For this assignment you will write a program for managing a music library using classes!

Your music manager program has a text-based interface which allows the user to select from a menu of options that operate on a song library, including: 
Display library: The “display” option prints songs and their attributes to the screen. 
Load library: The “load” option reads songs from a library file (file name entered by the user) into program memory. 
Store library: The “store” option writes songs from program memory to a file (file name entered by the user).
Sort library: The “sort” option sorts songs by an attribute. The user can choose to sort by title, artist, genre, or rating.
Search library: The “search” option displays songs based on a search field. A search field may be by title, artist, genre, or rating attributes belonging to a song, or by index in the list. If a search field matches multiple songs, then print the first match to the screen.
Add song: The “add” option collects information for a new song by prompting the user for song attribute values. The song is appended to the end of the library, which may cause the list to become unsorted.
Remove song: The “remove” option removes a record from the list. The user can search for a song to remove in the same manner as the “search” option. If a search field matches multiple songs, then remove the first match.
Edit: The “edit” option allows the user to find a song in the library and edit it. The user can search for a song to edit in the same manner as the “search” option. If a search field matches multiple songs, then edit the first match. The user may modify any of the attributes in the record. For editing the rating of a song, only allow the user to assign a value of 1 – 5 to a song; 1 is the lowest rating and 5 is the highest rating. 
Quit: Lastly, the “quit” option terminates the program.

Your music manager program is built upon a linear data structure implemented as a dynamic array and defined by the following two classes:
Song
SongLibrary
Song Class
A Song is a class type which consists of the following private attributes:
title – a lowercase string
artist – a lowercase string
genre – a lowercase string
rating – an integer in the range [1, 5]
SongLibrary Class
A SongLibrary is a class type which consists of the following private attributes:
songs - a dynamic array of Song objects that is perfectly fit to the number of songs
This means you must resize your array and properly free memory with every add and remove
When we learn about linked lists we will see a much better way to do this!
numSongs - an integer representing the size of the songs array
