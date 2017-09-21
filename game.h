#ifndef GAME_H
#define GAME_H
#include <QString>

class Game
{
public:
    Game();
    int mapOfAll[12][18]{};//可供划线的区域
    int mapOfPicture[10][16]{};//连连看游戏的图片区域
    int pictureNumber{0};
    void getCoordinate(int &x1, int &y1, int &x2, int &y2,QString pic1, QString pic2);
    bool linkWithOneLine(QString pic1, QString pic2, bool isThis);
    bool linkWithTwoLines(QString pic1, QString pic2,QString& p1, bool isThis);
    bool linkWithThreeLines(QString pic1, QString pic2, QString& p1, QString& p2);
    bool isWin();
    bool couldBelinked(int x1, int y1, int x2, int y2);
    QString pictureSelected{""};
    bool oneLine{false},
    twoLines{false},
    threeLines{false};
    float myBlood{100.0};
    int bossBlood{100};
    bool iswin{false};

private:


};

#endif // GAME_H
