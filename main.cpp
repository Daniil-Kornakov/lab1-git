// Лабораторная работа № 1. Вариант 59.
// Выполнил: Корнаков Д. Р., группа ПИ-53.

#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

// ===== Расчётные функции варианта 59 =====

// 1. Квадратный корень методом Герона
// Итерации: x_{n+1} = (x_n + x/x_n) / 2
double sqrtHeron(double x) {
    if (x < 0) {
        cout << "Ошибка: отрицательное число под корнем!\n";
        return -1;
    }
    if (x == 0) return 0;
    
    double guess = x / 2.0;
    double epsilon = 0.000001;
    
    while (true) {
        double next = (guess + x / guess) / 2.0;
        if (abs(next - guess) < epsilon) {
            return next;
        }
        guess = next;
    }
}

// 2. Кубический корень через итерации
// Итерации: x_{n+1} = (2*x_n + x/(x_n^2)) / 3
double cubeRoot(double x) {
    if (x == 0) return 0;
    
    double guess = x / 3.0;
    double epsilon = 0.000001;
    
    while (true) {
        double next = (2.0 * guess + x / (guess * guess)) / 3.0;
        if (abs(next - guess) < epsilon) {
            return next;
        }
        guess = next;
    }
}

// ===== Главная функция: меню =====
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;
    double x;
    
    cout << "Корнаков Д. Р.";
    cout << "Вариант задания - 59";

    do {
        cout << "\n----------------------------------------\n";
        cout << "|   Программа рассчётов. Вариант 59    |\n";
        cout << "|---------------------------------------|\n";
        cout << "| 1. Квадратный корень (метод Герона)   |\n";
        cout << "| 2. Кубический корень                  |\n";
        cout << "| 0. Выход                              |\n";
        cout << "|---------------------------------------|\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Введите число x: ";
                cin >> x;
                cout << "Квадратный корень из " << x << " = " << sqrtHeron(x) << "\n";
                break;
            case 2:
                cout << "Введите число x: ";
                cin >> x;
                cout << "Кубический корень из " << x << " = " << cubeRoot(x) << "\n";
                break;
            case 0:
                cout << "Работа завершена.\n";
                break;
            default:
                cout << "Такого пункта нет.\n";
        }
    } while (choice != 0);
    
    return 0;
}

