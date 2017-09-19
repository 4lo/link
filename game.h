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

    bool noOtherPic(char same,int n,int n1,int n2);
    void getCoordinate(int &x1, int &y1, int &x2, int &y2,QString pic1, QString pic2);
    bool linkWithOneLine(QString pic1, QString pic2, bool isThis);
    bool linkWithTwoLines(QString pic1, QString pic2, bool isThis);
    bool linkWithThreeLines(QString pic1, QString pic2);
    bool isWin();
    QString pictureSelected{""};
private:

};

#endif // GAME_H
