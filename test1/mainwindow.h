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
#include <QTableWidget>
#include <QHeaderView>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QLabel *lbl1;
    QLabel *lbl2;
    QLineEdit *dirPath;

    QPushButton *browse;
    QPushButton *ok;
    QPushButton *quit;

    QTableWidget *table;
    QTextEdit *text;

private slots:
    void OkClicked();
    void TextChanged(QString str);
    void Open();
    void fileStat(const QDir& dir, QMap<QString, QPair<qint64, qint32> >& fileGroups);
};

#endif // MAINWINDOW_H
