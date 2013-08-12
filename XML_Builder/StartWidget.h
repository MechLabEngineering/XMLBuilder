#ifndef STARTWIDGET_H
#define STARTWIDGET_H
#include <QWidget>
#include <QMessageBox>
#include <QObject>
#include <QDir>

class StartWidget : public QWidget
{
    Q_OBJECT
public:
    StartWidget(QWidget *parent = 0);
    QString getProjectName() {return projectName;}
private:
    int res;
    QString dirName, projectName;
    QDir *projectDirectory;
};

#endif // STARTWIDGET_H
