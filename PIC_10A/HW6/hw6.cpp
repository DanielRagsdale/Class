#include "hw6.h"
#include <cmath>
#include <cassert>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923 

int ipow(int base, int exp) 
{
	assert(exp >= 0);

	int counter = 1;
	for(int i = 0; i < exp; i++)
	{
		counter *= base;
	}

	return counter;
}

double my_min(double* arr, int len) 
{
	assert(len >= 0);

	double min = *arr;

	for(double* val = arr; val < arr + len; val++)
	{
		if(*val < min)
		{
			min = *val;
		}
	}

	return min;
}

double angle(double x, double y) 
{
	assert(x != 0 || y != 0);
	
	if (x > 0)
	{
		return fmod(360 + atan(y/x) * 180/PI, 360);
		
		//if(y >= 0) 
		//	return atan(y/x) * 180 / PI;
		//else
		//	return 360 + atan(y/x) * 180 / PI;
	}
	else if(x < 0)
	{
		return 180 + atan(y/x) * 180/PI;

		//if(y >= 0) 
		//	return 180 + atan(y/x) * 180 / PI;
		//else
		//	return 360 + atan(y/x) * 180 / PI;
	}	
	else if(x == 0)
	{
		if(y > 0)
			return 90;
		else
			return 270;
	}
}

char* my_strcpy(char* destination, const char* source) 
{
	unsigned int offset = 0;

	while(true)
	{
		*(destination + offset) = *(source + offset);

		if(*(source + offset) == '\0')
		{
			return destination;
		}

		offset++;
	}	
}

int my_strcmp(const char* str1, const char* str2) 
{
	int i = 0;
	while(true)
	{
		char diff = *(str1 + i) - *(str2 + i);

		if(diff != 0)
		{
			return diff;
		}	
		else if(*(str1 + i) == '\0' || *(str2 + i) == '\0')
		{
			return 0;	
		}

		i++;
	}
}
