#ifndef DRAWLINELAYER_H
#define DRAWLINELAYER_H
#include <QWidget>
#include <QPainter>

class DrawLineLayer : public QWidget
{
    Q_OBJECT

public:
    DrawLineLayer(QWidget *parent = 0);
    void setPos1(QPoint pos);
    void setPos2(QPoint pos);
    void setPos3(QPoint pos);
    void setPos4(QPoint pos);
    void clear();
    ~DrawLineLayer();

protected:
    void paintEvent(QPaintEvent *);

private:
    QPoint pos1, pos2, pos3, pos4;

};

#endif // DRAWLINELAYER_H


