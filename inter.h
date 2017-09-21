#ifndef inter_H
#define inter_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QMovie>
#include <QLabel>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class inter;
}

class inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit inter(QWidget *parent = 0);
    ~inter();
private:

    QMovie* movie;
    Ui::inter *ui;

public slots:
    void startGame();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // inter_H
