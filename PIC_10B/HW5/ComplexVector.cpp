#include<ostream>

#include"ComplexVector.h"



ComplexVector::ComplexVector(size_t s, ComplexDouble dVal) : mSize(s)
{
	mCapacity = 2*s;
	mData = new ComplexDouble[mCapacity];

	for(size_t i = 0; i < mCapacity; i++)
	{
		mData[i] = dVal;
	}
}

ComplexVector::ComplexVector(const ComplexVector &obj) : ComplexVector(obj.size())
{
	for(int i = 0; i < size(); i++)
	{
		mData[i] = obj[i];
	}
}


size_t ComplexVector::size() const
{
	return mSize;
}
size_t ComplexVector::capacity() const
{
	return mCapacity;
}

void ComplexVector::resize(size_t s)
{
	reserve(s);
	mSize = s;
}

void ComplexVector::reserve(size_t s)
{
	ComplexDouble* tempD = new ComplexDouble[s];

	for(int i = 0; i < s && i < mSize; i++)
	{
		tempD[i] = mData[i];
	}

	for(int i = mSize; i < s; i++)
	{
		tempD[i] = ComplexDouble();
	}

	delete[] mData;
	mData = tempD;
	
	mCapacity = s;
}

ComplexDouble& ComplexVector::operator[](size_t n) const
{
	return mData[n];
}


void ComplexVector::push_back(ComplexDouble o)
{
	if(mSize >= mCapacity)
	{
		if(mSize <= 0)
		{
			reserve(10);
		}
		else
		{
			reserve(mSize * 2);
		}
	}

	mData[mSize] = o;
	mSize++;
}

void ComplexVector::pop_back()
{
	mData[mSize] = ComplexDouble();

	if(mSize > 0)
	{
		mSize--;
	}
}

void ComplexVector::clear()
{
	for(int i = 0; i < mSize; i++)
	{
		mData[i] = ComplexDouble();
	}
}

ComplexVector::~ComplexVector()
{
	delete[] mData;
}

ComplexVector operator+(const ComplexVector& lhs, const ComplexVector& rhs)
{
	ComplexVector v(lhs.size());

	for(int i = 0; i < lhs.size(); i++)
	{
		v[i] = lhs[i] + rhs[i];
	}

	return v;
}

ComplexVector operator-(const ComplexVector& lhs, const ComplexVector& rhs)
{
	ComplexVector v(lhs.size());

	for(int i = 0; i < lhs.size(); i++)
	{
		v[i] = lhs[i] - rhs[i];
	}

	return v;
}

ComplexVector operator*(const ComplexVector& lhs, const ComplexVector& rhs)
{
	ComplexVector v(lhs.size());

	for(int i = 0; i < lhs.size(); i++)
	{
		v[i] = lhs[i] * rhs[i];
	}

	return v;
}

ComplexVector operator/(const ComplexVector& lhs, const ComplexVector& rhs)
{
	ComplexVector v(lhs.size());

	for(int i = 0; i < lhs.size(); i++)
	{
		v[i] = lhs[i] / rhs[i];
	}

	return v;
}

ComplexVector& operator+=(ComplexVector& lhs, const ComplexVector& rhs)
{
	for(int i = 0; i < lhs.size(); i++)
	{
		lhs[i] /= rhs[i];
	}

	return lhs;
}

ComplexVector& operator-=(ComplexVector& lhs, const ComplexVector& rhs)
{
	for(int i = 0; i < lhs.size(); i++)
	{
		lhs[i] /= rhs[i];
	}

	return lhs;
}

ComplexVector& operator*=(ComplexVector& lhs, const ComplexVector& rhs)
{
	for(int i = 0; i < lhs.size(); i++)
	{
		lhs[i] /= rhs[i];
	}

	return lhs;
}

ComplexVector& operator/=(ComplexVector& lhs, const ComplexVector& rhs)
{
	for(int i = 0; i < lhs.size(); i++)
	{
		lhs[i] /= rhs[i];
	}

	return lhs;
}

std::ostream& operator<<(std::ostream& os, const ComplexVector& rhs)
{
	os << "{";
	for(int i = 0; i < rhs.size(); i++)
	{
		os << rhs[i] << ", ";
	}
	os << "}";

	return os;
}














