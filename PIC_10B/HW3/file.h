#ifndef __file_h__
#define __file_h__

#include<string>
#include<iostream>

int countChars(const std::string& str);
int countWords(const std::string& str);

class File
{
private:
	std::string mFilename;
	int mCharCount;
	int mWordCount;

public:
	File(const std::string& filename);	

	bool operator>(const File& rhs);
	bool operator<(const File& rhs);
	bool operator==(const File& rhs);

	std::ostream& operator<<(std::ostream& os);
};

#endif
