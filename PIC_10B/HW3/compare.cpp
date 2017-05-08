#include<string>
#include<iostream>
#include<fstream>
#include"file.h"

/* 
 *
 * Homework # 1
 *
 * Author: Daniel Ragsdale
 *
 * Email: danielr@ucla.edu
 *
 * Course: PIC 10B Lecture 1 Spring 2017
 *
 * Collaborators: 
 *
 *
 *
 * Honesty Pledge: 
 *
 * I, Daniel Ragsdale, pledge that this is my independent work and abide by the guidelines of honesty 
 *
 * outlined in the syllabus. 
 *
 *
 *
 * User inputs: 
 *
 * Filename 1, Filename 2
 *
 * Output:
 *
 * Text file containing information about File 1 and File 2
 *
 * Character count includes whitespace, e.g. spaces, \n, \r
 *
 * List of known bugs: 
 *
 * The character count for "PhysicaDAbstract.txt" does not match the assignment sheet. I believe mine is correct.
 * I checked the value with a hex editor and it matched my value (217).
 *
 * */ 
int main()
{	
	std::cout << "Enter the name of file 1: ";
	std::string fn1; 
	std::getline(std::cin, fn1);
	File f1(fn1);


	std::cout << "Enter the name of file 2: ";
	std::string fn2;
	std::getline(std::cin, fn2);
	File f2(fn2);
	
	std::ofstream outFile;
	outFile.open("Properties.txt");

	outFile << f1.getDetails();
	outFile << std::endl;
	outFile << f2.getDetails();
	outFile << std::endl;
		
	if(f1 < f2)
	{
		outFile << "The file named \"" << f1.mFilename << "\" has fewer lines than \"" << f2.mFilename << "\".";
	}
	else if(f1 == f2)
	{
		outFile << "The file named \"" << f1.mFilename << "\" has the same number of lines as \"" << f2.mFilename << "\".";
	}
	else
	{
		outFile << "The file named \"" << f1.mFilename << "\" has more lines than \"" << f2.mFilename << "\".";
	}

	outFile.close();
}
