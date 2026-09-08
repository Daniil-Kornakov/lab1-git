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



// ===== Главная функция: меню =====
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;
    double x;
    
    do {
        cout << "\n== Вариант 59: Приближённые корни ==\n";
        cout << "1. Квадратный корень (метод Герона)\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Введите число x: ";
                cin >> x;
                cout << "sqrt(" << x << ") = " << sqrtHeron(x) << "\n";
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

