#ifndef __COMPLEXVECTOR_H__
#define __COMPLEXVECTOR_H__

#include"ComplexDouble.h"

/**
 * Class reprsenting a vector of ComplexDoubles.
 * Should have the most important features of an actual vector.
 *
 * Realistically the best thing to do would have been to create a simple
 * wrapper class for Vector<ComplexDouble> but for pedagogical reasons
 * I decided too code it entirely from scratch
 */
class ComplexVector
{
	private:
		size_t mCapacity;
		size_t mSize;
		ComplexDouble* mData;

	public:
		ComplexVector() : ComplexVector(0) {};
		ComplexVector(size_t size) : ComplexVector(size, ComplexDouble()) {};
		ComplexVector(size_t size, ComplexDouble dVal);
		ComplexVector(const ComplexVector &obj);

		size_t size() const;
		size_t capacity() const;
		void resize(size_t s);
		void reserve(size_t s);

		ComplexDouble& operator[](size_t n) const;

		void push_back(ComplexDouble o);
		void pop_back();
		void clear();

		~ComplexVector();
};

/**
 * Operations are defined component wise.
 *
 * The spec isn't clear on what should happen if the two vectors are different
 * lengths. For simplicity, I opted to simply leave this behavior as undefined.
 */
ComplexVector operator+(const ComplexVector& lhs, const ComplexVector& rhs);
ComplexVector operator-(const ComplexVector& lhs, const ComplexVector& rhs);
ComplexVector operator*(const ComplexVector& lhs, const ComplexVector& rhs);
ComplexVector operator/(const ComplexVector& lhs, const ComplexVector& rhs);

ComplexVector& operator+=(ComplexVector& lhs, const ComplexVector& rhs);
ComplexVector& operator-=(ComplexVector& lhs, const ComplexVector& rhs);
ComplexVector& operator*=(ComplexVector& lhs, const ComplexVector& rhs);
ComplexVector& operator/=(ComplexVector& lhs, const ComplexVector& rhs);

std::ostream& operator<<(std::ostream& os, const ComplexVector& rhs);

#endif
