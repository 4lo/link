#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "inter.h"
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include "game.h"
#include "button.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QPainter>
#include "drawlinelayer.h"
#include <QMovie>
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void initMap();
    void judge(const QString &msg);
    void drawLine(QString pic1, QString pic2,QString p1, QString p2);
    Game game{};
    DrawLineLayer *drawLineLayer;

    ~MainWindow();   
    Ui::MainWindow *ui;
private:
    QTimer *timer;
    QPainter* painter;
    QGridLayout *grid{};
    QMediaPlayer *player1;
public slots:
        void bossBloodUpdater();
        void myBloodUpdater();
        void returnMain();
        void goldenFinger();
};

#endif // MAINWINDOW_H

/*
0 0 0 0 0 0 0 0 0 0 0 0
0 1 x x x x x x x x x 0
0 0 x x x x x x x x x 0
0 0 0 0 0 0 0 x x x x 0
0 x x x x x 0 x x x x 0
0 x x x x x 0 x x x x 0
0 x x x x x 1 x x x x 0
0 x x x x x x x x x x 0
0 x x x x x x x x x x 0
0 0 0 0 0 0 0 0 0 0 0 0
*/
