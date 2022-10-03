#ifndef RENAMEWINDOW_H
#define RENAMEWINDOW_H

#include <QWidget>

#include <vector>

namespace Ui {
class RenameWindow;
}

class RenameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RenameWindow(const std::vector<QString>& oldNames, QWidget *parent = nullptr);
    ~RenameWindow();

private:
    Ui::RenameWindow *ui;
};

#endif // RENAMEWINDOW_H
