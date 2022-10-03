#include "menui.h"
#include "ui_menui.h"

MenuI::MenuI(const std::string& path, QWidget *parent) :
    command(path),
    QWidget(parent),
    dirModel(new QStandardItemModel),
    ui(new Ui::MenuI)
{
    ui->setupUi(this);

    ui->label->setText(QString::fromStdString(command.getCurrentDirPath()));

    ui->tableView->setShowGrid(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    dirModel->setHorizontalHeaderLabels(QStringList{"Имя", "Формат"});
    ui->tableView->setModel(dirModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MenuI::doScd);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &MenuI::doGtd);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, &MenuI::doRename);
}

MenuI::~MenuI() {
    delete ui;
}

void MenuI::doScd(bool c) {
    dirModel->clear();

    std::map<const std::string, fileFormat> dir = command.scd();

    dirModel->setHorizontalHeaderLabels(QStringList{"Имя", "Формат"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    int i = 0;
    for (const auto& file : dir) {
        dirModel->setItem(i, 0, new QStandardItem(QString::fromStdString(file.first)));
        dirModel->setItem(i, 1, new QStandardItem(QString::fromStdString(lab2::FileInfo::fileType.at(file.second))));
        ++i;
    }
}

void MenuI::doGtd(bool c) {
    QModelIndex currentIndex = ui->tableView->currentIndex();
    QVariant currentData = dirModel->data(currentIndex);

    if (currentIndex.column() == 0) {
        try {
            command.gtd(currentData.toString().toStdString());
            dirModel->clear();
            ui->label->setText(QString::fromStdString(command.getCurrentDirPath()));
        }  catch (std::string& msg) {
            QMessageBox::critical(nullptr, "Ошибка", QString::fromStdString(ErrorInfo::errorMessages.at(ErrorInfo::error::wrongPath)));
        }
    } else {
        QMessageBox::critical(nullptr, "Ошибка", QString::fromStdString(ErrorInfo::errorMessages.at(ErrorInfo::error::wrongPath)));
    }
}

void MenuI::doRename(bool c) {

}
