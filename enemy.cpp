// In enemy.cpp
#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "player.h"

Enemy::Enemy() {
    // Load enemy image and set its size
    setPixmap(QPixmap(":/images/Daco_4627996.png"));
    setScale(0.12);

    // Set the position of the enemy within the view dimensions
    int random_number = rand() % 701;
    setPos(random_number, 0);

    // Moving the enemies downwards automatically every 50 milliseconds
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move() {
    setPos(x(), y() + 5);

    // Check if the enemy bypasses the spacecraft
    if (y() > scene()->height()) {
        emit bypassedSpacecraft();
        scene()->removeItem(this);
        delete this;
    }
}
