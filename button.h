#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QTimer>

class button : public QPushButton{
    Q_OBJECT
public:
    explicit button(QWidget *parent = 0) : QPushButton(parent),
        pauseMsecs(400), intervalMsecs(30){
        tm = new QTimer(this);
        connect(this, SIGNAL(clicked(bool)), this, SLOT(on_clicked()));
    }
private:
    QTimer *tm;
    long pauseMsecs;
    long intervalMsecs;
signals:
    void keyClicked(const QString &msg);
public slots:
    void on_clicked(){
        emit this->keyClicked(this->objectName());
    }

};


#endif // BUTTON_H
