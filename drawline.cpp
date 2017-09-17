#include "drawline.h"

drawLine::drawLine(QWidget *parent)
    : QWidget(parent)
{
}

void drawLine::setP(int index, QPoint p)
{
    this->p[index] = p;
}

void drawLine::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen pen;
    pen.setWidth(2);
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::yellow);
    paint.setPen(pen);
    if (!p[0].isNull() && !p[1].isNull()){
        p[0].rx() += 20;
        p[0].ry() += 20;
        p[1].rx() += 20;
        p[1].ry() += 20;
        paint.drawLine(p[0], p[1]);
    }
    if (!p[1].isNull() && !p[2].isNull()) {
        p[2].rx() += 20;
        p[2].ry() += 20;
        paint.drawLine(p[1], p[2]);
    }
    if (!p[2].isNull() && !p[3].isNull()) {
        p[3].rx() += 20;
        p[3].ry() += 20;
        paint.drawLine(p[2], p[3]);
    }
}

drawLine::~drawLine()
{

}

