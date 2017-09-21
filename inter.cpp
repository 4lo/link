
#include "inter.h"
#include "ui_inter.h"
float mySpeed;
int bossSpeed;
QString path;
inter::inter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inter)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QMovie *movie = new QMovie(":/characters/3.gif");
    //QMovie *startButton = new QMovie(":/characters/2.gif");
    QMovie *lian = new QMovie(":/characters/lian.png");
    QMovie *kan = new QMovie(":/characters/kan.png");
    ui->label->setMovie(movie);
    ui->label->setScaledContents(true);
    ui->label->resize(ui->widget->size());
    movie->start();
    //ui->pushButton->setMovie(startButton);
    //ui->pushButton->setScaledContents(true);
   // ui->pushButton->resize(ui->widget_2->size());
   // startButton->start();
    ui->l1->setMovie(lian);
    ui->l1->setScaledContents(true);
    ui->l1->resize(ui->lian1->size());
    ui->l2->setMovie(lian);
    ui->l2->setScaledContents(true);
    ui->l2->resize(ui->lian2->size());
    ui->k->setMovie(kan);
    ui->k->setScaledContents(true);
    ui->k->resize(ui->kan->size());
    lian->start();
    kan->start();
    //connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(startGame()));


}

inter::~inter()
{
    delete ui;
}
void inter::startGame(){
    MainWindow *mWin = new MainWindow();
    mWin->setWindowTitle("连连看");
    mWin->show();
    this->hide();

}

void inter::on_pushButton_clicked(){
    path = "level1/";
    mySpeed = 10;
    bossSpeed = 10;
    MainWindow *mWin = new MainWindow();
    mWin->setWindowTitle("连连看");
    mWin->show();
    this->hide();
}

void inter::on_pushButton_2_clicked()
{
    path = "level2/";
    mySpeed = 1;
    bossSpeed = 5;
    MainWindow *mWin = new MainWindow();
    mWin->setWindowTitle("连连看");
    mWin->show();
    this->hide();

}

void inter::on_pushButton_3_clicked()
{
    path = "level3/";
    mySpeed = 1;
    bossSpeed = 2;
    MainWindow *mWin = new MainWindow();
    mWin->setWindowTitle("连连看");
    mWin->show();
    this->hide();

}
