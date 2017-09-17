#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "button.h"
#include "linkalgorithm.h"
#include "drawline.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QGridLayout *grid;
    void initMap();
    int PIC_NUM{10};
    Game game;
    QPainter* painter;
    drawLine *drawline;
//    linkAlgorithm linkalgorithm;
    void linelink(QString pic1, QString pic2, QString p1, QString p2);
    void link(const QString &msg);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
