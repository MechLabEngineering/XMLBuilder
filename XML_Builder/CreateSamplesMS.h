#ifndef CREATESAMPLES_H
#define CREATESAMPLES_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "InfoIOLayout.h"
#include "cvhaartraining.h"

class CreateSamplesMS : public QWidget
{
    Q_OBJECT
public:
    CreateSamplesMS(const QString &str1, const QString &str2, QWidget *parent = 0);
    const QString& getOutputFile() {return vec;}

private slots:
    void changeInputFile();
    void changeOutputFile();
    void changeW();
    void changeH();
    void startCreateSamples();

private:
    QGridLayout *gridLayout;
    InfoIOLayout *infoIOLayoutList[4];
    QString info, vec, wStr, hStr, dirName;
    QPushButton *buttonStart;
    int w, h, maxPos;
    QFile infoFile;
    QTextStream out;
};
    #endif // CREATESAMPLES_H
