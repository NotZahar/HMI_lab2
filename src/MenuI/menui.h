#ifndef MENUI_H
#define MENUI_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QStandardItemModel>
#include <QMessageBox>

#include <string>
#include <iostream>

#include "../command/command.h"

namespace Ui {
class MenuI;
}

class MenuI : public QWidget
{
    Q_OBJECT

public:
    explicit MenuI(const std::string& path, QWidget* parent = nullptr);
    ~MenuI();

private slots:
    void doScd(bool c);
    void doGtd(bool c);
    void doRename(bool c);

private:
    Command command;

    QStandardItemModel* dirModel;
    Ui::MenuI* ui;
};

#endif // MENUI_H
