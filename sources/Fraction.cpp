#include <iostream>
#include <numeric>
#include "Fraction.hpp"


using namespace std;
using namespace ariel;
namespace ariel{

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}
Fraction f1(0,1);
// Fraction::Fraction(){
// this->numerator = 0;
// this->denominator = 1;
// }

int Fraction::getNumerator() const{
    return this->numerator;
}
void Fraction::setNumerator(int n){
   this->numerator = n;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setDenominator(int n){
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
}
Fraction Fraction::operator+(float other){
    int mone = numerator + (other * denominator);
    int gcd = std::gcd(mone, denominator);
    return Fraction(mone / gcd, denominator / gcd);
}
Fraction operator+(float f, Fraction& other){          //friend 
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
    int mone = numerator - (other * denominator);
    int gcd = std::gcd(mone, denominator);
    return Fraction(mone / gcd, denominator / gcd);
}
Fraction operator-(float f, Fraction& other){          //friend 
    int mone = (f * other.denominator) - other.numerator;
    int gcd = std::gcd(mone, other.denominator);
    return Fraction( mone / gcd, other.denominator / gcd);
}

// The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(const Fraction& other){
    int mone = this->numerator * other.numerator;
    int mehane = this->denominator * other.denominator;
    return Fraction(mone, mehane);
}
Fraction Fraction::operator*(float other){
    // double result = static_cast<double>(numerator) / denominator * other;
    // int gcd = __gcd(static_cast<int>(result * denominator), denominator);
    // return Fraction(static_cast<int>(result * denominator / gcd), denominator / gcd);
    // int newNumerator = static_cast<int>(other * this->numerator );
    // return Fraction(newNumerator, denominator);
    int mone = numerator * other;
    int gcd = std::gcd(mone, denominator);
    return Fraction(mone / gcd, denominator / gcd);
}
Fraction operator*(float f, Fraction& other){          //friend 
    int mone = f * other.numerator;
    int gcd = std::gcd(mone, other.denominator);
    return Fraction(mone / gcd, other.denominator / gcd);
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(const Fraction& other){
    int mone = this->numerator * other.numerator;
    int mehane = this->denominator * other.denominator;
    return Fraction(mone, mehane);

}
Fraction Fraction::operator/(float other){
    int mehane = denominator * other;
    int gcd = std::gcd(numerator, mehane);
    return Fraction(numerator / gcd, mehane / gcd);

}
Fraction operator/(float f, Fraction& other){          //friend 
    int mone = f * other.denominator;
    int gcd = std::gcd(mone, other.numerator);
    return Fraction(mone / gcd, other.numerator / gcd);
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(const Fraction& other){
    return (numerator == other.numerator) && (denominator == other.denominator);

}
bool Fraction::operator==(float other){
    float result = (float)numerator / (float)denominator;
    return (result == other);

}
bool operator==(float f, Fraction& other){          //friend 
    float result = (float)other.numerator / (float)other.denominator;
    return (result == f);
}

// All comparison operations (>,<,>=,<=)
bool Fraction::operator>(const Fraction& other){
    int lcm = std::lcm(denominator, other.denominator);
    int thisNumerator = numerator * (lcm / denominator);
    int otherNumerator = other.numerator * (lcm / other.denominator);
    return  (thisNumerator > otherNumerator);

}
bool Fraction::operator>(float other){
    float result = (float)numerator / (float)denominator;
    return (result > other);

}
bool operator>(float f, Fraction& other){          //friend 
    float result = (float)other.numerator / (float)other.denominator;
    return (f > result);
}

bool Fraction::operator<(const Fraction& other){
    int lcm = std::lcm(denominator, other.denominator);
    int thisNumerator = numerator * (lcm / denominator);
    int otherNumerator = other.numerator * (lcm / other.denominator);
    return  (thisNumerator < otherNumerator);

}
bool Fraction::operator<(float other){
        return true;

}
bool operator<(float f, Fraction& other){          //friend 
    return true;
}

bool Fraction::operator>=(const Fraction& other){
    return true;

}
bool Fraction::operator>=(float other){
        return true;

}
bool operator>=(float f, Fraction& other){          //friend 
    return true;
}

bool Fraction::operator<=(const Fraction& other){
    return true;

}
bool Fraction::operator<=(float other){
        return true;

}
bool operator<=(float f, Fraction& other){          //friend 
    return true;
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
       return f1;
 
}
Fraction Fraction::operator--(){
       return f1;
 
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
    int numerator, denominator;
    char slash;
    is >> numerator >> slash >> denominator;
    fraction = Fraction(numerator, denominator);
    return is;
    
}
}