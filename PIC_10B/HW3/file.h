#ifndef __file_h__
#define __file_h__

#include<string>
#include<iostream>

/**
 * Class representing the a file read from disk.
 */
class File
{
public:
	/**
	 * The filename of this file
	 */
	std::string mFilename;
	/**
	 * The text of this file
	 */
	std::string mText;
	
	/**
	 * The number of characters of all types in this file
	 */
	int mCharCount;
	/**
	 * The number of words in this file
	 */
	int mWordCount;
	/**
	 * The number of lines in this file
	 */
	int mLineCount;
	
	/**
	 * Open and initialize based upon the file at location given by filename
	 *
	 * @param filename the name of the file to be opened
	 */
	File(const std::string& filename);	
	
	/**
	 * Get a string representing various information about this file.
	 *
	 * @return string representing the details
	 */	
	std::string getDetails();
};

/**
 * Compare the number of lines in lhs and rhs.
 *
 * @param lhs the left hand file in the comparison
 * @param rhs the right hand file in the comparison
 *
 * @return does lhs have more lines than rhs?
 */
bool operator>(const File& lhs, const File& rhs);
/*
 * Compare the number of lines in lhs and rhs
 *
 * @param lhs the left hand file in the comparison
 * @param rhs the right hand file in the comparison
 *
 * @return does rhs have more lines than lhs?
 */
bool operator<(const File& lhs, const File& rhs);

/**
 * Compare the number of lines in lhs and rhs
 * This seems like a bad use of overloading
 *
 * @param lhs the left hand file in the comparison
 * @param rhs the right hand file in the comparison
 *
 * @return does rhs have the same number of lines as lhs?
 */
bool operator==(const File& lhs, const File& rhs);

/**
 * Print the text of this file to the stream
 *
 * @param os the stream to be printed to
 * @param file the file to be printed
 *
 * @return the stream that has been printed to
 */
std::ostream& operator<<(std::ostream& os, const File& file);

/**
 * Count the number of words in a given string
 *
 * @param str the string to have words counted in
 * @return the number of words
 */
int countWords(const std::string& str);
#endif










