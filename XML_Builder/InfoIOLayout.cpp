#include <QApplication>
#include "InfoIOLayout.h"

InfoIOLayout::InfoIOLayout(const QString& str1 ,const QString& str2, const QString& str3, QWidget *parent)
    : QWidget(parent)
{
    gridLayout = new QGridLayout(this);
    labelInfo = new QLabel("<b>"+str1+"</b>",this);
    label = new QLabel(str2,this);
    label->setWordWrap(true);
    button = new QPushButton(str3,this);
    gridLayout->addWidget(labelInfo,0,0);
    gridLayout->addWidget(label,0,1);
    gridLayout->addWidget(button,0,2);
    gridLayout->setColumnStretch(0,200);
    gridLayout->setColumnStretch(1,300);
    gridLayout->setColumnStretch(2,100);
}

void InfoIOLayout::setInfotext(const QString& str)
{
    label->setText(str);
}

