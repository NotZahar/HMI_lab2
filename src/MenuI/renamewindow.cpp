#include "renamewindow.h"
#include "ui_renamewindow.h"

RenameWindow::RenameWindow(const std::vector<QString>& oldNames, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenameWindow)
{
    ui->setupUi(this);


}

RenameWindow::~RenameWindow()
{
    delete ui;
}
