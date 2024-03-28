// In bullet.h
#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player; // Forward declaration

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(Player *player); // Constructor now takes a Player pointer

public slots:
    void move();

private:
    Player *player; // Reference to the Player object
};

#endif // BULLET_H
