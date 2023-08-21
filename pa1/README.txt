Program Details
Write a program that converts English-language phrases into Morse code and Morse code back to English-language phrases. The program should also keep track of the number of characters converted from English text to Morse code and vice versa. For this program, you will need to prompt the user to determine the conversion option (-m means convert from English text to Morse code, -t means convert from Morse code to English text) and the source and destination file names. The source filename will be the file from which you read and the destination filename will be the file to which you will write.  For example:

[Your Prompt]:   -m    english.txt    morse.txt

Indicates that the file called english.txt should be opened for reading and that the file morse.txt should be opened for writing. Essentially the file english.txt, which contains the English-language text (with no punctuation or special characters), needs to be converted to Morse Code and outputted to morse.txt.

If you type -t    morse.txt    english.txt at the prompt, then you will need to convert the Morse code contents of morse.txt to English text and output to english.txt. You may assume that the user enters the format of the strings at the prompt correctly, i.e. the number of strings is always three, etc. The only error checking that you will have to perform for the user input is that the files can be successfully opened.

All white spaces in the English text file should be preserved in the Morse code file. Also, all newline characters should be preserved. When you convert from Morse code to English text, I would recommend reading one Morse string at a time. Remember these strings will be separated by white space.
