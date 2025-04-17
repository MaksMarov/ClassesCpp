#include "ConsoleMenu.h"
#include <windows.h>  // Для установки кодировки консоли (Windows)


int main() {
    setlocale(LC_ALL, "");         // Устанавливаем локаль для корректного отображения русских символов
    SetConsoleOutputCP(1251);      // Устанавливаем кодировку консоли на Windows (CP1251)
    SetConsoleCP(1251);            // Устанавливаем кодировку ввода на Windows (CP1251)

    ConsoleMenu::MainMenu();  // Запуск главного меню
    return 0;
}