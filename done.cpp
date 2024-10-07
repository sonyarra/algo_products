#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include "product.h"

using namespace std;

bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
            return false;
        }
    }
    return true;
}

bool isValidProductName(const string& name) {
    if (name.empty()) return false;

    for (char c : name) {
        if (!isspace(c)) {
            return !isNumeric(name);
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Ru");
    string name;
    double mass, temperature, maxTemperature, minTemperature, heatCapacity;
    char choice;

    do { // Используем цикл do-while для добавления нескольких продуктов

        cout << "Введите название продукта: ";
        getline(cin, name); // Используем getline для ввода строки с пробелами
        while (!isValidProductName(name)) {
            cout << "Некорректные данные. Название продукта должно состоять только из букв и пробелов. Попробуйте снова: ";
            getline(cin, name); // Используем getline для ввода строки с пробелами
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
        }

        cout << "Введите массу продукта (г): ";
        while (!(cin >> mass) || mass <= 0) {
            cout << "Некорректные данные. Масса должна быть положительным числом. Попробуйте снова: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Введите температуру продукта (°C): ";
        while (!(cin >> temperature)) {
            cout << "Некорректные данные. Температура должна быть числом. Попробуйте снова: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Цикл для ввода максимальной и минимальной температуры
        while (true) {
            cout << "Введите максимальную допустимую температуру (°C): ";
            while (!(cin >> maxTemperature)) {
                cout << "Некорректные данные. Температура должна быть числом. Попробуйте снова: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Введите минимальную допустимую температуру (°C): ";
            while (!(cin >> minTemperature)) {
                cout << "Некорректные данные. Температура должна быть числом. Попробуйте снова: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Проверка ограничений на диапазон значений (сразу после ввода)
            if (maxTemperature < minTemperature) {
                cout << "Ошибка: Максимальная температура не может быть меньше минимальной. Введите данные заново." << endl;
            }
            else {
                // Если значения корректные, выходим из цикла
                break;
            }
        }

        cout << "Введите теплоёмкость продукта (Дж/(г*К)): ";
        while (!(cin >> heatCapacity)) {
            cout << "Некорректные данные. Теплоёмкость должна быть числом. Попробуйте снова: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Создание объекта Product только после успешной проверки ограничений
        Product product(name, mass, temperature, maxTemperature, minTemperature, heatCapacity);

        cout << "\nНазвание: " << product.getName() << endl;
        cout << "Масса: " << product.getMass() << endl;
        cout << "Температура: " << product.getTemperature() << endl;
        cout << "Максимальная температура: " << product.getMaxTemperature() << endl;
        cout << "Минимальная температура: " << product.getMinTemperature() << endl;
        cout << "Состояние: " << (product.getState() == NORMAL ? "Нормальное" : (product.getState() == OVERHEATED ? "Перегрет" : "Переморожен")) << endl;
        cout << "Теплоёмкость: " << product.getHeatCapacity() << endl << endl;

        product.transferHeatEnergy(100);
        cout << "Температура после добавления тепла: " << product.getTemperature() << endl;
        cout << "Состояние: " << (product.getState() == NORMAL ? "Нормальное" : (product.getState() == OVERHEATED ? "Перегрет" : "Переморожен")) << endl << endl;

        // Меню для добавления еще одного продукта
        cout << "Добавить еще один продукт? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
