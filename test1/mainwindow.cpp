#include "mainwindow.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QDialog(parent)
//    ui(new Ui::MainWindow)
{
    lbl = new QLabel("&Enter directory path");
    dirPath = new QLineEdit;
    lbl->setBuddy(dirPath);

    browse = new QPushButton("&Browse");
    ok = new QPushButton("Ok");
    ok->setDefault(true);
    ok->setEnabled(false);
    quit = new QPushButton("&Quit");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lbl, 1, 1);
    layout->addWidget(dirPath, 1, 2);
    layout->addWidget(browse, 1, 3);
    layout->addWidget(ok, 2, 2);
    layout->addWidget(quit, 2, 3);

    connect(dirPath,SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(browse,SIGNAL(clicked()), this, SLOT(Open()));

    setLayout(layout);

//    ui->setupUi(this);
}

void MainWindow::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());

}

void MainWindow::OkClicked()
{

}

void MainWindow::Open()
{
    QString dirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    if (dirName != "") {
        dirPath->setText(dirName);
    }
}
//MainWindow::~MainWindow()
//{
//    delete ui;
//}
