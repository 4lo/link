#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("emoji连连看");
    grid = new QGridLayout(ui->widget);
    initMap();
}

void MainWindow::initMap(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            game.mapOfPicture[i][j] = game.pictureNumber++ % 10 + 1; //初始化未经打乱的棋盘
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
            int tmp = game.mapOfPicture[randx1][randy1];
            game.mapOfPicture[randx1][randy1] = game.mapOfPicture[randx2][randy2];
            game.mapOfPicture[randx2][randy2] = tmp;
        }
        int randomPicIndex{0};
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 18; j++) {
                if (i == 0 || i == 11 || j == 0 || j == 17) {
                    button *w = new button();
                    w->setStyleSheet("background:transparent");
                    w->setObjectName(QString::number(/*i * 18 + j*/ 0 ));
                    w->setMinimumSize(40, 40);
                    w->setMaximumSize(40, 40);
                    w->setParent(ui->widget);
                    grid->addWidget(w, i, j);
                    continue;
                }
                randomPicIndex = game.mapOfPicture[i - 1][j - 1];
                button *pic = new button();
                if (randomPicIndex == 0) {
                    pic->setIcon(QIcon("background:transparent"));
                    pic->setObjectName(QString::number(i * 18 + j));
                    pic->setIconSize(QSize(40, 40));
                    pic->setMinimumSize(40, 40);
                    pic->setMaximumSize(40, 40);
                    game.mapOfAll[i][j] = 0;
                } else {
                    pic->setIcon(QIcon(":/images/" + QString::number(randomPicIndex) + ".png"));
                    pic->setObjectName(QString::number(i * 18 + j));
                    pic->setIconSize(QSize(40, 40));
                    pic->setMinimumSize(40, 40);
                    pic->setMaximumSize(40, 40);
                    pic->setCheckable(true);
                    connect(pic, &button::keyClicked, this, &MainWindow::judge);
                    game.mapOfAll[i][j] = randomPicIndex;
                }
                grid->addWidget(pic, i, j);

            }
        }
}

void MainWindow::judge(const QString &msg){
    button *btn = ui->widget->findChild<button*>(msg);
    if (btn != nullptr){
        if (game.pictureSelected == btn->objectName()){
            //若连续点击同一张图片
            btn->setChecked(false);
            game.pictureSelected = "";
        }else if (game.pictureSelected == ""){
            //此次未点击图片
            game.pictureSelected = btn->objectName();
        }else if (game.linkWithOneLine(game.pictureSelected,btn->objectName(),true)
                  ||game.linkWithTwoLines(game.pictureSelected,btn->objectName(),true)
                  || game.linkWithThreeLines(game.pictureSelected,btn->objectName())){
            //可以连接
            button *b1 = ui->widget->findChild<button*>(game.pictureSelected);
            button *b2 = ui->widget->findChild<button*>(btn->objectName());
            b1->setVisible(false);
            b2->setVisible(false);
            b1->setStyleSheet("background:transparent");
            b2->setStyleSheet("background:transparent");
            game.pictureSelected = "";
        }else{
            button *b1 = ui->widget->findChild<button*>(game.pictureSelected);
            b1->setChecked(false);
            game.pictureSelected = btn->objectName();
            btn->setChecked(true);
        }
    }
}

void MainWindow::log(button *btn){
    qDebug() << game.pictureSelected;
    qDebug() << btn->objectName();
}

MainWindow::~MainWindow()
{
    delete ui;
}
