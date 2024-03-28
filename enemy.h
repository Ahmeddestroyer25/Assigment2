// In enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();

signals:
    void bypassedSpacecraft();

public slots:
    void move();

private:
    int health = 3;
};

#endif // ENEMY_H
