#include <iostream>
#include <numeric>
#include <cmath>
#include <climits>
#include "Fraction.hpp"


using namespace std;
using namespace ariel;
namespace ariel{

Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0){
         throw std::invalid_argument("denominator can't be Zero");
    }

     if (denominator < 0){
        numerator *=-1;
        denominator *= -1;
     }
     if(numerator == 0){
        numerator = 0;
        denominator = 1;
     }
    this->setNumerator(numerator);
    this->setDenominator(denominator);
    reduce();
}
Fraction::Fraction(float num) {
    // convert the float to a fraction
    this->setNumerator(num * 1000);
    this->setDenominator(1000);
    reduce();
    }

Fraction::Fraction()
    {
    setNumerator(0);
    setDenominator(1);
    }

void Fraction::reduce(){
    int gcd = __gcd(abs(this->numerator),abs(this->denominator));  // using builtin gcd method
        this->numerator/=gcd;
        this->denominator/=gcd;
}
int Fraction::getNumerator() const{
    return this->numerator;
}
void Fraction::setNumerator(int n) {
   this->numerator = n;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setDenominator(int n) {
    if(n == 0){
        throw invalid_argument("Denominator must be different from 0");
    }
    this->denominator = n;
}

// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(const Fraction& other){
    int max_int = numeric_limits<int>::max();
    int min_int = numeric_limits<int>::min();
    if ((this->getNumerator() == max_int && this->getDenominator() != max_int)
            || (this->getNumerator() <= min_int + 1 && other.getNumerator() <= min_int + 1)
            || (other.getNumerator() == max_int && other.getDenominator() != max_int))
            {
               throw overflow_error("Overflow");
            }
    int mone = getNumerator() * other.getDenominator() + other.getNumerator() * getDenominator();
    int mehane = getDenominator() * other.getDenominator();
    return Fraction(mone, mehane);
}
Fraction Fraction::operator+(float other){
    Fraction f1(other);
    int mone = numerator * f1.denominator + f1.numerator * denominator;
    int mehane = denominator * f1.denominator;
    return Fraction(mone, mehane);
}
Fraction operator+(float f, const Fraction& other){          //friend 
    Fraction f1(f);
    int mone = f1.numerator * other.denominator + other.numerator * f1.denominator;
    int mehane = f1.denominator * other.denominator;
    return Fraction(mone, mehane);
 }

// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
Fraction Fraction::operator-(const Fraction& other){
    int max_int = numeric_limits<int>::max();
    int min_int = numeric_limits<int>::min();
    if ((this->getNumerator() <= min_int + 1 && other.getNumerator() <= min_int + 1)
            || (this->getNumerator() >= max_int - 1 && other.getNumerator() <= min_int + 1))
            {
                throw overflow_error("Overflow");
            }
    int mone = numerator * other.denominator - other.numerator * denominator;
    int mehane = denominator * other.denominator;
    return Fraction(mone, mehane);
}
Fraction Fraction::operator-(float other){
    Fraction f1(other);
    int mone = numerator * f1.denominator - f1.numerator * denominator;
    int mehane = denominator * f1.denominator;
    return Fraction(mone, mehane);
}
Fraction operator-(float f, const Fraction& other){          //friend 
    Fraction f1(f);
    int mone = f1.numerator * other.denominator - other.numerator * f1.denominator;
    int mehane = other.denominator * f1.denominator;
    return Fraction(mone, mehane); 
}

// The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(const Fraction& other){
      int max_int = numeric_limits<int>::max();
    if  ((this->getNumerator() == max_int && this->getDenominator() != max_int)
            || (this->getDenominator() == max_int && this->getNumerator() != max_int)
            || (other.getNumerator() == max_int && other.getDenominator() != max_int))
            {
                throw overflow_error("Overflow");
            }
    int mone = this->numerator * other.numerator;
    int mehane = this->denominator * other.denominator;
    return Fraction(mone, mehane);
}
Fraction Fraction::operator*(float other){
  Fraction f1(other);
  return Fraction(this->getNumerator() * f1.getNumerator(), this->getDenominator() * f1.getDenominator());
  
}
Fraction operator*(float f, const Fraction& other){          //friend 
  Fraction f1(f);
  return Fraction(other.getNumerator() * f1.getNumerator(), other.getDenominator() * f1.getDenominator());
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(const Fraction& other){
    if(other.getNumerator() == 0){
        throw::runtime_error("Can't divide by zero");
    }
    int max_int = numeric_limits<int>::max();
    if ((this->getDenominator() == max_int && this->getNumerator() < max_int - 100)
            || (this->getNumerator() == max_int && this->getDenominator() != max_int)){
                throw overflow_error("Overflow");
            }
    return Fraction(this->numerator * other.denominator, this->denominator * other.numerator);

}
Fraction Fraction::operator/(float other){
    if(other == 0.0) { 
       throw::runtime_error("Can't divide by zero");
  }
    Fraction nEw(other);
    return Fraction(this->numerator*nEw.denominator, this->denominator*nEw.numerator);

}
Fraction operator/(float f, const Fraction& other){          //friend 
     Fraction f1(f);
     return f1/other;
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(const Fraction& other) const{
    if(this->getNumerator() == 0 && other.getNumerator() == 0){
        return true;
    }
    return (this->getNumerator() == other.getNumerator()) && (this->getDenominator() == other.getDenominator());

}
bool Fraction::operator==(float other) const{
    if(this->getNumerator() == 0 && other == 0){
        return true;
    }
    float result = (float)numerator / (float)denominator;
    return (result == other);

}
bool operator==(float f, const Fraction& other) {          //friend 
    if(other.getNumerator() == 0 && f == 0){
        return true;
    }
    float result = (float)other.numerator / (float)other.denominator;
    return (result == f);
}

// All comparison operations (>,<,>=,<=)
bool Fraction::operator>(const Fraction& other) const{
    return (this->getNumerator() * other.getDenominator() > other.getNumerator() * this->getDenominator());
}
bool Fraction::operator>(float other) const{
    float result = (float)numerator / (float)denominator;
    return (result > other);

}
bool operator>(float f, const Fraction& other) {          //friend 
    Fraction f1(f);
    return (f1.getNumerator() * other.getDenominator() > other.getNumerator() * f1.getDenominator());
}

bool Fraction::operator<(const Fraction& other) const{
    return (this->getNumerator() * other.getDenominator() < other.getNumerator() * this->getDenominator());

}
bool Fraction::operator<(float other) const{
    Fraction f1(other);
    return (this->getNumerator() * f1.getDenominator() < f1.getNumerator() * this->getDenominator());

}
bool operator<(float f, const Fraction& other) {          //friend 
    Fraction f1(f);
    return (f1.getNumerator() * other.getDenominator() < other.getNumerator() * f1.getDenominator());
}

bool Fraction::operator>=(const Fraction& other) const{
    return (this->getNumerator() * other.getDenominator() >= other.getNumerator() * this->getDenominator());


}
bool Fraction::operator>=(float other) const{
    Fraction f1(other);
    return (this->getNumerator() * f1.getDenominator() >= f1.getNumerator() * this->getDenominator());

}
bool operator>=(float f, const Fraction& other) {          //friend 
     Fraction f1(f);
    return (f1.getNumerator() * other.getDenominator() >= other.getNumerator() * f1.getDenominator());
}

bool Fraction::operator<=(const Fraction& other) const{
    return (this->getNumerator() * other.getDenominator() <= other.getNumerator() * this->getDenominator());

}
bool Fraction::operator<=(float other) const{
    Fraction f1(other);
    return (this->getNumerator() * f1.getDenominator() <= f1.getNumerator() * this->getDenominator());

}
bool operator<=(float f, const Fraction& other) {          //friend 
     Fraction f1(f);
    return (f1.getNumerator() * other.getDenominator() <= other.getNumerator() * f1.getDenominator());
}

// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    this->numerator += this->denominator;
    return temp;
}
Fraction &Fraction::operator++() {
    this->numerator  += this->denominator;
    return *this;
}

Fraction Fraction::operator--(int){
   Fraction temp(*this);
    this->numerator -= this->denominator;
    return temp;
}
Fraction Fraction::operator--(){
  this->numerator  -= this->denominator;
    return *this;
}

// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

// The >> operator to read a fraction from an input stream by taking two integers as input.
istream& operator>>(std::istream& is, Fraction& frac) {
    is >> frac.numerator >> frac.denominator;
    if(!is){  
        throw runtime_error("error: invalid input");
    }
    if (frac.getDenominator() == 0){
        throw runtime_error("denominator can't be zero");
    }
    if (frac.getDenominator() < 0) {
        frac.setNumerator(frac.getNumerator() * -1); 
        frac.setDenominator(frac.getDenominator() * -1); 
    }    
    return is;
}
}