#include "mainwindow.h"
#include "ui_mainwindow.h"
extern QString path;
extern float mySpeed;
extern int bossSpeed;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString path1 = ":/images/";
    path1.append(path);
    ui->setupUi(this);
    ui->bossblood->setValue(game.bossBlood);
    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowTitle("连连看");
    grid = new QGridLayout(ui->widget);
    timer = new QTimer(this);
    timer->start(2000);
    painter = new QPainter(this);
    drawLineLayer = new DrawLineLayer(this);
    drawLineLayer->hide();
    drawLineLayer->setGeometry(QRect(0, 0, 720, 480));
    QMovie *movie = new QMovie(":/images/" + path + "me1.gif");
    QMovie *rw2 = new QMovie(path1 + "boss1.gif");
    ui->rw->setMovie(movie);
    ui->rw->setScaledContents(true);
    ui->rw->resize(ui->widget_2->size());
    ui->rw_2->setMovie(rw2);
    ui->rw_2->setScaledContents(true);
    ui->rw_2->resize(ui->widget_3->size());
    rw2->start();
    movie->start();
    ui->myblood->setValue(game.myBlood);
    initMap();
    connect(ui->quit,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->restart,SIGNAL(clicked(bool)),this,SLOT(returnMain()));
    connect(timer,SIGNAL(timeout()),this,SLOT(myBloodUpdater()));
    connect(ui->goldenfinger,SIGNAL(clicked(bool)),this,SLOT(goldenFinger()));
    connect(ui->goldenfinger,SIGNAL(clicked(bool)),this,SLOT(bossBloodUpdater()));
    if (game.myBlood == 0 || game.iswin == true){
        delete movie;
    }

}

void MainWindow::initMap(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {//16*10
            game.mapOfPicture[i][j] = game.pictureNumber++ % 20 + 1; //初始化未经打乱的棋盘
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
                    w->setObjectName(QString::number(i * 18 + j));//0
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

                    QString path1 = ":/images/";
                    path1.append(path);
                    pic->setIcon(QIcon(path1 +  QString::number(randomPicIndex) + ".png"));
                    pic->setObjectName(QString::number(i * 18 + j));
                    pic->setIconSize(QSize(40, 40));
                    pic->setMinimumSize(40, 40);
                    pic->setMaximumSize(40, 40);
                    pic->setCheckable(true);
                    connect(pic, &button::keyClicked, this, &MainWindow::judge);
                    connect(pic, &button::keyClicked, this, &MainWindow::bossBloodUpdater);
                    game.mapOfAll[i][j] = randomPicIndex;
                }
                grid->addWidget(pic, i, j);

            }
        }
}

void MainWindow::judge(const QString &msg){
    button *btn = ui->widget->findChild<button*>(msg);
    QString p1,p2;
    if (btn != nullptr){
        if (game.pictureSelected == btn->objectName()){
            //若连续点击同一张图片
            btn->setChecked(false);
            game.pictureSelected = "";
        }else if (game.pictureSelected == ""){
            //此次未点击图片
            game.pictureSelected = btn->objectName();
        }else if (game.linkWithOneLine(game.pictureSelected,btn->objectName(),true)
                  ||game.linkWithTwoLines(game.pictureSelected,btn->objectName(),p1,true)
                  || game.linkWithThreeLines(game.pictureSelected,btn->objectName(),p1,p2)){
            //可以连接

            game.bossBlood -= bossSpeed;
            game.myBlood += mySpeed;

            QMediaPlayer *player1 = new QMediaPlayer(this);
            player1->setMedia(QUrl("qrc:/music/linkandblink.mp3"));
            player1->setVolume(100);
            player1->play();
            drawLine(game.pictureSelected,btn->objectName(),p1,p2);
            button *b1 = ui->widget->findChild<button*>(game.pictureSelected);
            button *b2 = ui->widget->findChild<button*>(btn->objectName());
            b1->setVisible(false);
            b2->setVisible(false);
            b1->setStyleSheet("background:transparent");
            b2->setStyleSheet("background:transparent");
            game.pictureSelected = "";
            QMovie *movie = new QMovie(":/images/"+ path + "me2.gif");
            QMovie *movie2 = new QMovie(":/images/" + path +"me1.gif");
            ui->rw->setMovie(movie);
            ui->rw->setScaledContents(true);
            ui->rw->resize(ui->widget_2->size());
            movie->start();
            QTime t;
            t.start();
            while(t.elapsed()<2000) //连线延迟2s
                QCoreApplication::processEvents();
            delete movie;

            ui->rw->setMovie(movie2);
            ui->rw->setScaledContents(true);
            ui->rw->resize(ui->widget_2->size());
            movie2->start();


            if(game.bossBlood == 0){
                QMessageBox *box = new QMessageBox(this);
                box->setInformativeText("Congratulations！");
                box->show();
                timer->stop();
                QMovie *win = new QMovie(":/images/win.gif");
                ui->lose->setMovie(win);
                ui->lose->setScaledContents(true);
                ui->lose->resize(ui->widget_4->size());
                win->start();
                QTime t;
                t.start();
                while(t.elapsed()<2000) //连线延迟2s
                    QCoreApplication::processEvents();
                game.iswin = true;
                returnMain();
            }
        }else{
            button *b1 = ui->widget->findChild<button*>(game.pictureSelected);
            b1->setChecked(false);
            game.pictureSelected = btn->objectName();
            btn->setChecked(true);
        }
    }
}

void MainWindow::drawLine(QString pic1, QString pic2, QString pos2,QString pos3){
    button *p1 = ui->widget->findChild<button*>(pic1);
    button *p2 = ui->widget->findChild<button*>(pic2);
    if (game.oneLine) { //没有转折点
        drawLineLayer->setPos1(p1->pos());
        drawLineLayer->setPos2(p2->pos());
        game.oneLine = false;
    } else if (game.twoLines) {
        drawLineLayer->setPos1(p1->pos());
        drawLineLayer->setPos2(ui->widget->findChild<button*>(pos2)->pos());
        drawLineLayer->setPos3(p2->pos());
        game.twoLines = false;
    } else if (game.threeLines) {
        drawLineLayer->setPos1(p1->pos());
        QWidget *tmpP1;
        QWidget *tmpP2;
        tmpP1 = ui->widget->findChild<QWidget*>(pos2);
        tmpP2 = ui->widget->findChild<QWidget*>(pos3);
        if (tmpP1 != nullptr) {
            drawLineLayer->setPos2(tmpP1->pos());
        }
        if (tmpP2 != nullptr) {
            drawLineLayer->setPos3(tmpP2->pos());
        }
        QPoint pp4 = p2->pos();
        drawLineLayer->setPos4(pp4);
        game.threeLines = false;
    }
    drawLineLayer->show();
    QTime t;
    t.start();
    while(t.elapsed()<200) //连线延迟0.2s
        QCoreApplication::processEvents();
    drawLineLayer->clear();
}

void MainWindow::bossBloodUpdater(){

    ui->bossblood->setValue(game.bossBlood);

}

void MainWindow::returnMain()
{
    inter *newwin = new inter();
    newwin->setWindowTitle("连连看");
    newwin->show();
    this->hide();
}

void MainWindow::goldenFinger(){
    QString pos2, pos3;
    QString pic1, pic2;
    bool success = false;
    for (int i = 0; i < 216 && !success; i++) {
        for (int j = 0; j < 216 && !success && j!=i; j++) {
            if (i % 18 == 0 || i % 18 == 17 || i<18 || i>=198 || j % 18 == 0 || j % 18 == 17 || j<18 || j>=198)
                continue;
            pic1 = QString::number(i);
            pic2 = QString::number(j);



            if (game.linkWithOneLine(pic1, pic2,true)
                               || game.linkWithTwoLines(pic1, pic2, pos2,true)
                               || game.linkWithThreeLines(pic1, pic2, pos2, pos3)) {//可消去
                drawLine(pic1, pic2, pos2, pos3);

                success = true;
                game.bossBlood -= bossSpeed;
                button *b1 = ui->widget->findChild<button*>(pic1);
                button *b2 = ui->widget->findChild<button*>(pic2);
                b1->setVisible(false);
                b2->setVisible(false);
                b1->setStyleSheet("background:transparent");
                b2->setStyleSheet("background:transparent");

            }

        }
        if(game.bossBlood == 0){
            ui->bossblood->setValue(game.bossBlood);
            QMessageBox *box = new QMessageBox(this);
            box->setInformativeText("Congratulations！");
            box->show();
            timer->stop();
            QMovie *win = new QMovie(":/images/win.gif");
            ui->lose->setMovie(win);
            ui->lose->setScaledContents(true);
            ui->lose->resize(ui->widget_4->size());
            win->start();
            QTime t;
            t.start();
            while(t.elapsed()<2000) //连线延迟2s
                QCoreApplication::processEvents();
            game.iswin = true;
            returnMain();
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete drawLineLayer;
    delete painter;
    delete timer;
    delete player1;
    delete grid;
}


void MainWindow::myBloodUpdater(){
    if(game.bossBlood != 0)
        game.myBlood -= mySpeed;
    ui->myblood->setValue(game.myBlood);
    if(game.myBlood == 0 && !game.iswin){
        QMessageBox *box = new QMessageBox(this);
        box->setInformativeText("Lose！");
        box->show();
        timer->stop();
        QMovie *lose = new QMovie(":/images/lose.png");
        ui->lose->setMovie(lose);
        ui->lose->setScaledContents(true);
        ui->lose->resize(ui->widget_4->size());
        lose->start();
        QTime t;
        t.start();
        while(t.elapsed()<2000) //连线延迟2s
            QCoreApplication::processEvents();

        returnMain();
    }
}


