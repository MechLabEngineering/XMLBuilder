//#include "mainwindow.h"
#include <QApplication>
#include "StartWidget.h"
#include "MainWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWidget *startWin;
    do
    {
        startWin = new StartWidget;
        startWin->show();
    }while(startWin->getProjectName().isEmpty());

    MainWidget *mainWin = new MainWidget(startWin->getProjectName());
    mainWin->showMaximized();



    return a.exec();
}
