#ifndef DRAWLINE_H
#define DRAWLINE_H
#include <QWidget>
#include <QPainter>

class drawLine : public QWidget
{
    Q_OBJECT

public:
    drawLine(QWidget *parent = 0);
    void setP(int index, QPoint p);
    void paintEvent(QPaintEvent *);
    ~drawLine();
private:
    QPoint p[4]{};
};

#endif // DRAWLINE_H
