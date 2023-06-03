#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);

    void simplify();

public:
    Fraction();

    Fraction(int num, int denom);

    Fraction operator+(const Fraction& other) const;

    Fraction operator+(int value) const;

    friend Fraction operator+(int value, const Fraction& f);

    Fraction operator-(const Fraction& other) const;

    Fraction operator-(int value) const;

    friend Fraction operator-(int value, const Fraction& f);

    Fraction operator*(const Fraction& other) const;

    Fraction operator*(int value) const;

    friend Fraction operator*(int value, const Fraction& f);

    Fraction operator/(const Fraction& other) const;

    Fraction operator/(int value) const;

    friend Fraction operator/(int value, const Fraction& f);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

    bool operator==(const Fraction& other) const;

    bool operator!=(const Fraction& other) const;

    bool operator<(const Fraction& other) const;

    bool operator>(const Fraction& other) const;

    bool operator<=(const Fraction& other) const;

    bool operator>=(const Fraction& other) const;
};

Fraction operator+(int value, const Fraction& f);
Fraction operator-(int value, const Fraction& f);
Fraction operator*(int value, const Fraction& f);
Fraction operator/(int value, const Fraction& f);

template<typename T>
class MyArray {
private:
    T* arr;
    int size;

    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

public:
    MyArray(T* arr, int size);
    ~MyArray();

    void sort();
    void print() const;
};