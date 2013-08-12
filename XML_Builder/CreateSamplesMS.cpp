#include <QApplication>
#include "CreateSamplesMS.h"

CreateSamplesMS::CreateSamplesMS(const QString &str1, const QString &str2, QWidget *parent) : dirName(str1), info(str2), QWidget(parent)
{
    info = dirName+"/"+info;
    int width = 600;
    //nachfolgenden 4 Parameter sind für vec-file voreingestellt
    w = 24;
    h = 24;
    wStr.append(QString("%1").arg(w));
    hStr.append(QString("%1").arg(h));
    vec = "untitled";

    gridLayout = new QGridLayout(this);
    gridLayout->setAlignment(Qt::AlignCenter );

    infoIOLayoutList[0] = new InfoIOLayout("Eingabedatei:",info,"Ändern");
    infoIOLayoutList[0]->setMaximumWidth(width);
    infoIOLayoutList[1] = new InfoIOLayout("Ausgabedatei:",vec,"Ändern");
    infoIOLayoutList[1]->setMaximumWidth(width);
    infoIOLayoutList[2] = new InfoIOLayout("Skalierungsbreite:",wStr,"Ändern");
    infoIOLayoutList[2]->setMaximumWidth(width);
    infoIOLayoutList[3] = new InfoIOLayout("Skalierungshöhe:",hStr,"Ändern");
    infoIOLayoutList[3]->setMaximumWidth(width);

    buttonStart = new QPushButton("Start");


    gridLayout->addWidget(infoIOLayoutList[0],0,0);
    gridLayout->addWidget(infoIOLayoutList[1],1,0);
    gridLayout->addWidget(infoIOLayoutList[2],2,0);
    gridLayout->addWidget(infoIOLayoutList[3],3,0);
    gridLayout->addWidget(buttonStart,4,0);

    setLayout(gridLayout);

    connect(infoIOLayoutList[0]->button, SIGNAL(clicked()), this, SLOT(changeInputFile()));
    connect(infoIOLayoutList[1]->button, SIGNAL(clicked()), this, SLOT(changeOutputFile()));
    connect(infoIOLayoutList[2]->button, SIGNAL(clicked()), this, SLOT(changeW()));
    connect(infoIOLayoutList[3]->button, SIGNAL(clicked()), this, SLOT(changeH()));
    connect(buttonStart, SIGNAL(clicked()), this, SLOT(startCreateSamples()));
}

void CreateSamplesMS::changeInputFile()
{
    QString temp = QFileDialog::getOpenFileName(this,
                                        "Bitte eine Datei wählen",
                                        dirName,
                                        "Dokumente (*.txt)");
    if(!temp.isEmpty())
    {
        info = temp;
        infoIOLayoutList[0]->setInfotext(info);
    }
}

void CreateSamplesMS::changeOutputFile()
{
    bool ok = 0;
    QString temp = QInputDialog::getText(this,
                                        "Namen der Ausgabedatei eingeben",
                                        "Name der Ausgabedatei:",
                                        QLineEdit::Normal,
                                        "Untitled",
                                        &ok);
    if(ok && !temp.isEmpty())
    {
        vec = temp;
        infoIOLayoutList[1]->setInfotext(vec);
    }
}

void CreateSamplesMS::changeW()
{
    bool ok = 0;
    int value = QInputDialog::getInt(this,
                                     "Anzahl der Positiven für das Training eingeben",
                                     "Wert eingeben:",
                                     10,w,50,1,
                                     &ok);
    if(ok)
    {
        w = value;
        wStr = "";
        wStr.append(QString("%1").arg(w));
        infoIOLayoutList[2]->setInfotext(wStr);
    }
}

void CreateSamplesMS::changeH()
{
    bool ok = 0;
    int value = QInputDialog::getInt(this,
                                     "Anzahl der Positiven für das Training eingeben",
                                     "Wert eingeben:",
                                     10,h,50,1,
                                     &ok);
    if(ok)
    {
        h = value;
        hStr = "";
        hStr.append(QString("%1").arg(h));
        infoIOLayoutList[3]->setInfotext(hStr);
    }
}

void CreateSamplesMS::startCreateSamples()
{
    int total, num = 1000, showsamples = 0;

//    total = cvCreateTrainingSamplesFromInfo( info.toStdString().c_str(), vec.toStdString().c_str(),
//                                             num, showsamples, w, h );
}
