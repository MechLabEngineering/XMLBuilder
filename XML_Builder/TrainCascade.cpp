#include <QApplication>
#include "TrainCascade.h"

TrainCascade::TrainCascade(const QString &str1, const QString &str2, QWidget *parent) : dirName(str1), vec(str2), QWidget(parent)
{
    vec = dirName+"/"+vec;
    int width = 600;
    data = "classifier";
    bg = "";
    numPos = 100; //max. kommt aus vecInfoDatei
    numPosStr.append(QString("%1").arg(numPos));
    numNeg = 100; //max. kommt aus Anzahl der Neg. im Verzeichnis bg
    numNegStr.append(QString("%1").arg(numNeg));
    //nachfolgenden 4 Parameter sind durch vec-file festgelegt
    w = 24;
    h = 24;
    maxPos = 100;
    maxNeg = 100;
    wStr.append(QString("%1").arg(w));
    hStr.append(QString("%1").arg(h));
    numStages = 10; //frei wählbar zwischen 1,...,20
    numStagesStr.append(QString("%1").arg(numNeg));
    featureType = "LBP"; //sonst noch HAAR möglich
    minHitRate = 0.95; //Wert zw. 0 und 1
    minHitRateStr.append(QString("%1").arg(minHitRate));
    maxFalseAlarmRate = 0.5; //Wert zw. 0 und 1
    maxFalseAlarmRateStr.append(QString("%1").arg(maxFalseAlarmRate));

    gridLayout = new QGridLayout(this);
    gridLayout->setAlignment(Qt::AlignCenter );

    infoIOLayoutList[0] = new InfoIOLayout("Eingabedatei:",vec,"Ändern");
    infoIOLayoutList[0]->setMaximumWidth(width);
    infoIOLayoutList[1] = new InfoIOLayout("Ausgabedatei:",data,"Ändern");
    infoIOLayoutList[1]->setMaximumWidth(width);
    infoIOLayoutList[2] = new InfoIOLayout("Negative Bilder:",bg,"Ändern");
    infoIOLayoutList[2]->setMaximumWidth(width);
    infoIOLayoutList[3] = new InfoIOLayout("Anzahl der Positiven:",numPosStr,"Ändern");
    infoIOLayoutList[3]->setMaximumWidth(width);
    infoIOLayoutList[4] = new InfoIOLayout("Anzahl der Negativen:",numNegStr,"Ändern");
    infoIOLayoutList[4]->setMaximumWidth(width);
    infoIOLayoutList[5] = new InfoIOLayout("Anzahl der Stufen:",numStagesStr,"Ändern");
    infoIOLayoutList[5]->setMaximumWidth(width);
    infoIOLayoutList[6] = new InfoIOLayout("FeatureType:",featureType,"Ändern");
    infoIOLayoutList[6]->setMaximumWidth(width);
    infoIOLayoutList[7] = new InfoIOLayout("Min. Erkennungsrate:",minHitRateStr,"Ändern");
    infoIOLayoutList[7]->setMaximumWidth(width);
    infoIOLayoutList[8] = new InfoIOLayout("Max. Falscherkennungsrate:",maxFalseAlarmRateStr,"Ändern");
    infoIOLayoutList[8]->setMaximumWidth(width);
    buttonStart = new QPushButton("Start");


    gridLayout->addWidget(infoIOLayoutList[0],0,0);
    gridLayout->addWidget(infoIOLayoutList[1],1,0);
    gridLayout->addWidget(infoIOLayoutList[2],2,0);
    gridLayout->addWidget(infoIOLayoutList[3],3,0);
    gridLayout->addWidget(infoIOLayoutList[4],4,0);
    gridLayout->addWidget(infoIOLayoutList[5],5,0);
    gridLayout->addWidget(infoIOLayoutList[6],6,0);
    gridLayout->addWidget(infoIOLayoutList[7],7,0);
    gridLayout->addWidget(infoIOLayoutList[8],8,0);
    gridLayout->addWidget(buttonStart,9,0);

    setLayout(gridLayout);

    connect(infoIOLayoutList[0]->button, SIGNAL(clicked()), this, SLOT(changeInputFile()));
    connect(infoIOLayoutList[1]->button, SIGNAL(clicked()), this, SLOT(changeOutputFile()));
    connect(infoIOLayoutList[2]->button, SIGNAL(clicked()), this, SLOT(changeBG()));
    connect(infoIOLayoutList[3]->button, SIGNAL(clicked()), this, SLOT(changeNumPos()));
    connect(infoIOLayoutList[4]->button, SIGNAL(clicked()), this, SLOT(changeNumNeg()));
    connect(infoIOLayoutList[5]->button, SIGNAL(clicked()), this, SLOT(changeNumStages()));
    connect(infoIOLayoutList[6]->button, SIGNAL(clicked()), this, SLOT(changeFeatureType()));
    connect(infoIOLayoutList[7]->button, SIGNAL(clicked()), this, SLOT(changeMinHitRate()));
    connect(infoIOLayoutList[8]->button, SIGNAL(clicked()), this, SLOT(changeMaxFalseAlarmRate()));
    connect(buttonStart, SIGNAL(clicked()), this, SLOT(startTraining()));

    readVecInfo();
}

void TrainCascade::changeInputFile()
{
    QString temp = QFileDialog::getOpenFileName(this,
                                        "Bitte eine Datei wählen",
                                        dirName,
                                        "Dokumente (*.vec)");
    if(!temp.isEmpty())
    {
        vec = temp;
        infoIOLayoutList[0]->setInfotext(vec);
        readVecInfo(); //liest die Informationen zur aktuellen vec Datei ein
    }
}

void TrainCascade::changeOutputFile()
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
        data = temp;
        infoIOLayoutList[1]->setInfotext(data);
    }
}

void TrainCascade::changeBG()
{
    bg = QFileDialog::getOpenFileName(this,
                                      "Bitte eine Datei wählen",
                                      dirName,
                                      "Dokumente (*.txt)");
    infoIOLayoutList[2]->setInfotext(bg);
}

void TrainCascade::changeNumPos()
{
    bool ok = 0;
    int value = QInputDialog::getInt(this,
                                     "Anzahl der Positiven für das Training eingeben",
                                     "Wert eingeben:",
                                     100,100,maxPos,10,
                                     &ok);
    if(ok)
    {
        numPos = value;
        numPosStr = "";
        numPosStr.append(QString("%1").arg(numPos));
        infoIOLayoutList[3]->setInfotext(numPosStr);
    }
}

void TrainCascade::changeNumNeg()
{
    bool ok = 0;
    int value = QInputDialog::getInt(this,
                                     "Anzahl der Positiven für das Training eingeben",
                                     "Wert eingeben:",
                                     100,100,maxNeg,10,
                                     &ok);
    if(ok)
    {
        numNeg = value;
        numNegStr = "";
        numNegStr.append(QString("%1").arg(numNeg));
        infoIOLayoutList[4]->setInfotext(numNegStr);
    }
}

void TrainCascade::changeNumStages()
{
    bool ok = 0;
    int value = QInputDialog::getInt(this,
                                     "Anzahl der Positiven für das Training eingeben",
                                     "Wert eingeben:",
                                     10,1,20,1,
                                     &ok);
    if(ok)
    {
        numStages = value;
        numStagesStr = "";
        numStagesStr.append(QString("%1").arg(numStages));
        infoIOLayoutList[5]->setInfotext(numStagesStr);
    }
}

void TrainCascade::changeFeatureType()
{
    QStringList items;
    items << "LBP" << "HAAR";
    bool ok = 0;
    QString temp = QInputDialog::getItem(this,
                                        "FeatureType eingeben",
                                        "FeatureType:",
                                        items,0,false,
                                        &ok);
    if(ok)
    {
        featureType = temp;
        infoIOLayoutList[6]->setInfotext(featureType);
    }
}

void TrainCascade::changeMinHitRate()
{
    bool ok = 0;
    double value = QInputDialog::getDouble(this,
                                     "Minimale Erkennungsrate eingeben",
                                     "Wert eingeben:",
                                     0.95,0,1,2,
                                     &ok);
    if(ok)
    {
        minHitRate = value;
        minHitRateStr = "";
        minHitRateStr.append(QString("%1").arg(minHitRate));
        infoIOLayoutList[7]->setInfotext(minHitRateStr);
    }
}

void TrainCascade::changeMaxFalseAlarmRate()
{
    bool ok = 0;
    double value = QInputDialog::getDouble(this,
                                     "Maximale Falscherkennungsrate eingeben",
                                     "Wert eingeben:",
                                     0.5,0,1,2,
                                     &ok);
    if(ok)
    {
        maxFalseAlarmRate = value;
        maxFalseAlarmRateStr = "";
        maxFalseAlarmRateStr.append(QString("%1").arg(maxFalseAlarmRate));
        infoIOLayoutList[8]->setInfotext(maxFalseAlarmRateStr);
    }
}

void TrainCascade::startTraining()
{
  //traincascade...
}

void TrainCascade::readVecInfo()
{
//    QString str;
    infoFile.setFileName(vec.remove(vec.length()-4,4)+"_info.txt");
    if(infoFile.open(QIODevice::ReadOnly))
    {
        in.setDevice(&infoFile);
        in >> w;
//        w = atoi(str.toUtf8().constData());
        in >> h;
        in >> maxPos;
    }
    else
    {
        w=h=24;
        maxPos = 155;
    }
}
