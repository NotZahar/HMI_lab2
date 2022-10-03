#include <QApplication>

#include <iostream>
#include <string>

#include "lab2.h"
#include "CLI/cli.h"
#include "MenuI/menui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MenuI* menuI = nullptr;

    std::cout << "Выберите вид пользовательского интерфейса:" << std::endl
              << "1.Командный режим" << std::endl
              << "2.Меню" << std::endl
              << std::flush;

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
        CLI cli(".");
        cli.start();
        exit(EXIT_SUCCESS);
        break;
    }
    case 2: {
        menuI = new MenuI("."); // memory leak
        menuI->show();
        break;
    }
    default: {
        std::cout << lab2::ErrorInfo::errorMessages.at(lab2::ErrorInfo::error::incorrectEntryInput) << std::endl << std::flush;
        exit(EXIT_SUCCESS);
        break;
    }
    }

    return a.exec();
}
