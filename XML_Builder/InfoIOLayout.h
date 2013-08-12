#ifndef INFOIOLAYOUT_H
#define INFOIOLAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class InfoIOLayout : public QWidget
{
    Q_OBJECT
public:
    InfoIOLayout(const QString &str1, const QString &str2, const QString &str3, QWidget *parent = 0);
    void setInfotext(const QString &str);

     QPushButton *button;

private:
    QLabel *labelInfo;
    QLabel *label;
    QGridLayout *gridLayout;
};

#endif // INFOIOLAYOUT_H
