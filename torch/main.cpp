#include "CMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow *pw = new CMainWindow(0, /*Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint*/Qt::FramelessWindowHint);
    //pw->setWindowIcon(QIcon(":/icon_1.ico"));
    pw->show();
    //pw->setMinimumSize(pw->centralWidget->size().width()+10, pw->centralWidget->size().height()+10);
    //pw->setMaximumSize(QSize(16777215,16777215));
    return a.exec();
}
