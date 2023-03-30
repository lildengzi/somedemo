#include "digitbomb.h"
#include "ui_digitbomb.h"

/*
注释 ctrl+/
运行 ctrl+r
编译 ctrl+b
字体缩放 ctrl+鼠标滚轮
查找 ctrl+f
整行移动 ctrl+shift+上下建
帮助文档 F1  退出 ESC
自动对齐 ctrl+i
快速在同名.h.cpp间切换 F4
*/
digitbomb::digitbomb(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::digitbomb)
{
    ui->setupUi(this);
    this->secondwidget=new Secondwidget;
    connect(ui->startBtn,&QPushButton::clicked,this,&digitbomb::changeToSec);
    connect(this->secondwidget,&Secondwidget::back,this,&digitbomb::changeToMenu);
    connect(this->secondwidget->dialog, &Dialog::back, this , [&]
    {digitbomb::show();
    secondwidget->hide();
    });
    connect(ui->overBtn,&QPushButton::clicked,this,[&]{qApp->quit();});

    ui->startBtn->setDefault(true);
}

digitbomb::~digitbomb()
{
    delete ui;
}

void digitbomb::changeToSec()    //自定义的槽函数，执行的效果是隐藏父窗口，显示子窗口
{
    this->hide();
    this->secondwidget->show();
}

void digitbomb::changeToMenu()
{   //返回时创一个mbox确认返回
    QMessageBox mbox;
    mbox.setText("是否返回主菜单？");
    mbox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    mbox.setDefaultButton(QMessageBox::Ok);
    int ret = mbox.exec();
    switch (ret){
    case QMessageBox::Ok:break;
    case QMessageBox::Cancel:break;
    default: break;
    }
    //
    if(ret == QMessageBox::Ok)
    {
    this->secondwidget->hide();
    this->show();
    }
}
