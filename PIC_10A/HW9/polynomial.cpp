#include "polynomial.h"
#include "CImg.h"
#include <iostream>
#include <cassert>

using namespace pic10a;

polynomial::polynomial(double c)
{
	polynomial::coeffs = std::vector<double>(1, 0);
	polynomial::coeffs[0] = c;
}

int polynomial::degree()
{
	return polynomial::mDegree;
}

int polynomial::nonzeroTerms()
{
	int termCounter = 0;
	for(int i = 0; i <= polynomial::mDegree; i++)
	{
		if(polynomial::coeffs[i] == 0.0D)
		{
			termCounter++;
		}
	}

	return termCounter;
}

void polynomial::setCoeff(int deg, double c)
{
	assert(deg >= 0);
	
	if(deg > mDegree)
	{
		mDegree = deg;
	}
	coeffs.resize(mDegree + 1);
	coeffs[deg] = c;
	
	mDegree = 0;
	for(int i = 0; i < coeffs.size(); i++)
	{
		if(coeffs[i] != 0.0D)
		{
			mDegree = i;
		}
	}
}

double polynomial::getCoeff(int deg)
{
	assert(deg >= 0);

	if(deg <= polynomial::mDegree)
	{
		return polynomial::coeffs[deg];
	}
	return 0.0;	
}

double polynomial::operator()(double x)
{
	double accumulator = 0;

	for(int i = 0; i <= polynomial::mDegree; i++)
	{
		double powAccumulator = 1;
		for(int j = 0; j < i; j++)
		{
			powAccumulator *= x;
		}	

		accumulator += polynomial::coeffs[i] * powAccumulator; 
	}

	return accumulator;
}

polynomial polynomial::operator+(polynomial p)
{
	polynomial out;

	for(int i = 0; i <= degree() || i  <= p.degree(); i++)
	{
		out.setCoeff(i, getCoeff(i) + p.getCoeff(i));
	}

	return out;
}

polynomial polynomial::operator-()
{
	polynomial out;

	for(int i = 0; i <= degree(); i++)
	{
		out.setCoeff(i, -getCoeff(i));
	}

	return out;
}

polynomial polynomial::operator-(polynomial p)
{
	return *this + (-p);
}

polynomial polynomial::operator*(polynomial p)
{
	polynomial out;

	for(int i = 0; i <= degree() + p.degree(); i++)
	{
		double c = 0;	
		for(int j = 0; j <= i; j++)
		{
			c += getCoeff(j) * p.getCoeff(i - j);
		}

		out.setCoeff(i, c);
	}

	return out;
}

polynomial& polynomial::operator+=(polynomial p)
{
	polynomial out;

	for(int i = 0; i <= degree() || i  <= p.degree(); i++)
	{
		out.setCoeff(i, getCoeff(i) + p.getCoeff(i));
	}
	
	return *this;
}

polynomial& polynomial::operator-=(polynomial p)
{
	return *this += -p;
}

polynomial& polynomial::operator*=(polynomial p)
{
	for(int i = 0; i <= degree() + p.degree(); i++)
	{
		double c;	
		for(int j = 0; j <= i; i++)
		{
			c += getCoeff(j) * p.getCoeff(i - j);
		}

		setCoeff(i, c);
	}
	
	return *this;	
}

polynomial& polynomial::operator*=(double c)
{
	for(int i = 0; i <= degree(); i++)
	{
		setCoeff(i, getCoeff(i) * c);
	}

	return *this;
}

polynomial& polynomial::operator+=(double c)
{
	setCoeff(0, getCoeff(0) + c);

	return *this;
}

polynomial pic10a::operator+(double c, polynomial p)
{
	polynomial temp(c);

	return p + temp;
}

polynomial pic10a::operator*(double c, polynomial p)
{
	polynomial out;

	for(int i = 0; i <= p.degree(); i++)
	{
		out.setCoeff(i, c * p.getCoeff(i));	
	}
	return out;
}

polynomial pic10a::operator*(polynomial p, double c)
{
	return c * p;
}

//End my funcs
//
//
//
//
//
//End my funcs

std::ostream& pic10a::operator<<(std::ostream& s, polynomial p) {
  if (p.degree() == 0 && p.getCoeff(0) == 0.0)
    return (s << double(0));
  for (int i = p.degree(); i >= 0; i--) {
    if (p.getCoeff(i) == 0)
      continue;
    if (i < p.degree() && p.getCoeff(i)>0)
      s << "+";
    if (p.getCoeff(i) != 1.0 || i==0)
      s << p.getCoeff(i);
    if (i == 1) {
      s << "x";
    } else if (i > 1){
      s << "x^" << i;
    }
  }
  return s;
}


//Credit for this function:
//http://cimg.eu/
//http://stackoverflow.com/questions/39414084/plotting-a-vector-in-c-with-cimg
using namespace cimg_library;
void pic10a::plot(polynomial p) {
  int argc = 0; char** const argv = NULL;
  const char *const formula = cimg_option("-f", "p(x)", "Formula to    plot");
  const double x0 = cimg_option("-x0", -2.0, "Minimal X-value");
  const double x1 = cimg_option("-x1", 2.0, "Maximal X-value");
  const int resolution = cimg_option("-r", 5000, "Plot resolution");
  const unsigned int nresolution = resolution>1 ? resolution : 5000;
  const unsigned int plot_type = cimg_option("-p", 1, "Plot type");
  const unsigned int vertex_type = cimg_option("-v", 1, "Vertex type");

  //Create plot data
  CImg<double> values(1, nresolution, 1, 1, 0);

  std::cout << "stats" << nresolution << "\n";

  const unsigned int r = nresolution - 1;

  for (int i1 = 0; i1 < resolution; ++i1) {
    double xtime = x0 + i1*(x1 - x0) / r;
    values(0, i1) = p(xtime);
  }
	
  CImg<double> values2;
  values2 = values.display_graph(formula, plot_type, vertex_type, "X Axis", x0, x1, "Y Axis");
  //values2.normalize(0, 255);
  //values2.save_png("plot.png");
}







