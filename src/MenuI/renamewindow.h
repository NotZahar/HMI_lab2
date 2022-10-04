#ifndef RENAMEWINDOW_H
#define RENAMEWINDOW_H

#include <QWidget>
#include <QStandardItemModel>
#include <QPushButton>

#include <vector>
#include <string>
#include <utility>
#include <iostream>

namespace Ui {
class RenameWindow;
}

class RenameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RenameWindow(const std::vector<QString>& oldNames, QWidget *parent = nullptr);
    ~RenameWindow();

signals:
    void renameButtonWasPushed(std::vector<std::pair<const std::string, const std::string>> renameList);

private slots:
    void renameButtonIsPushed(bool c);

private:
    QStandardItemModel* renameModel;
    Ui::RenameWindow* ui;
};

#endif // RENAMEWINDOW_H
