#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("emoji连连看");
    grid = new QGridLayout(ui->widget);
    drawline = new drawLine(this);
    initMap();
}

void MainWindow::initMap(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            game.rawMap[i][j] = game.totalPic++ % 10 + 1; //初始化未经打乱的棋盘
        }
    }

        srand((int)time(0));
        int randx1, randx2, randy1, randy2;
        //将地图中的图片进行300次随机对调，从而打乱棋盘
        for (int k = 0; k < 300; k++) {
            randx1 = rand() % 10;
            randx2 = rand() % 10;
            randy1 = rand() % 16;
            randy2 = rand() % 16;
            int tmp = game.rawMap[randx1][randy1];
            game.rawMap[randx1][randy1] = game.rawMap[randx2][randy2];
            game.rawMap[randx2][randy2] = tmp;
        }
        int randomPicIndex{0};
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 18; j++) {
                if (i == 0 || i == 11 || j == 0 || j == 17) {
                    button *w = new button();
                    w->setStyleSheet("background:transparent");
                    w->setObjectName(QString::number(i * 18 + j));
                    w->setMinimumSize(40, 40);
                    w->setMaximumSize(40, 40);
                    w->setParent(ui->widget);
                    grid->addWidget(w, i, j);
                    continue;
                }
                randomPicIndex = game.rawMap[i - 1][j - 1];
                button *pic = new button();
                if (randomPicIndex == 0) {
                    pic->setIcon(QIcon("background:transparent"));
                    pic->setObjectName(QString::number(i * 18 + j));
                    pic->setIconSize(QSize(40, 40));
                    pic->setMinimumSize(40, 40);
                    pic->setMaximumSize(40, 40);
                    game.map[i][j] = 0;
                } else {
                    pic->setIcon(QIcon(":/images/" + QString::number(randomPicIndex) + ".png"));
                    pic->setObjectName(QString::number(i * 18 + j));
                    pic->setIconSize(QSize(40, 40));
                    pic->setMinimumSize(40, 40);
                    pic->setMaximumSize(40, 40);
                    pic->setCheckable(true);
                    connect(pic, &button::keyClicked, this, &MainWindow::link);
                    game.map[i][j] = randomPicIndex;
                }
                grid->addWidget(pic, i, j);

            }
        }
}

void MainWindow::linelink(QString pic1, QString pic2, QString p1, QString p2)
{
    button *ptr1 = ui->widget->findChild<button*>(pic1);
    button *ptr2 = ui->widget->findChild<button*>(pic2);

    if (game.flagA){
        drawline->setP(0,ptr1->pos());
        drawline->setP(1,ptr2->pos());
        game.flagA = false;
    }else if (game.flagB){
        drawline->setP(0,ptr1->pos());
        drawline->setP(1,ui->widget->findChild<button*>(p1)->pos());
        drawline->setP(2,ptr2->pos());
    }else if (game.flagC){
        drawline->setP(0,ptr1->pos());
        QWidget *tmp1{}, *tmp2{};
        tmp1 = ui->widget->findChild<QWidget*>(p1);
        tmp2 = ui->widget->findChild<QWidget*>(p2);
        if (tmp1 != nullptr){
            QPoint qp1 = tmp1->pos();
            drawline->setP(1,qp1);
        }
        if (tmp2 != nullptr){
            QPoint qp2 = tmp1->pos();
            drawline->setP(2,qp2);
        }

    }
}

void MainWindow::link(const QString &msg){
    QString po1{},po2{};
//    if(linkalgorithm.link(msg,game)){
      //  button *btn = ui->widget->findChild<button*>(msg);
       // drawLine(game.pictureSelected,btn->objectName(),po1,po2);
   // }
}

MainWindow::~MainWindow()
{
    delete ui;
}
