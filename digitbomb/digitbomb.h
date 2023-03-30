#ifndef DIGITBOMB_H
#define DIGITBOMB_H

#include <QMainWindow>//包含头文件QWidget窗口类
#include <QCloseEvent>
#include "secondwidget.h"
#include <QDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class digitbomb; }
QT_END_NAMESPACE

class digitbomb : public QMainWindow
{
    Q_OBJECT//Q_OBJECT,允许类中使用信号和槽机制
    //
public:
    digitbomb(QWidget *parent = nullptr);//构造
    ~digitbomb();//析构

private:
    Ui::digitbomb *ui;
    Secondwidget *secondwidget=NULL;
    void changeToSec();
    void changeToMenu();
};
#endif // DIGITBOMB_H
