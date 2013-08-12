#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QGroupBox>
#include "Testbilder.h"
#include "ObjectMaker.h"
#include "CreateSamplesMS.h"
#include "TrainCascade.h"
#include "TestClassifier.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(const QString& str, QWidget *parent = 0);
private:
    QString projectName;
    QTabWidget *tab;
    Testbilder *testbilder;
    ObjectMaker *objMaker;
    CreateSamplesMS *crSamp;
    TrainCascade *trCasc;
    TestClassifier *testClas;
    QVBoxLayout *vbox, *vbox1, *vbox2, *vbox3, *vbox4, *vbox5;
    QGroupBox *groupBox1, *groupBox2, *groupBox3, *groupBox4, *groupBox5;
//    QStackedWidget *widgetStack;
public slots:
    void getCurrentPosition ( int pos );
};


#endif // MAINWIDGET_H
