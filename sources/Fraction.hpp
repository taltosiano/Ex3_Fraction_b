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
    Fraction(float num);
    Fraction();
    Fraction(int numerator, int denominator);
    void reduce();
    int getNumerator() const;
    void setNumerator(int) ;
    int getDenominator() const;
    void setDenominator(int) ;
    
    Fraction operator+(const Fraction& other);
    Fraction operator+(float other);

    Fraction operator-(const Fraction& other);
    Fraction operator-(float other);

    Fraction operator*(const Fraction& other);
    Fraction operator*(float other);

    Fraction operator/(const Fraction& other);
    Fraction operator/(float other);

    bool operator==(const Fraction& other) const;
    bool operator==(float other) const;

    bool operator<(const Fraction& other) const;
    bool operator<(float other) const;

    bool operator>(const Fraction& other) const;
    bool operator>(float other) const;

    bool operator<=(const Fraction& other) const;
    bool operator<=(float other) const;

    bool operator>=(const Fraction& other) const;
    bool operator>=(float other) const;

    Fraction operator++(int) ;
    Fraction &operator++() ;

    Fraction operator--(int) ;
    Fraction operator--() ;

    friend ostream& operator<<(std::ostream& outs, const Fraction& other);
    friend istream& operator>>(std::istream& ins, Fraction& other);

    friend Fraction operator+(float frac, const Fraction& other);
    friend Fraction operator-(float frac, const Fraction& other);
    friend Fraction operator*(float frac, const Fraction& other);
    friend Fraction operator/(float frac, const Fraction& other);
    friend bool operator==(float frac, const Fraction& other);
    friend bool operator>(float frac, const Fraction& other);
    friend bool operator>=(float frac, const Fraction& other);
    friend bool operator<(float frac, const Fraction& other);
    friend bool operator<=(float frac, const Fraction& other);

};
}
#endif