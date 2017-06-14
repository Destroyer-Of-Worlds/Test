#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent)
{

    lbl = new QLabel("&Enter directory path");
    dirPath = new QLineEdit;
    lbl->setBuddy(dirPath);

    browse = new QPushButton("&Browse");
    ok = new QPushButton("&Ok");
    ok->setDefault(true);
    ok->setEnabled(false);
    quit = new QPushButton("&Quit");

    text = new QTextEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lbl, 1, 1);
    layout->addWidget(dirPath, 1, 2, 1,3);
    layout->addWidget(browse, 1, 5);
    layout->addWidget(ok, 2, 5);
    layout->addWidget(quit, 9, 5);
    layout->addWidget(text,1,6, 9, 9);


    connect(dirPath,SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(browse,SIGNAL(clicked()), this, SLOT(Open()));
    connect(ok,SIGNAL(clicked()),this, SLOT(OkClicked()));

    setLayout(layout);

}


void MainWindow::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());

}

void MainWindow::start(const QDir& dir)
{
    QFileInfoList list = dir.entryInfoList();
    foreach(QFileInfo file, list){
        if (file.isFile()){
            QMap<QString, QPair<qint64, qint32> > fileGroups;
            //fileGroups[file.fileName().split('.').takeLast()]=qMakePair(file.size(),1);
            text->append(file.fileName().split('.').takeLast()+" "+QString::number(file.size()/1024)+"Kb");
        }
        else if(file.isDir()){
            if (file.fileName()=="."||file.fileName()=="..")
                continue;
            start(QDir(file.absoluteFilePath()));
        }
    }
}

void MainWindow::OkClicked()
{
    QDir *dir = new QDir(dirPath->text());
    if(! dir->exists()){
        QMessageBox::critical(this, tr("Error"), tr("Could not open directory"));
        return;
    }
    else{
        start(QDir(dirPath->text()));
//        foreach (QFileInfo file, listFiles) {
//                text->append(file.fileName()+" "+QString::number(file.size()/1024)+"Kb");
//            }

    }

}



void MainWindow::Open()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    if (dirName != "") {
        dirPath->setText(dirName);
    }
}
