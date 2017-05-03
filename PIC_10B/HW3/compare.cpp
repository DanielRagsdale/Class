#include<string>
#include"file.h"






int main()
{	
	std::cout << "Please enter first filenames : \n";
	std::string fn1; 
	std::getline(std::cin, fn1);

	std::cout << "Please enter second filenames : \n";
	std::string fn2;
	std::getline(std::cin, fn2);
	

	File f(fn1);
}
