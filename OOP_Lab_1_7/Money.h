#pragma once
#include "string"

using namespace std;

class Money {
private:
    long hryvnias;
    unsigned char kopecks;

    // Допоміжні приватні методи для зручних обчислень в копійках
    long long toKopecks() const;
    void fromKopecks(long long total);

public:
    long getHryvnias() const { return hryvnias; }
    unsigned char getKopecks() const { return kopecks; }

    bool setHryvnias(long h);
    bool setKopecks(unsigned char k);

    bool Init(long h, unsigned char k);
    void Read();
    void Display() const;
    string toString() const;

    // Специфічні арифметичні операції для Варіанту 8
    Money Add(const Money& m) const;
    Money Sub(const Money& m) const;
    double Div(const Money& m) const;
    Money DivByNumber(double d) const;
    Money MulByNumber(double d) const;

    // Специфічні операції порівняння
    bool IsEqual(const Money& m) const;
    bool IsGreater(const Money& m) const;
    bool IsLess(const Money& m) const;
};