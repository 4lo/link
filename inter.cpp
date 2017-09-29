
#include "inter.h"
#include "ui_inter.h"
float mySpeed;//玩家血量的变化速度
int bossSpeed;//boss血量的变化速度
QString path;//用于存储路径以区分level关卡
inter::inter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inter)
{
    ui->setupUi(this);

    //设置界面标题隐藏
    setWindowFlags(Qt::FramelessWindowHint);

    //加载动态图背景
    QMovie *movie = new QMovie(":/characters/3.gif");
    //QMovie *startButton = new QMovie(":/characters/2.gif");

    //连连看字样
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


    //将inter.ui中的退出按钮绑定信号事件（退出，即关闭）
    connect(ui->quit,SIGNAL(clicked(bool)),this,SLOT(close()));
    //connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(startGame()));


}

inter::~inter()
{
    delete ui;
}
//开始游戏函数________已过期
void inter::startGame(){
    MainWindow *mWin = new MainWindow();
    mWin->setWindowTitle("连连看");
    mWin->show();
    this->hide();

}

//关卡1
void inter::on_pushButton_clicked(){
    path = "level1/";
    mySpeed = 1;
    bossSpeed = 10;
    MainWindow *mWin = new MainWindow();
    mWin->setWindowTitle("连连看");
    mWin->show();
    this->hide();
}
//关卡2
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

//关卡3
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
