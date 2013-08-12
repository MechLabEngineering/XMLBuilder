#include <QApplication>
#include "MainWidget.h"

MainWidget::MainWidget(const QString &str, QWidget *parent)
    : QWidget(parent) , projectName(str)
{
    testbilder = new Testbilder;
    objMaker = new ObjectMaker(projectName);
    crSamp = new CreateSamplesMS(projectName, objMaker->getOutputFile());
    trCasc = new TrainCascade(projectName, crSamp->getOutputFile());
    testClas = new TestClassifier;

    groupBox1 = new QGroupBox("Testbilder");
    groupBox2 = new QGroupBox("Objectmaker");
    groupBox3 = new QGroupBox("Createsamples");
    groupBox4 = new QGroupBox("Traincascade");
    groupBox5 = new QGroupBox("Testclassifier");

    vbox1 = new QVBoxLayout;
    vbox2 = new QVBoxLayout;
    vbox3 = new QVBoxLayout;
    vbox4 = new QVBoxLayout;
    vbox5 = new QVBoxLayout;

    vbox1->addWidget(testbilder);
    vbox2->addWidget(objMaker);
    vbox3->addWidget(crSamp);
    vbox4->addWidget(trCasc);
    vbox5->addWidget(testClas);

    groupBox1->setFlat(true);
    groupBox2->setFlat(true);
    groupBox3->setFlat(true);
    groupBox4->setFlat(true);
    groupBox5->setFlat(true);

    groupBox1->setLayout(vbox1);
    groupBox2->setLayout(vbox2);
    groupBox3->setLayout(vbox3);
    groupBox4->setLayout(vbox4);
    groupBox5->setLayout(vbox5);


    tab = new QTabWidget;
    tab->addTab(groupBox1, "Testbilder");
    tab->addTab(groupBox2, "Objectmaker");
    tab->addTab(groupBox3, "Createsamples");
    tab->addTab(groupBox4, "Traincascade");
    tab->addTab(groupBox5, "Testclassifier");

    vbox = new QVBoxLayout;
    vbox->addWidget(tab);
    setLayout(vbox);
    setWindowTitle("XML Builder Main");
    resize(600,400);
}

void MainWidget::getCurrentPosition(int pos)
{

}
