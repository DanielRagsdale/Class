#ifndef __ComplexDouble_H__
#define __ComplexDouble_H__

#include<ostream>

class ComplexDouble
{
	public:
		double mRealPart;
		double mImaginaryPart;
		
		ComplexDouble() : mRealPart(0), mImaginaryPart(0) {}
		ComplexDouble(double rp, double ip) : mRealPart(rp), mImaginaryPart(ip) {}
		ComplexDouble(double rp) : mRealPart(rp), mImaginaryPart(0) {}

		ComplexDouble conjugate() const;
};

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
