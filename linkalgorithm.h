#ifndef LINKALGORITHM_H
#define LINKALGORITHM_H
#include <QString>
#include "button.h"
#include "mainwindow.h"
#include "game.h"
#include "drawline.h"
class linkAlgorithm{
public:
    bool link(button *buttonPushed,Game game);
private:
    drawLine line;
    QString p1,p2;
};


#endif // LINKALGORITHM_H
