#ifndef GAME_H
#define GAME_H
#include <QString>

class Game
{
public:
    Game();
    int map[12][18];
    int rawMap[10][16];//未经打乱的游戏棋盘
    int totalPic = 0;
    bool flagA = false, flagB = false, flagC = false; //转折点数量
    QString getPictureSelected();
    void setPictureSelected(QString newSelected);
    bool linkWithNoCorner(QString pic1, QString pic2);
    bool linkWithOneCorner(QString pic1, QString pic2, QString& pos2);
    bool linkWithTwoCorner(QString pic1, QString pic2, QString& pos2, QString& pos3);
    bool couldBeLinked(QString o1, QString o2);
    bool isWin();
    void getPosition(int &x1, int &y1, int &x2, int & y2, QString pic1, QString pic2);
    bool link(int x1, int y1, int x2, int y2);
private:
    QString pictureSelected;
};

#endif // GAME_H
