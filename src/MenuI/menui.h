#ifndef MENUI_H
#define MENUI_H

#include <QWidget>

namespace Ui {
class MenuI;
}

class MenuI : public QWidget
{
    Q_OBJECT

public:
    explicit MenuI(QWidget *parent = nullptr);
    ~MenuI();

private:
    Ui::MenuI *ui;
};

#endif // MENUI_H
