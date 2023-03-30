#include "dialog.h"
#include "qpushbutton.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->okBtn,&QPushButton::clicked,this,&Dialog::guessWhat);
    connect(ui->quitBtn,&QPushButton::clicked,this,[&]{emit this->back();
        this->hide();
        ui->lineEdit->clear();
        ui->label->clear();});
    //setDefault设置默认按钮
    //ui->button_add->QPushButton::setDefault(true);
    ui->okBtn->setDefault(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::guessWhat()
{   //QRandomGenerator::global()->bounded();
    static int bomb;
    int minnumber=*min,maxnumber=*max;
    static bool once = true;//静态变量初始化一次

    if (once)
    {
       bomb = QRandomGenerator::global()->bounded(minnumber,maxnumber);  //只执行一遍的代码
       once = false;
    }

    //功能实现
    ui->label->clear();
    QString num=ui->lineEdit->text();
    if(num.toDouble(&ok))
    {
        number = num.toInt();
        if(number==bomb)
        {
            ui->label->setText("你炸了！");
            once=true,bomb=NULL;
        }
        else if(number>maxnumber)
        {
            ui->label->setText("你输入的数字大于最大值,请重新输入");
        }
        else if(number<minnumber)
        {
            ui->label->setText("你输入的数字小于最小值,请重新输入");
        }
        else if(number>bomb)
        {
            ui->label->setText("你输的数字比炸弹大");
        }
        else if(number<bomb)
        {
            ui->label->setText("你输的数字比炸弹小");
        }
    }
    else {ui->label->setText("请输入一个有效数字");}
}








