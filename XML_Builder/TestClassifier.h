#ifndef TESTCLASSIFIER_H
#define TESTCLASSIFIER_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class TestClassifier : public QWidget
{
    Q_OBJECT
public:
    TestClassifier(QWidget *parent = 0);

private:
    QLabel *labelInfo;
    QPushButton *button1;
};
#endif // TESTCLASSIFIER_H
