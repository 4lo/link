#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QTimer>
#include <QMediaPlayer>

//重载QPushButton
class button : public QPushButton{
    Q_OBJECT
public:
    explicit button(QWidget *parent = 0) : QPushButton(parent),
        pauseMsecs(400), intervalMsecs(30){
        tm = new QTimer(this);
        //将点击转变为按下状态，来实现练练看的选中状态
        connect(this, SIGNAL(clicked(bool)), this, SLOT(on_clicked()));
    }
private:
    QTimer *tm;
    long pauseMsecs;
    long intervalMsecs;
signals:
    void keyClicked(const QString &msg);
public slots:
    void on_clicked(){
        //按下的同时记录下按下图片的ID（用于连接算法中是否为同一张图片）
        emit this->keyClicked(this->objectName());

        //播放音乐
        QMediaPlayer *player = new QMediaPlayer(this);
        player->setMedia(QUrl("qrc:/music/click.mp3"));
        player->setVolume(100);
        player->play();
    }

};


#endif // BUTTON_H
