#include "secondwidget.h"
#include "ui_secondwidget.h"

Secondwidget::Secondwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Secondwidget)
{
    ui->setupUi(this);
    connect(ui->OKBtn,&QPushButton::clicked,this,&Secondwidget::initMax_Min);
    connect(ui->MenuBtn,&QPushButton::clicked,this,[&]{emit this->back();});
    //connect(ui->lineEdit, &QLineEdit::editingFinished, this , &Dialog::AddStudent);
    dialog->sync(&minnum,&maxnum);

}

Secondwidget::~Secondwidget()
{
    delete ui;
}



void Secondwidget::initMax_Min()
{

    QString max=ui->lineEdit_max->text();
    QString min=ui->lineEdit_min->text();
    ui->lineEdit_max->clear();
    ui->lineEdit_min->clear();
    bool ok1,ok2;
    if(!max.toInt(&ok1)||max.isEmpty())
    {
        ui->lineEdit_max->setPlaceholderText("请输入一个有效数字");
    }
    if(!min.toInt(&ok2)||min.isEmpty())
    {
        ui->lineEdit_min->setPlaceholderText("请输入一个有效数字");
    }
    if(max.toInt()<min.toInt())
    {   //ui->lineEdit->setPlaceholderText("请输入一个名字");
        ui->lineEdit_max->setPlaceholderText("请输入一个比min大的数字");
        ui->lineEdit_min->setPlaceholderText("请输入一个比max小的数字");
    }
    else if(max.toInt(&ok1) && min.toInt(&ok2))
    {
        maxnum = max.toInt();
        minnum = min.toInt();
        startGame();
    }
}

void Secondwidget::startGame()
{
    dialog->show();
}
