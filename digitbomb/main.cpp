#include "digitbomb.h"

#include <QApplication>
//       argc命令行变量的数量   argv命令行变量的数组
int main(int argc, char *argv[])
{
    //应用程序对象有且只有一个
    QApplication a(argc, argv);
    //窗口对象      mywidget父类->Qwidget
    digitbomb w;
    //窗口对象，默认不显示，使用show()方法显示窗口
    w.show();
    //让应用程序对象进入消息循环
    //==while(true){if(点x时)break;}
    return a.exec();
}
