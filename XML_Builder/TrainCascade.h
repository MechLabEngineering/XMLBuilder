#ifndef TRAINCASCADE_H
#define TRAINCASCADE_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QInputDialog>
#include "InfoIOLayout.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

class TrainCascade : public QWidget
{
    Q_OBJECT
public:
    TrainCascade(const QString &str1, const QString &str2, QWidget *parent = 0);

private slots:
    void changeInputFile();
    void changeOutputFile();
    void changeBG();
    void changeNumPos();
    void changeNumNeg();
    void changeNumStages();
    void changeFeatureType();
    void changeMinHitRate();
    void changeMaxFalseAlarmRate();
    void startTraining();
private:
    QGridLayout *gridLayout;
    InfoIOLayout *infoIOLayoutList[9];
    QString data, vec, bg, featureType, dirName;
    QString wStr, hStr, numPosStr, numNegStr, numStagesStr, minHitRateStr, maxFalseAlarmRateStr;
    QPushButton *buttonStart;
    int w, h, numPos, numNeg, numStages;
    int maxPos, maxNeg;
    double minHitRate, maxFalseAlarmRate;
    QFile infoFile;
    QTextStream in;

    void readVecInfo();
};
#endif // TRAINCASCADE_H
