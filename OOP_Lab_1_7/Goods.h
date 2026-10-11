#pragma once
#include "string"
#include "Money.h"

using namespace std;

class Goods {
private:
    string name;
    string date;
    Money price; // Агреговане поле (композиція)
    unsigned int quantity;
    string invoiceNumber;

public:
    string getName() const { return name; }
    string getDate() const { return date; }
    Money getPrice() const { return price; }
    unsigned int getQuantity() const { return quantity; }
    string getInvoiceNumber() const { return invoiceNumber; }

    void setName(string n) { name = n; }
    void setDate(string d) { date = d; }
    void setInvoiceNumber(string inv) { invoiceNumber = inv; }
    bool setPrice(const Money& p);
    bool setQuantity(unsigned int q);

    bool Init(string n, string d, const Money& p, unsigned int q, string inv);
    void Read();
    void Display() const;

    // За завданням метод має повертати саме ВАРТІСТЬ у вигляді рядка
    string toString() const;

    // Специфічні методи Варіанту 8
    void increaseQuantity(unsigned int amount);
    bool decreaseQuantity(unsigned int amount);
    Money calculateTotalCost() const;
    void applyDiscount(int daysOverdue); // уцінка на 1% за день
};