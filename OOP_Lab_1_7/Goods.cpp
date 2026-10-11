#include "Goods.h"
#include "iostream"
#include "sstream"

using namespace std;

bool Goods::setPrice(const Money& p) {
    price = p;
    return true;
}

bool Goods::setQuantity(unsigned int q) {
    quantity = q;
    return true;
}

bool Goods::Init(string n, string d, const Money& p, unsigned int q, string inv) {
    setName(n);
    setDate(d);
    setInvoiceNumber(inv);
    setPrice(p);
    setQuantity(q);
    return true;
}

void Goods::Read() {
    string n, d, inv;
    unsigned int q;
    Money p;

    cout << "Найменування товару: "; cin >> n;
    cout << "Дата оформлення: "; cin >> d;
    cout << "Номер накладної: "; cin >> inv;
    cout << "Введення ціни одиниці товару:" << endl;
    p.Read(); // Делегуємо зчитування ціни класу Money
    cout << "Кількість одиниць: "; cin >> q;

    Init(n, d, p, q, inv);
}

void Goods::Display() const {
    cout << "Товар: " << name << " | Накладна: " << invoiceNumber << " | Дата: " << date << endl;
    cout << "Ціна за 1 шт: "; price.Display(); cout << " | Кількість: " << quantity << " шт." << endl;
    cout << "Загальна " << toString() << endl;
}

// За завданням цей метод повертає саме літерний рядок з вартістю товару
string Goods::toString() const {
    stringstream sout;
    sout << "вартість товару: " << calculateTotalCost().toString();
    return sout.str();
}

void Goods::increaseQuantity(unsigned int amount) {
    quantity += amount;
}

bool Goods::decreaseQuantity(unsigned int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        return true;
    }
    return false; // Захист від від'ємної кількості
}

Money Goods::calculateTotalCost() const {
    // Вартість = Ціна * Кількість
    return price.MulByNumber(quantity);
}

void Goods::applyDiscount(int daysOverdue) {
    if (daysOverdue <= 0) return;

    // Знижка 1% за кожен день. 
    double discountFactor = 1.0 - (0.01 * daysOverdue);
    if (discountFactor < 0) discountFactor = 0.0; // Щоб ціна не стала від'ємною при >100 днях

    price = price.MulByNumber(discountFactor);
}