#include "drawLineLayer.h"
DrawLineLayer::DrawLineLayer(QWidget *parent)
    : QWidget(parent)
{
}

DrawLineLayer::~DrawLineLayer()
{

}
//重新实现paintEvent
void DrawLineLayer::paintEvent(QPaintEvent *)
{
    QPainter paint(this),paint1(this);
    QPen pen,pen1;
    pen.setWidth(4);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::blue);
    pen1.setWidth(4);
    pen1.setStyle(Qt::SolidLine);
    pen1.setColor(Qt::yellow);
    paint.setPen(pen);
    paint1.setPen(pen1);
    if (!pos1.isNull() && !pos2.isNull()) {
        pos1.rx() += 20;
        pos1.ry() += 110;
        pos2.rx() += 20;
        pos2.ry() += 110;
        paint1.drawLine(pos1, pos2);
        paint.drawLine(pos1, pos2);
    }
    if (!pos2.isNull() && !pos3.isNull()) {
        pos3.rx() += 20;
        pos3.ry() += 110;
        paint1.drawLine(pos2, pos3);
        paint.drawLine(pos1, pos2);
    }
    if (!pos3.isNull() && !pos4.isNull()) {
        pos4.rx() += 20;
        pos4.ry() += 110;
        paint1.drawLine(pos3, pos4);
        paint.drawLine(pos1, pos2);
    }
}


//设置四个点
void DrawLineLayer::setPos1(QPoint pos) {
    this->pos1 = pos;
}

void DrawLineLayer::setPos2(QPoint pos) {
    this->pos2 = pos;
}

void DrawLineLayer::setPos3(QPoint pos) {
    this->pos3 = pos;
}

void DrawLineLayer::setPos4(QPoint pos) {
    this->pos4 = pos;
}


//点坐标归零
void DrawLineLayer::clear() {
    pos1.setX(0);
    pos1.setY(0);
    pos2.setX(0);
    pos2.setY(0);
    pos3.setX(0);
    pos3.setY(0);
    pos4.setX(0);
    pos4.setY(0);
    this->hide();
}
