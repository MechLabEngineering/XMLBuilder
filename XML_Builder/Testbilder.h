#ifndef TESTBILDER_H
#define TESTBILDER_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Testbilder : public QWidget
{
    Q_OBJECT
public:
    Testbilder(QWidget *parent = 0);

private:
    QLabel *labelInfo;
    QPushButton *button1;
};
#endif // TESTBILDER_H
