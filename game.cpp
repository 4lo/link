#include "game.h"

Game::Game(){
//初始化整体游戏操作区域
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 18; j++)
            mapOfAll[i][j] = 0;
}


void Game::getCoordinate(int &x1, int &y1, int &x2, int &y2, QString pic1, QString pic2){
    x1 = pic1.toInt() / 18;
    x2 = pic2.toInt() / 18;
    y1 = pic1.toInt() % 18;
    y2 = pic2.toInt() % 18;
}

bool Game::linkWithOneLine(QString pic1, QString pic2, bool isThis){
    bool result{false};
    int x1{},x2{},y1{},y2{};
    getCoordinate(x1,y1,x2,y2,pic1,pic2);
    result = couldBelinked(x1,y1,x2,y2);
    if (result && isThis){
        mapOfAll[x1][y1] = 0;
        mapOfAll[x2][y2] = 0;
        pictureNumber -= 2;
        oneLine = true;
    }
    return result;
}

bool Game::linkWithTwoLines(QString pic1, QString pic2,QString& p1,bool isThis){
    bool result{false};
    int x1{},x2{},y1{},y2{};
    getCoordinate(x1,y1,x2,y2,pic1,pic2);
    if (x1 == x2 || y1 == y2)
        return false;
    if (mapOfAll[x1][y1] != mapOfAll[x2][y2] && isThis)
        return false;
    if (mapOfAll[x1][y2] == 0){
        mapOfAll[x1][y2] = mapOfAll[x1][y1];
        if (couldBelinked(x1,y1,x1,y2) && couldBelinked(x2,y2,x1,y2)){
            result = true;
            p1 = QString::number(x1 * 18 + y2);
        }
        mapOfAll[x1][y2] = 0;
    }
    if (mapOfAll[x2][y1] == 0){
        mapOfAll[x2][y1] = mapOfAll[x1][y1];
        if (couldBelinked(x1,y1,x2,y1) && couldBelinked(x2,y2,x2,y1)){
            result = true;
            p1 = QString::number((x2 * 18 + y1));
        }
        mapOfAll[x2][y1] = 0;
    }
    if (result && isThis){
        pictureNumber -= 2;
        mapOfAll[x1][y1] = 0;
        mapOfAll[x2][y2] = 0;
        twoLines = true;
    }
    return result;
}

bool Game::linkWithThreeLines(QString pic1, QString pic2, QString& p1, QString& p2){
    bool result{false};
    int x1{},x2{},y1{}, y2{};
    getCoordinate(x1,y1,x2,y2,pic1,pic2);

    if (mapOfAll[x1][y1] != mapOfAll[x2][y2])
        return false;
    for (int i = 0; i < 12 *18; i++){
        QString a = QString::number(i);
        if(mapOfAll[i/18][i%18] == 0){
            mapOfAll[i/18][i%18] = mapOfAll[x1][y1];
            if (linkWithOneLine(pic1,a,false) && linkWithTwoLines(pic2,a,p2,false)){
                p1 = a;
                result = true;
                mapOfAll[i/18][i%18] = 0;
                break;
            }
            mapOfAll[i/18][i%18] = 0;
        }

    }
    if(result){
        pictureNumber -= 2;
        mapOfAll[x1][y1] = 0;
        mapOfAll[x2][y2] = 0;
        threeLines = true;
    }
    return result;
}

bool Game::isWin(){
    if (pictureNumber == 0){
        return true;
    }else{
        return false;
    }
}

bool Game::couldBelinked(int x1, int y1, int x2, int y2){
    if (x1 != x2 && y1 != y2)
        return false;
    if (mapOfAll[x1][y1] != mapOfAll[x2][y2])
        return false;
    if (mapOfAll[x1][y1] == 0 || mapOfAll[x2][y2] == 0)
        return false;
    if (x1 == x2){
        for (int i = y1 + 1; i < y2; i++){
            if(mapOfAll[x1][i] != 0)
                return false;
        }
        for (int i = y2 + 1; i < y1; i++){
            if(mapOfAll[x1][i] != 0)
                return false;
        }
    }
    if (y1 == y2){
        for (int i = x1 + 1; i < x2; i++){
            if (mapOfAll[i][y1] != 0)
                return false;
        }
        for (int i = x2 + 1; i < x1; i++){
            if (mapOfAll[i][y1] != 0)
                return false;
        }
    }
    return true;
}



