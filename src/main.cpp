#include <QApplication>

#include <iostream>
#include <string>

#include "lab2.h"
#include "CLI/cli.h"
#include "MenuI/menui.h"

#define C

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

#ifdef M
    MenuI menuI(".");
    menuI.show();
#endif

#ifdef C
    CLI cli(".");
    cli.start();
    exit(EXIT_SUCCESS);
#endif

    return a.exec();
}
