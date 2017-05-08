/**
 * Method descriptions are found in card.h
 */

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include"file.h"



File::File(const std::string& filename)
{
	mFilename = filename;
	mText = "";
	
	std::streampos begin, end;
	std::ifstream fileIn(&mFilename[0]);

	if(fileIn.is_open())
	{

		begin = fileIn.tellg();
		fileIn.seekg (0, std::ios::end);
		end = fileIn.tellg();
		fileIn.seekg (0, std::ios::beg);

		mCharCount += end - begin;

		std::string line;

		while(getline(fileIn, line))
		{
			mText += line;
			mWordCount += countWords(line);
			mLineCount++;
		}
		fileIn.close();
	}
}

std::string File::getDetails()
{
	std::ostringstream ss;
	ss << "Filename: " << mFilename << std::endl;
	ss << "Number of characters: " << mCharCount << std::endl;
	ss << "Number of words: " << mWordCount << std::endl;
	return ss.str();
}

bool operator>(const File& lhs, const File& rhs)
{
	return lhs.mLineCount > rhs.mLineCount;
}

bool operator<(const File& lhs, const File& rhs)
{
	return lhs.mLineCount < rhs.mLineCount;
}

bool operator==(const File& lhs, const File& rhs)
{
	lhs.mLineCount == rhs.mLineCount;
}

std::ostream& operator<<(std::ostream& os, const File& file)
{
	return os << file.mText;
}

int countChars(const std::string& str)
{
	return str.length();
}

int countWords(const std::string& str)
{
	int counter = 0;

	for(int i = 0; i < str.length(); i++)
	{
		if((std::isalpha(str[i]) || std::ispunct(str[i])) && (i == str.length() - 1 || std::isspace(str[i+1])))
		{
			counter++;
		}
	}
	
	return counter;
}







