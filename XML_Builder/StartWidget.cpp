#include "StartWidget.h"
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QInputDialog>

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
{
    QMessageBox msg(QMessageBox::Information, "XML Builder Start", "Was wollen Sie tun?");
    QPushButton *newProjectButton = msg.addButton("New Project", QMessageBox::YesRole);
    QPushButton *openProjectButton = msg.addButton("Open Project", QMessageBox::NoRole);
    QPushButton *closeButton = msg.addButton("Close", QMessageBox::RejectRole);
    msg.exec();
    if(msg.clickedButton() == newProjectButton)
    {
        dirName = QFileDialog::getExistingDirectory(this,
                                                    "Bitte ein Verzeichnis auswählen, indem das Projekt angelegt werden soll.",
                                                    QDir::currentPath());
        if(!dirName.isEmpty())
        {
            bool ok = 0;
            projectName = QInputDialog::getText(this,
                                                "Projektnamen eingeben",
                                                "Name des Projekts:",
                                                QLineEdit::Normal,
                                                "Untitled",
                                                &ok);
            if(ok && !projectName.isEmpty())
            {
                projectName = dirName + "/" + projectName;
                QDir *tempProjectDirectory = new QDir(projectName);
                int i=0;
                while(tempProjectDirectory->exists())
                {
                    i++;
                    delete tempProjectDirectory;
                    QString tempProjectName = projectName;
                    tempProjectName.append(QString("%1").arg(i));
                    QDir *tempProjectDirectory = new QDir(tempProjectName);
                }
                if(i>0)
                    projectName.append(QString("%1").arg(i));
                QMessageBox::information(this, "Projektname: ",projectName, QMessageBox::Ok);
                projectDirectory = new QDir(dirName);
                projectDirectory->mkdir(projectName);//neuen Projektordner anlegen
                projectDirectory->cd(projectName);
                projectDirectory->mkdir(projectName+"/Testbilder");
            }
            else
                projectName = "";
        }
    }
    if(msg.clickedButton() == openProjectButton)
    {
        projectName = QFileDialog::getExistingDirectory(this,
                                                        "Projektverzeichnis auswählen",
                                                        QDir::currentPath());
        if(!projectName.isEmpty())
        {
            QMessageBox::information(this, "Projektname: ",projectName, QMessageBox::Ok);
        }
    }
    if(msg.clickedButton() == closeButton)
        exit(1);
}
