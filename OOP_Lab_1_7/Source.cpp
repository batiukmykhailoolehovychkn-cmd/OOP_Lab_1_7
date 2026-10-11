#include "iostream"
#include "Money.h"
#include "Goods.h"
#include "windows.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== 1. Створення об'єкту Goods ===" << endl;
    Goods item1;
    Money price1;
    price1.Init(150, 50); // 150 грн 50 коп
    item1.Init("Клавіатура", "10.10.2026", price1, 10, "INV-001");
    item1.Display();

    cout << "\n=== 2. Зміна кількості та уцінка ===" << endl;
    item1.decreaseQuantity(2); // Продали 2 шт, залишилось 8
    cout << "Після продажу 2 шт загальна " << item1.toString() << endl;

    cout << "\n(Товар прострочено на 15 днів, уцінка 15%)" << endl;
    item1.applyDiscount(15);
    item1.Display();

    cout << "\n=== 3. Введення з клавіатури ===" << endl;
    Goods item2;
    item2.Read();
    cout << "\nВи ввели:" << endl;
    item2.Display();

    cout << "\n=== 4. Демонстрація ВСІХ операцій класу Money ===" << endl;
    Money m1, m2, m3;
    m1.Init(500, 0);  // 500 грн 00 коп
    m2.Init(120, 50); // 120 грн 50 коп
    m3.Init(500, 0);  // 500 грн 00 коп

    cout << "Сума 1: " << m1.toString() << endl;
    cout << "Сума 2: " << m2.toString() << endl;
    cout << "Сума 3: " << m3.toString() << endl;
    cout << "-----------------------------------" << endl;

    // 1. Додавання
    Money sum = m1.Add(m2);
    cout << "[Додавання сум]: " << sum.toString() << endl;

    // 2. Віднімання
    Money diff = m1.Sub(m2);
    cout << "[Віднімання сум]: " << diff.toString() << endl;

    // 3. Ділення сум (результат - це коефіцієнт/число)
    double divRes = m1.Div(m2);
    cout << "[Ділення сум (Сума1 / Сума2)]: " << divRes << endl;

    // 4. Множення суми на дробове число
    Money mulByNum = m2.MulByNumber(2.5);
    cout << "[Множення (Сума2 * 2.5)]: " << mulByNum.toString() << endl;

    // 5. Ділення суми на дробове число
    Money divByNum = m1.DivByNumber(4.0);
    cout << "[Ділення (Сума1 / 4.0)]: " << divByNum.toString() << endl;

    // 6. Операції порівняння
    cout << "-----------------------------------" << endl;
    cout << "[Порівняння]:" << endl;
    if (m1.IsEqual(m2)) {
        cout << "-> Суми рівні." << endl;
    }
    else if (m1.IsGreater(m2)) {
        cout << "-> Сума 1 БІЛЬША за Суму 2." << endl;
    }
    else if (m1.IsLess(m2)) {
        cout << "-> Сума 1 МЕНША за Суму 2." << endl;
    }

    // Додаткова перевірка IsEqual та IsLess
    cout << "\nПорівняємо Сума 1 (" << m1.toString() << ") та Сума 3 (" << m3.toString() << "):" << endl;
    if (m1.IsEqual(m3)) cout << "-> Сума 1 ДОРІВНЮЄ Сумі 3." << endl;

    return 0;
}