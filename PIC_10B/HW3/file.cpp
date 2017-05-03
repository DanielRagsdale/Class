#include<string>
#include<iostream>
#include<fstream>
#include"file.h"

File::File(const std::string& filename)
{
	mFilename = filename;
	
	std::streampos begin, end;
	std::ifstream fileIn(&mFilename[0]);

	std::string line;
	if(fileIn.is_open())
	{
		int wordCount = 0;

		while(getline(fileIn, line))
		{
			std::cout << line << std::endl;
			wordCount += countWords(line);
		}
		
		std::cout << "Word Count: " << wordCount << std::endl;

		fileIn.close();
	}
}

int countChars(const std::string& str)
{
	return str.length();
}

int countWords(const std::string& str)
{
	int counter = 0;

	for(int i = 0; i < str.length() - 1; i++)
	{
		if(std::isalpha(str[i]) && (std::isspace(str[i+1]) || std::ispunct(str[i+1])))
		{
			counter++;
		}
	}

	return counter;
}

