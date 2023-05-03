#include <iostream>
#include <numeric>
#include <cmath>
#include "Fraction.hpp"


using namespace std;
using namespace ariel;
namespace ariel{

Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0 && numerator != 0){
         throw std::invalid_argument("denominator can't be Zero");
    }
    
    // if(numerator == 0){
    //     this->numerator = 0;
    //     this->denominator = 0;
    //     return;
    // }
     if (denominator < 0 ){
        numerator *=-1;
        denominator *= -1;
     }
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}
Fraction::Fraction(float num) {
        // convert the float to a fraction
    if(num != 0){    
         int _num = static_cast<int>(num * 1000);
          int _den = 1000;
        this->numerator = _num;
        this->denominator = _den;
    }

    else{
        this->numerator = 0;
        this->denominator = 0;
        return;
    }
    
     if (denominator < 0 ){
        this->numerator *=-1;
        this->denominator *= -1;
     }
    reduce();
    }
Fraction::Fraction()
    {
    setNumerator(0);
    setDenominator(1);
    }
void Fraction::reduce(){
    float gcd = std::gcd(this->numerator, this->denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
}

int Fraction::getNumerator() const{
    return this->numerator;
}
void Fraction::setNumerator(int n) {
    // if(n == 0){
    //     this->numerator = 0;
    //     this->denominator = 0;
    //     return;
    // }
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
    int mone = numerator * other.denominator + other.numerator * denominator;
    int mehane = denominator * other.denominator;
    return Fraction(mone, mehane);
    // int n = (this->numerator * other.denominator) + (this->denominator * other.numerator);
    // int d = this->denominator * other.denominator;
    // if (overAdd(*this, other))
    //     throw std::overflow_error("overflow");
    // return Fraction(int(n), int(d));
}
Fraction Fraction::operator+(float other){
    int mone = numerator + (other * denominator);
    int gcd = std::gcd(mone, denominator);
    return Fraction(mone / gcd, denominator / gcd);
}
Fraction operator+(float f, const Fraction& other){          //friend 
    int mone = other.numerator + (f * other.denominator);
    int gcd = std::gcd(mone, other.denominator);
    return Fraction(mone / gcd, other.denominator / gcd);
}

// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
Fraction Fraction::operator-(const Fraction& other){
    int mone = numerator * other.denominator - other.numerator * denominator;
    int mehane = denominator * other.denominator;
    return Fraction(mone, mehane);
}
Fraction Fraction::operator-(float other){
    if(other == 0){
        return this;
    }
    Fraction f1(other);
    int mone = numerator * f1.denominator - f1.numerator * denominator;
    int mehane = denominator * f1.denominator;
    return Fraction(mone, mehane);
    // int mone = numerator - (other * denominator);
    // int gcd = std::gcd(mone, denominator);
    // return Fraction(mone / gcd, denominator / gcd);
}
Fraction operator-(float f, const Fraction& other){          //friend 
    // int mone = (f * other.denominator) - other.numerator;
    // int gcd = std::gcd(mone, other.denominator);
    if(f == 0){
        return other * (-1);
    }
    Fraction f1(f);
    int mone = f1.numerator * other.denominator - other.numerator * f1.denominator;
    int mehane = other.denominator * f1.denominator;
    return Fraction(mone, mehane); 


    
    //  Fraction f1(f);  // fraction(1,2)
    //  int common = f1.getDenominator() * other.getDenominator();
    //  int mone = f1.getNumerator()*other.getDenominator() - f1.getDenominator()*other.getNumerator();
    //  return Fraction(mone, common);
   
}

// The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(const Fraction& other){
    int mone = this->numerator * other.numerator;
    int mehane = this->denominator * other.denominator;
    return Fraction(mone, mehane);
}
Fraction Fraction::operator*(float other){
  Fraction f1(other);
  return Fraction(this->getNumerator() * f1.getNumerator(), this->getDenominator() * f1.getDenominator());
  
    // int mone = numerator * other;
    // int gcd = std::gcd(mone, denominator);
    // return Fraction(mone / gcd, denominator / gcd);
}
Fraction operator*(float f, const Fraction& other){          //friend 
  Fraction f1(f);
  return Fraction(other.getNumerator() * f1.getNumerator(), other.getDenominator() * f1.getDenominator());
    // int mone = f * other.numerator;
    // int gcd = std::gcd(mone, other.denominator);
    // return Fraction(mone / gcd, other.denominator / gcd);
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(const Fraction& other){
    if(other.getNumerator() == 0){
        throw::runtime_error("Can't divide by zero");
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
    if(other.getNumerator() == 0){
        throw::runtime_error("Can't divide by zero");
    }
    Fraction nEw(f);
    return Fraction(nEw.numerator*other.denominator, nEw.denominator*other.numerator);

}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(const Fraction& other) const{
    if(this->numerator == 0 && other.numerator == 0){
        return true;
    }
    return (numerator == other.numerator) && (denominator == other.denominator);

}
bool Fraction::operator==(float other) const{
    if(this->numerator == 0 && other == 0){
        return true;
    }
    float result = (float)numerator / (float)denominator;
    return (result == other);

}
bool operator==(float f, const Fraction& other) {          //friend 
    if(other.numerator == 0 && f == 0){
        return true;
    }
    float result = (float)other.numerator / (float)other.denominator;
    return (result == f);
}

// All comparison operations (>,<,>=,<=)
bool Fraction::operator>(const Fraction& other) const{
    int lcm = std::lcm(denominator, other.denominator);
    int thisNumerator = numerator * (lcm / denominator);
    int otherNumerator = other.numerator * (lcm / other.denominator);
    return  (thisNumerator > otherNumerator);

}
bool Fraction::operator>(float other) const{
    float result = (float)numerator / (float)denominator;
    return (result > other);

}
bool operator>(float f, const Fraction& other) {          //friend 
    // float result = (float)other.numerator / (float)other.denominator;
    // return (f > result);
    Fraction f1(f);
    return (f1.getNumerator() * other.getDenominator() > other.getNumerator() * f1.getDenominator());
}

bool Fraction::operator<(const Fraction& other) const{
    // int lcm = std::lcm(denominator, other.denominator);
    // int thisNumerator = numerator * (lcm / denominator);
    // int otherNumerator = other.numerator * (lcm / other.denominator);
    // return  (thisNumerator < otherNumerator);
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
    // Fraction f0 = *this;
    //  //this->numerator;
    //  //this->denominator;
    // return f0;
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}
Fraction &Fraction::operator++() {
    //  this->numerator;
    //  this->denominator;
    // return *this;
     numerator  += denominator;
    return *this;

}

Fraction Fraction::operator--(int){
    Fraction temp(*this);
    numerator -= denominator;
    int gcd = __gcd(numerator,  denominator);
    numerator /= gcd;
    denominator /= gcd;
    return temp;
}
Fraction Fraction::operator--(){
    numerator -= denominator;
    int gcd = __gcd(numerator,  denominator);
    numerator /= gcd;
    denominator /= gcd;
    return *this;
 
}

// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
    // cout << fraction.numerator << "/" << fraction.denominator << endl;
}

// std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
//     if (fraction.denominator == 1) {
//         os << fraction.numerator;
//     } else {
//         os << fraction.numerator << "/" << fraction.denominator;
//     }
//     return os;
// }

// std::ostream& operator<<(std::ostream& os, const std::pair<const char*, Fraction>& p) {
//     os << p.first << p.second;
//     return os;
// }

// The >> operator to read a fraction from an input stream by taking two integers as input.
istream& operator>>(std::istream& is, Fraction& fraction) {
    // int numerator, denominator;
    // char slash;
    // is >> numerator >> slash >> denominator;
    // fraction = Fraction(numerator, denominator);
    // return is;


    //   int n, d;
    // if (is >> n >> d) {
    //     if (d == 0) {
    //         throw runtime_error("Division by zero is undefined");
    //     }
    //     if (n == 0) { //Fraction equal 0
    //         Fraction fraction(n, 1);
    //         // fraction.setNumerator(n);
    //         // fraction.setDenominator(1);
    //     } else {
    //         Fraction fraction(n, d);
    //         // fraction.setNumerator(n);
    //         // fraction.setDenominator(d);
    //     }
    // } else {
    //     throw runtime_error("Input 2 numbers");
    // }

    // return is;
    char c ;
        int num , den;
         
        is >> num >> den ;
        
        if (is && den != 0) {
        fraction.setNumerator(num);
        fraction.setDenominator(den);
    }
     else {
        throw runtime_error("Bad_in");
    }
    return is;
}
}