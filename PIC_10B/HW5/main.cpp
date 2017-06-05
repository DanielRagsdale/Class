#include<iostream>
#include<fstream>

#include"ComplexDouble.h"
#include"ComplexVector.h"

/*
*
* Homework # 5
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
* None
*
* Output:
*
* v1, v2, v1+v2, v1-v2, v1*v2, v1/v2, TextFile containing the sequence
*
* List of known bugs:
*
* None.
*
* Some behaviors left as undefined if they weren't specified in the spec.
*
**/

/**
* Recursive function to create the complex number sequence up to element n
*
* @param n the position of the largest sequence point to be created
* @return a ComplexVector containing the sequence
**/
ComplexVector createSequence(size_t n);

int main()
{
	ComplexVector v1;

	v1.push_back(ComplexDouble(2, 4));
	v1.push_back(ComplexDouble(3, 5));
	v1.push_back(ComplexDouble(-1, -3));
	v1.push_back(ComplexDouble(8, 10));

	ComplexVector v2;
	v2.push_back(ComplexDouble(-10, 3.5));
	v2.push_back(ComplexDouble(4, 7.3));
	v2.push_back(ComplexDouble(2, -8));
	v2.push_back(ComplexDouble(10, -142));
	
	std::cout << "     v1: " << v1 << std::endl;	
	std::cout << "     v2: " << v2 << std::endl;	
	std::cout << "v1 + v2: " << v1 + v2 << std::endl;	
	std::cout << "v1 - v2: " << v1 - v2 << std::endl;	
	std::cout << "v1 * v2: " << v1 * v2 << std::endl;	
	std::cout << "v1 / v2: " << v1 / v2 << std::endl;	

	//Sequence code
	
	std::ofstream sequence;
	sequence.open("ComplexSequence.txt");
	
	if(sequence)
	{
		std::cout << "Writing ComplexSequence.txt to file" << std::endl;
		sequence << createSequence(5);
		sequence.close();
	}
	else
	{
		std::cout << "ComplexSequence.txt failed to open" << std::endl;
	}
}

ComplexVector createSequence(size_t n)
{
	if(n == 0)
	{
		return ComplexVector(1, ComplexDouble(1,1));	
	}
	
	ComplexVector v = createSequence(n - 1);

	ComplexDouble ct = n * ComplexDouble(2, 3);
	ComplexDouble cb = ComplexDouble(7, 5 * n * n);
	
	v.push_back((ct/cb) * v[n-1]);

	return v;
}
