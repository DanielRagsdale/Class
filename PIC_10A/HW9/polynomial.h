#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

namespace pic10a
{
  
  class polynomial {
   private:
    //coefficient of term a*x^n is represented by v[n]
    unsigned int mDegree = 0;
    std::vector<double> coeffs;
  
   public:
    polynomial(double c = 0.0);
    int degree();
    int nonzeroTerms();
    void setCoeff(int deg, double c);
    double getCoeff(int deg);
    double operator()(double x);
    polynomial operator+(polynomial p);
    polynomial& operator+=(polynomial p);
    polynomial operator-();
    polynomial operator-(polynomial p);
    polynomial& operator-=(polynomial p);
    polynomial operator*(polynomial p);
    polynomial& operator*=(polynomial p);
    polynomial& operator+=(double c);
    polynomial& operator*=(double c);
  };
  
  polynomial operator+(double c, polynomial p);
  polynomial operator*(double c, polynomial p);
  polynomial operator*(polynomial p, double c);
  

  std::ostream& operator<<(std::ostream& s, polynomial p);
  void plot(polynomial p);
}

#endif
