#include "renamewindow.h"
#include "ui_renamewindow.h"

RenameWindow::RenameWindow(const std::vector<QString>& oldNames, QWidget *parent) :
    QWidget(parent),
    renameModel(new QStandardItemModel),
    ui(new Ui::RenameWindow)
{
    ui->setupUi(this);

    ui->tableView->setShowGrid(true);
    ui->tableView->verticalHeader()->setVisible(false);

    renameModel->setHorizontalHeaderLabels(QStringList{"Старое имя", "Новое имя"});
    ui->tableView->setModel(renameModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    int i = 0;
    for (const auto& oldName : oldNames) {
        QStandardItem* cell = new QStandardItem(oldName);
        cell->setEditable(false);
        renameModel->setItem(i, 0, cell);
        renameModel->setItem(i, 1, new QStandardItem(QString("")));
        ++i;
    }

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &RenameWindow::renameButtonIsPushed);
}

RenameWindow::~RenameWindow() {
    delete renameModel;
    delete ui;
}

void RenameWindow::renameButtonIsPushed(bool c) {
    std::vector<std::pair<const std::string, const std::string>> renameList;

    int rowCount = renameModel->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        renameList.push_back({renameModel->item(i, 0)->text().toStdString(),
                              renameModel->item(i, 1)->text().toStdString()});
    }

    emit renameButtonWasPushed(renameList);
}
