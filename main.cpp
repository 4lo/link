#include "mainwindow.h"
#include "inter.h"
#include <QString>
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inter w;
    //播放音乐
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/music/bgm.mp3"));
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    QMediaPlayer *player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(100);
    player->play();

    w.setWindowTitle("连连看");
    //进行开始界面
    w.show();

    return a.exec();
}
