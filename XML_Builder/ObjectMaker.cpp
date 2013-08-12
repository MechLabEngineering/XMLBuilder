#include <QApplication>
#include <QFileDialog>
#include <QInputDialog>
#include "ObjectMaker.h"
#include "InfoIOLayout.h"

ObjectMaker::ObjectMaker(QString &str, QWidget *parent)
    : QWidget(parent), projectName(str)
{
    i = 0;
    inputDir = projectName+"/Testbilder";
    outputFile = "untitled.txt";

    dir = new QDir(inputDir);
    filters = new QStringList;
    *filters << "*.png" << "*.jpg" << "*.bmp" << "*.gif";
    dir->setNameFilters(*filters);
    dir->setFilter(QDir::Files);
    fileList = dir->entryList();

    gridLayout = new QGridLayout(this);
    gridLayout->setAlignment(Qt::AlignCenter );
    infoIOLayoutList[0] = new InfoIOLayout("Verzeichnispfad:",inputDir,"Pfad ändern");
    infoIOLayoutList[1] = new InfoIOLayout("Ausgabedatei:",outputFile,"Dateiname ändern");
    drawArea = new DrawOnImageLayout(this);
    drawArea->setMinimumSize(drawArea->getImageWidth(),drawArea->getImageHeight());
    drawArea->setMaximumSize(600,400);
    buttonStart = new QPushButton("Start",this);

    buttonStop = new QPushButton("Stop",this);
    buttonStop->setEnabled(false);
    button1 = new QPushButton("Bestätigen",this);
    button1->setEnabled(false);
    button2 = new QPushButton("Weiter",this);
    button2->setEnabled(false);

    gridLayout->addWidget(infoIOLayoutList[0],0,0,1,2);
    gridLayout->addWidget(infoIOLayoutList[1],1,0,1,2);
    gridLayout->addWidget(buttonStart,2,0);
    gridLayout->addWidget(buttonStop,2,1);
    //gridLayout->setRowStretch(3,drawArea->getImageHeight());
    gridLayout->addWidget(drawArea,3,0,3,2);
    gridLayout->setAlignment(drawArea,Qt::AlignHCenter);
    gridLayout->addWidget(button1,6,0);
    gridLayout->addWidget(button2,6,1);

    setLayout(gridLayout);

    connect(infoIOLayoutList[0]->button, SIGNAL(clicked()), this, SLOT(changeInputDir()));
    connect(infoIOLayoutList[1]->button, SIGNAL(clicked()), this, SLOT(changeOutputFile()));
    connect(button1, SIGNAL(clicked()), this, SLOT(saveImageArea()));
    connect(button2, SIGNAL(clicked()), this, SLOT(nextImage()));
    connect(buttonStart, SIGNAL(clicked()), this, SLOT(startObjMaker()));
    connect(buttonStop, SIGNAL(clicked()), this, SLOT(stopObjMaker()));
}

void ObjectMaker::changeInputDir()
{
    QString temp;
    temp = QFileDialog::getExistingDirectory(this,
                                             "Bitte ein Verzeichnis auswählen, indem die Testbilder liegen.",
                                             QDir::homePath());
    if(!temp.isEmpty())
    {
        inputDir = temp;
        infoIOLayoutList[0]->setInfotext(inputDir);
        dir->setPath(inputDir);
        fileList = dir->entryList();
        i=0;
    }

}

void ObjectMaker::changeOutputFile()
{
    bool ok = 0;
    QString temp = QInputDialog::getText(this,
                                        "Ausgabedatei eingeben",
                                        "Name der Ausgabedatei:",
                                        QLineEdit::Normal,
                                        "Untitled",
                                        &ok);
    if(ok && !temp.isEmpty())
    {
        outputFile = temp+".txt";
        infoIOLayoutList[1]->setInfotext(outputFile);
    }
}

void ObjectMaker::nextImage()
{
    if(i < fileList.length())
    {
        drawArea->setImage(inputDir+"/"+fileList[i]);
        drawArea->setMinimumSize(drawArea->getImageWidth(),drawArea->getImageHeight());
        drawArea->setMaximumSize(drawArea->getImageWidth(),drawArea->getImageHeight());
        i++;
    }
    else
    {
        stopObjMaker();
        i=0;
    }
}

void ObjectMaker::saveImageArea()
{
    if(drawArea->getRoiWidth() >= 0 && drawArea->getRoiHeight() >= 0)
        out << inputDir+"/"+fileList[i]+" 1 " << drawArea->getRoiX() <<" "
            << drawArea->getRoiY() <<" "<< drawArea->getRoiWidth() <<" "<< drawArea->getRoiHeight() << endl;
}

void ObjectMaker::startObjMaker()
{
    //Ausgabedatei anlegen und prüfen, ob diese bereits existert
    bool statusVar = false;
    if(data.exists(projectName+"/"+outputFile))
    {
        QMessageBox msg(QMessageBox::Warning, "Warnung vor dem Überschreiben der Ausgabedatei",
                        "Die Ausgabedatei "+outputFile+" existiert bereits. Möchten sie diese Datei überschreiben?");
        QPushButton *yes = msg.addButton("Ja", QMessageBox::YesRole);
        QPushButton *no = msg.addButton("Nein", QMessageBox::NoRole);

        msg.exec();
        if(msg.clickedButton() == yes)
            statusVar = true;
        if(msg.clickedButton() == no)
            statusVar = false;
    }
    if(!data.exists(projectName+"/"+outputFile) || statusVar)
    {
        data.setFileName(projectName+"/"+outputFile);
        if(data.open(QFile::WriteOnly | QFile::Truncate | QFile::Text))
        {
            out.setDevice(&data);
        }
        else
        {
            //Ausgabedatei konnte nicht angelegt werden.
            QMessageBox::information(this, "Fehler beim Öffnen der Ausgabedatei: ",outputFile, QMessageBox::Ok);
        }
        button1->setEnabled(true);
        button2->setEnabled(true);
        buttonStop->setEnabled(true);
        buttonStart->setEnabled(false);
        infoIOLayoutList[0]->button->setEnabled(false);
        infoIOLayoutList[1]->button->setEnabled(false);
    }
}

void ObjectMaker::stopObjMaker()
{
    button1->setEnabled(false);
    button2->setEnabled(false);
    buttonStop->setEnabled(false);
    buttonStart->setEnabled(true);
    infoIOLayoutList[0]->button->setEnabled(true);
    infoIOLayoutList[1]->button->setEnabled(true);
    //save areaFile
}
