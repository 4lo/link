#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "button.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QGridLayout *grid{};
    void initMap();
    void judge(const QString &msg);

    int PIC_NUM{10};
    Game game{};
    ~MainWindow();
public slots:
    void log(button *btn);//debug

private:
    Ui::MainWindow *ui;
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
