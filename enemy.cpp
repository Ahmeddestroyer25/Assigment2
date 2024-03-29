// In enemy.cpp
#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

Enemy::Enemy() {

    setPixmap(QPixmap(":/images/Daco_4627996.png"));
    setScale(0.12);


    int random_number = rand() % 701;
    setPos(random_number, 0);


    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move() {
    setPos(x(), y() + 5);


    if (y() > scene()->height()) {
        emit bypassedSpacecraft();
        scene()->removeItem(this);
        delete this;
    }
}
