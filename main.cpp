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
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/music/bgm.mp3"));
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    QMediaPlayer *player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(100);
    player->play();

    w.setWindowTitle("连连看");
    w.show();

    return a.exec();
}
