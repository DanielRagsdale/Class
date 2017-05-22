#ifndef __ComplexDouble_H__
#define __ComplexDouble_H__

#include<ostream>

/**
* A class reprsenting a complex number with doubles for elements
**/
class ComplexDouble
{
	public:
		/**
		* The real part of this ComplexDouble
		**/
		double mRealPart;
		
		/**
		* The coefficient of the imaginary term
		**/
		double mImaginaryPart;
		
		/**
		* Create a ComplexDouble with 0 for both the real and imaginary components
		**/
		ComplexDouble() : mRealPart(0), mImaginaryPart(0) {}

		/**
		* Create a ComplexDouble with real part rp and imaginary part 0.
		*
		* @param rp the real part of this number
		**/
		ComplexDouble(double rp) : mRealPart(rp), mImaginaryPart(0) {}
		
		/**
		* Create a ComplexDouble with the specified real and imaginary parts
		*
		* @param rp the real part of this number
		* @param ip the imaginary part of this number
		**/
		ComplexDouble(double rp, double ip) : mRealPart(rp), mImaginaryPart(ip) {}

		/**
		* Create the complex conjugate of this number.
		*
		* @return the complex conjugate of this ComplexDouble
		**/
		ComplexDouble conjugate() const;
};

/**
* Operators are overloaded according to their mathematical definitions.
**/
ComplexDouble operator+(const ComplexDouble& lhs, const ComplexDouble& rhs);
ComplexDouble operator-(const ComplexDouble& lhs, const ComplexDouble& rhs);
ComplexDouble operator*(const ComplexDouble& lhs, const ComplexDouble& rhs);
ComplexDouble operator/(const ComplexDouble& lhs, const ComplexDouble& rhs);

ComplexDouble& operator+=(ComplexDouble& lhs, const ComplexDouble& rhs);
ComplexDouble& operator-=(ComplexDouble& lhs, const ComplexDouble& rhs);
ComplexDouble& operator*=(ComplexDouble& lhs, const ComplexDouble& rhs);
ComplexDouble& operator/=(ComplexDouble& lhs, const ComplexDouble& rhs);

std::ostream& operator<<(std::ostream& os, const ComplexDouble& rhs);

#endif
