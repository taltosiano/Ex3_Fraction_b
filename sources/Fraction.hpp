#ifndef FRACTION_H
#define FRACTION_H
#include <stdio.h>
#include <iostream>
using namespace std;

namespace ariel{

class Fraction{
private:
    int numerator;
    int denominator;

public:
   // Fraction();
    Fraction(int numerator, int denominator);
    int getNumerator() const;
    void setNumerator(int);
    int getDenominator() const;
    void setDenominator(int);

    Fraction operator+(const Fraction& other);
    Fraction operator+(float other);

    Fraction operator-(const Fraction& other);
    Fraction operator-(float other);

    Fraction operator*(const Fraction& other);
    Fraction operator*(float other);

    Fraction operator/(const Fraction& other);
    Fraction operator/(float other);

    bool operator==(const Fraction& other);
    bool operator==(float other);

    bool operator<(const Fraction& other);
    bool operator<(float other);

    bool operator>(const Fraction& other);
    bool operator>(float other);

    bool operator<=(const Fraction& other);
    bool operator<=(float other);

    bool operator>=(const Fraction& other);
    bool operator>=(float other);

    Fraction operator++(int) ;
    Fraction &operator++() ;

    Fraction operator--(int) ;
    Fraction operator--() ;

    friend ostream& operator<<(std::ostream& os, const Fraction& other);
    friend istream& operator>>(std::istream& is, Fraction& other);

    friend Fraction operator+(float f, Fraction& other);
    friend Fraction operator-(float f, Fraction& other);
    friend Fraction operator*(float f, Fraction& other);
    friend Fraction operator/(float f, Fraction& other);
    friend bool operator==(float f, Fraction& other);
    friend bool operator>(float f, Fraction& other);
    friend bool operator>=(float f, Fraction& other);
    friend bool operator<(float f, Fraction& other);
    friend bool operator<=(float f, Fraction& other);

};
}
#endif