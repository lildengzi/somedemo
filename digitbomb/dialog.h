#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QRandomGenerator>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    void guessWhat();
    //
    bool ok;
    int number;
    int* max,* min;
    void sync(int *p,int *q)
    {
        max = q;
        min = p;
    }

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
signals:
    void back();
};

#endif // DIALOG_H
