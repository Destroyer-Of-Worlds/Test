#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QLabel *lbl;
    QLineEdit *dirPath;

    QPushButton *browse;
    QPushButton *ok;
    QPushButton *quit;

    QTextEdit *text;
private slots:
    void OkClicked();
    void TextChanged(QString str);
    void Open();
    void start(const QDir& dir);
};

#endif // MAINWINDOW_H
