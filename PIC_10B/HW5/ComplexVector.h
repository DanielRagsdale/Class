#ifndef __COMPLEXVECTOR_H__
#define __COMPLEXVECTOR_H__

#include"ComplexDouble.h"

/**
 * Class reprsenting a vector of ComplexDoubles.
 * Should have the most important features of an actual vector.
 *
 * Realistically the best thing to do would have been to create a simple
 * wrapper class for Vector<ComplexDouble> but for pedagogical reasons
 * I decided to code it entirely from scratch
 */
class ComplexVector
{
	private:
		size_t mCapacity;
		size_t mSize;
		ComplexDouble* mData;

	public:
		/**
		* Create an empty ComplexVector
		**/
		ComplexVector() : ComplexVector(0) {};

		/**
		* Create a complex vector of a given length
		*
		* @param size the length of the vector to be created
		*/
		ComplexVector(size_t size) : ComplexVector(size, ComplexDouble()) {};

		/**
		* Create a complex vector of a given length.
		* Fill the created vector with values dVal
		*
		* @param size the length of the vector to be created
		* @param dVal the default value of the vector
		*/
		ComplexVector(size_t size, ComplexDouble dVal);
		/**
		* Copy constructor for ComplexVector
		*
		* @param obj the ComplexVector to be copied from
		*/
		ComplexVector(const ComplexVector &obj);

		/**
		* The length of the vector
		*
		* @return the length of the vector
		*/
		size_t size() const;

		/**
		* The amount of space reserved for this vector.
		* How many elements it can hold before it will need to reallocate.
		*
		* @return the capacity in number of ComplexDoubles
		**/
		size_t capacity() const;

		/**
		* Change the size of the backing array.
		* Affects both the size and the capacity of this vector
		*
		* @param s the new size of the vector
		**/
		void resize(size_t s);

		/**
		* Change the size of the backing array.
		* Only affects the size of this vector if s is less than the size
		*
		* @param the new capacity of the vector
		*/
		void reserve(size_t s);

		/**
		* Get the nth element of this vector
		*
		* @param n the index in this vector
		* @return a reference to the element
		**/
		ComplexDouble& operator[](size_t n) const;

		/**
		* Add object o to the end of this vector.
		* Will allocate more space if it runs out.
		*
		* @param o the ComplexDouble to be added to the end of this vector
		**/
		void push_back(ComplexDouble o);

		/**
		* Remove an object from the end of this vector.
		* Will do nothing if the vector is already empty.
		**/
		void pop_back();

		/**
		* Replace every element in this vector with the 0 ComplexDouble
		*/
		void clear();

		/**
		* Destructor for ComplexVector
		**/
		~ComplexVector();
};

/**
 * Operations are defined component wise, e.g. v1 + v2 = {v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2], ...}
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
