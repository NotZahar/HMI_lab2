#include <QApplication>

#include "command/command.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Command cli("..");



    return a.exec();
}
