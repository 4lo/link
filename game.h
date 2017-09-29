#ifndef GAME_H
#define GAME_H
#include <QString>

class Game
{
public:
    Game();

    //可供划线的区域
    int mapOfAll[12][18]{};

    //连连看游戏的图片区域
    int mapOfPicture[10][16]{};

    //用于计数
    int pictureNumber{0};

    //连连看的算法整体
    void getCoordinate(int &x1, int &y1, int &x2, int &y2,QString pic1, QString pic2);
    bool couldBelinked(int x1, int y1, int x2, int y2);
    bool linkWithOneLine(QString pic1, QString pic2, bool isThis);
    bool linkWithTwoLines(QString pic1, QString pic2,QString& p1, bool isThis);
    bool linkWithThreeLines(QString pic1, QString pic2, QString& p1, QString& p2);
    bool isWin();

    QString pictureSelected{""};
    bool oneLine{false},
    twoLines{false},
    threeLines{false};

    //初始化血量，由于qt中
    float myBlood{100.0};
    int bossBlood{100};

    //胜利的布尔记录
    bool iswin{false};
};

#endif // GAME_H
