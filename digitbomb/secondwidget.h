#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QWidget>
#include <QRandomGenerator>
#include "dialog.h"

namespace Ui {
class Secondwidget;
}

class Secondwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Secondwidget(QWidget *parent = nullptr);
    ~Secondwidget();

    //
    int maxnum,minnum;
    //
    void initMax_Min();
    void startGame();

    Dialog *dialog = new Dialog;
private:
    Ui::Secondwidget *ui;
signals:
    void back();
};

#endif // SECONDWIDGET_H
