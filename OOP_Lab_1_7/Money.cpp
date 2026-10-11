#include "Money.h"
#include "iostream"
#include "sstream"
#include "iomanip"

using namespace std;

// Перетворення в загальну кількість копійок для зручної математики
long long Money::toKopecks() const {
    return hryvnias * 100 + kopecks;
}

// Конвертація з копійок назад у гривні та копійки
void Money::fromKopecks(long long total) {
    if (total < 0) total = 0; // Сума не може бути від'ємною
    hryvnias = total / 100;
    kopecks = static_cast<unsigned char>(total % 100);
}

bool Money::setHryvnias(long h) {
    if (h >= 0) {
        hryvnias = h;
        return true;
    }
    return false;
}

bool Money::setKopecks(unsigned char k) {
    if (k < 100) {
        kopecks = k;
        return true;
    }
    return false;
}

bool Money::Init(long h, unsigned char k) {
    if (setHryvnias(h) && setKopecks(k)) {
        return true;
    }
    hryvnias = 0; kopecks = 0;
    return false;
}

void Money::Read() {
    long h;
    int k; // Вводимо як int, бо unsigned char зчитається як 1 символ, а не число
    do {
        cout << "  Введіть гривні: "; cin >> h;
        cout << "  Введіть копійки (0-99): "; cin >> k;
        if (Init(h, static_cast<unsigned char>(k))) break;
        cout << "  Помилка! Некоректні дані. Спробуйте ще раз." << endl;
    } while (true);
}

void Money::Display() const {
    cout << toString();
}

string Money::toString() const {
    stringstream sout;
    // Вивід через кому з обов'язковими двома цифрами для копійок (напр. 05 коп)
    sout << hryvnias << "," << setfill('0') << setw(2) << (int)kopecks << " грн";
    return sout.str();
}

Money Money::Add(const Money& m) const {
    Money res;
    res.fromKopecks(this->toKopecks() + m.toKopecks());
    return res;
}

Money Money::Sub(const Money& m) const {
    Money res;
    res.fromKopecks(this->toKopecks() - m.toKopecks());
    return res;
}

double Money::Div(const Money& m) const {
    if (m.toKopecks() == 0) return 0.0;
    return static_cast<double>(this->toKopecks()) / m.toKopecks();
}

Money Money::DivByNumber(double d) const {
    Money res;
    if (d == 0) {
        res.fromKopecks(0);
        return res;
    }
    res.fromKopecks(static_cast<long long>(this->toKopecks() / d));
    return res;
}

Money Money::MulByNumber(double d) const {
    Money res;
    res.fromKopecks(static_cast<long long>(this->toKopecks() * d));
    return res;
}

bool Money::IsEqual(const Money& m) const {
    return this->toKopecks() == m.toKopecks();
}

bool Money::IsGreater(const Money& m) const {
    return this->toKopecks() > m.toKopecks();
}

bool Money::IsLess(const Money& m) const {
    return this->toKopecks() < m.toKopecks();
}