#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1_7/Money.cpp"
#include "../OOP_Lab_1_7/Goods.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab17
{
	TEST_CLASS(UnitTestOOPLab17)
	{
	public:

		// 1. Тестуємо метод з Money.cpp (Додавання сум)
		TEST_METHOD(TestMoneyAdd)
		{
			Money m1, m2, expected, result;
			m1.Init(100, 50); // 100 грн 50 коп
			m2.Init(50, 70);  // 50 грн 70 коп

			expected.Init(151, 20); // 100.50 + 50.70 = 151.20
			result = m1.Add(m2);

			// Використовуємо наш метод IsEqual для перевірки рівності об'єктів
			Assert::IsTrue(expected.IsEqual(result));
		}

		// 2. Тестуємо метод з Money.cpp (Множення на число)
		TEST_METHOD(TestMoneyMulByNumber)
		{
			Money m, expected, result;
			m.Init(15, 40); // 15 грн 40 коп

			expected.Init(30, 80); // 15.40 * 2 = 30.80
			result = m.MulByNumber(2.0);

			Assert::IsTrue(expected.IsEqual(result));
		}

		// 3. Тестуємо метод з Goods.cpp (Зменшення кількості)
		TEST_METHOD(TestGoodsDecreaseQuantity)
		{
			Goods item;
			Money p;
			p.Init(10, 0);
			// Створюємо товар з кількістю 10 штук
			item.Init("Тест", "01.01.2026", p, 10, "INV-00");

			bool success = item.decreaseQuantity(4); // Віднімаємо 4 штуки

			Assert::IsTrue(success); // Операція має бути успішною
			Assert::AreEqual((unsigned int)6, item.getQuantity()); // Залишилось 6

			// Перевірка на захист від від'ємного значення
			// Намагаємося відняти 10 штук, коли на складі лише 6
			bool fail = item.decreaseQuantity(10);
			Assert::IsFalse(fail); // Очікуємо, що метод поверне false
		}

		// 4. Тестуємо метод з Goods.cpp (Обчислення загальної вартості)
		TEST_METHOD(TestGoodsCalculateTotalCost)
		{
			Goods item;
			Money p, expectedTotal;
			p.Init(12, 50); // Ціна 12 грн 50 коп
			// Створюємо товар у кількості 4 штук
			item.Init("Тест", "01.01.2026", p, 4, "INV-00");

			expectedTotal.Init(50, 0); // 12.50 * 4 = 50.00
			Money resultTotal = item.calculateTotalCost();

			Assert::IsTrue(expectedTotal.IsEqual(resultTotal));
		}
	};
}