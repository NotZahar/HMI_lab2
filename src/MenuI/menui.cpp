#include "menui.h"
#include "ui_menui.h"

MenuI::MenuI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuI)
{
    ui->setupUi(this);
}

MenuI::~MenuI()
{
    delete ui;
}
