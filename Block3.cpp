#include "ConsoleMenu.h"
#include <windows.h>   // Для установки кодировки консоли (Windows)
#include <iostream>    // Для std::cerr
#include <exception>   // Для std::exception
#include <stdexcept>   // Для стандартных исключений

int main() {
    try {
        setlocale(LC_ALL, "");         // Устанавливаем локаль для корректного отображения русских символов
        SetConsoleOutputCP(1251);      // Устанавливаем кодировку консоли на Windows (CP1251)
        SetConsoleCP(1251);            // Устанавливаем кодировку ввода на Windows (CP1251)

        ConsoleMenu::MainMenu();       // Запуск главного меню
    }
    catch (const std::exception& ex) {
        std::cerr << "Произошла ошибка: " << ex.what() << std::endl;
        return 1; // Возврат кода ошибки
    }
    catch (...) {
        std::cerr << "Произошла неизвестная ошибка." << std::endl;
        return 1;
    }

    return 0; // Успешное завершение
}
