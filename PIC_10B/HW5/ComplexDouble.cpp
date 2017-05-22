#include<ostream>

#include"ComplexDouble.h"


ComplexDouble ComplexDouble::conjugate() const
{
	return ComplexDouble(mRealPart, -mImaginaryPart);
}

ComplexDouble operator+(const ComplexDouble& lhs, const ComplexDouble& rhs)
{
	return ComplexDouble(lhs.mRealPart + rhs.mRealPart, lhs.mImaginaryPart + rhs.mImaginaryPart);
}

ComplexDouble operator-(const ComplexDouble& lhs, const ComplexDouble& rhs)
{

	return ComplexDouble(lhs.mRealPart - rhs.mRealPart, lhs.mImaginaryPart - rhs.mImaginaryPart);
}

ComplexDouble operator*(const ComplexDouble& lhs, const ComplexDouble& rhs)
{
	double rp1 = lhs.mRealPart * rhs.mRealPart;
	double rp2 = -(lhs.mImaginaryPart * rhs.mImaginaryPart);

	double ip1 = lhs.mRealPart * rhs.mImaginaryPart;
	double ip2 = lhs.mImaginaryPart * rhs.mRealPart;

	return ComplexDouble(rp1 + rp2, ip1 + ip2);
}

ComplexDouble operator/(const ComplexDouble& lhs, const ComplexDouble& rhs)
{
	ComplexDouble numeratorMult = lhs * rhs.conjugate();
	ComplexDouble denominatorConj = rhs * rhs.conjugate();

	numeratorMult.mRealPart /= denominatorConj.mRealPart;
	numeratorMult.mImaginaryPart /= denominatorConj.mRealPart;

	return numeratorMult;
}




ComplexDouble& operator+=(ComplexDouble& lhs, const ComplexDouble& rhs)
{
	lhs.mRealPart += rhs.mRealPart;
	lhs.mImaginaryPart += rhs.mImaginaryPart;

	return lhs;
}

ComplexDouble& operator-=(ComplexDouble& lhs, const ComplexDouble& rhs)
{
	lhs.mRealPart -= rhs.mRealPart;
	lhs.mImaginaryPart -= rhs.mImaginaryPart;

	return lhs;
}

ComplexDouble& operator*=(ComplexDouble& lhs, const ComplexDouble& rhs)
{
	lhs = lhs * rhs;

	return lhs;
}

ComplexDouble& operator/=(ComplexDouble& lhs, const ComplexDouble& rhs)
{
	lhs *= rhs.conjugate();
	ComplexDouble denominatorConj = rhs * rhs.conjugate();

	lhs.mRealPart /= denominatorConj.mRealPart;
	lhs.mImaginaryPart /= denominatorConj.mRealPart;

	return lhs;
}

std::ostream& operator<<(std::ostream& os, const ComplexDouble& rhs)
{
	if(rhs.mImaginaryPart < 0)
	{
		os << rhs.mRealPart << " - " << -rhs.mImaginaryPart << "i";	
	}
	else
	{
		os << rhs.mRealPart << " + " << rhs.mImaginaryPart << "i";	
	}
	return os;
}





