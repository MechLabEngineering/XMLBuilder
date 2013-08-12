#ifndef OBJECTMAKER_H
#define OBJECTMAKER_H
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include "InfoIOLayout.h"
#include "DrawOnImageLayout.h"

class ObjectMaker : public QWidget
{
    Q_OBJECT
public:
    ObjectMaker(QString &str, QWidget *parent = 0);
    const QString& getOutputFile() {return outputFile;}

private slots:
    void changeInputDir();
    void changeOutputFile();
    void nextImage();
    void saveImageArea();
    void startObjMaker();
    void stopObjMaker();

private:
    QString projectName;
    QGridLayout *gridLayout;
    QString inputDir, outputFile;
    InfoIOLayout *infoIOLayoutList[2];
    DrawOnImageLayout *drawArea;
    QPushButton *buttonStart, *buttonStop, *button1, *button2;
    QStringList *filters, fileList;
    QDir *dir;
    QFile data;
    QTextStream out;
    int i;
};
#endif // OBJECTMAKER_H
