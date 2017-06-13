#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
//    ~MainWindow();

private:
    QLabel *lbl;
    QLineEdit *dirPath;

    QPushButton *browse;
    QPushButton *ok;
    QPushButton *quit;

private slots:
    void OkClicked();
    void TextChanged(QString str);
    void Open();
};

#endif // MAINWINDOW_H
