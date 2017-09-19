#include "game.h"

Game::Game(){
//初始化整体游戏操作区域
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 18; j++)
            mapOfAll[i][j] = 0;
}

bool Game::noOtherPic(char same,int n, int n1, int n2){
    if (n1 > n2){
        int tmp{n1};
        n1 = n2;
        n2 = tmp;
    }
    if (same == 'x'){
        for (int i = n1 + 1 ; i < n2 ; i++){
            if (mapOfAll[n][i] != 0)
                return false;
        }
        return true;
    }
    if (same == 'y'){
        for (int i = n1 + 1 ; i < n2 ; i++){
            if (mapOfAll[i][n] != 0)
                return false;
        }
        return true;
    }

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
    if (isThis){
        if (mapOfAll[x1][y1] != mapOfAll[x2][y2]){
            return false;
        }
    }

    if (x1 == x2){
        int x = x1;
        if (( y1 == y2 +1) || ( y2 == y1 + 1))result = true;
        if (noOtherPic('x', x, y1, y2))result = true;
    }
    if (y1 == y2){
        int y = y2;
        if (( x1 == x2 +1 ) || ( x2 == x1 + 1))result = true;
        if (noOtherPic('y', y, x1, x2))result = true;
    }
   if(result && isThis){
        mapOfAll[x1][y1] = 0;
        mapOfAll[x2][y2] = 0;
        pictureNumber -= 2;
    }
    return result;
}

bool Game::linkWithTwoLines(QString pic1, QString pic2, bool isThis){
    bool result{false};
    int x1{},x2{},y1{},y2{};
    getCoordinate(x1,y1,x2,y2,pic1,pic2);
    if (isThis){
        if (mapOfAll[x1][y1] != mapOfAll[x2][y2]){
            return false;
        }
    }

    if(linkWithOneLine(pic1,pic2,false))return false;
    QString a = QString::number(x1 * 18 + y2);
    QString b = QString::number(x2 * 18 + y1);
    if ((linkWithOneLine(pic1,a,false)&&linkWithOneLine(pic2,a,false))||(linkWithOneLine(pic1,b,false)&&linkWithOneLine(pic2,b,false))){
        result = true;
    }
    if(result && isThis){
         mapOfAll[x1][y1] = 0;
         mapOfAll[x2][y2] = 0;
         pictureNumber -= 2;
     }
    return result;
}

bool Game::linkWithThreeLines(QString pic1, QString pic2){
    bool result{false};
    int x1{},x2{},y1{}, y2{};
    getCoordinate(x1,y1,x2,y2,pic1,pic2);
    if (mapOfAll[x1][y1] != mapOfAll[x2][y2]){
        return false;
    }
    /*QString a = QString::number(x1 * 18 + y2);
    QString b = QString::number(x2 * 18 + y1);
    */
    for (int i = 0 ; i < 18*12 ; i++){
        QString a = QString::number(i);
        if(linkWithOneLine(pic1,a,false)&&linkWithTwoLines(pic2,a,false))result = true;
    }
    //if (linkWithOneLine(pic1,a,false)&&linkWithTwoLines(pic2,a,false) || (linkWithOneLine(pic1,b,false) && linkWithTwoLines(pic2,b,false))){
    //    result = true;
    //}

    if(result){
         mapOfAll[x1][y1] = 0;
         mapOfAll[x2][y2] = 0;
         pictureNumber -= 2;
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


