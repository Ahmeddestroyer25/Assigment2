#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "enemy.h"
#include "player.h"
class Player;

Bullet::Bullet(Player *player) : QObject(), QGraphicsPixmapItem()
{

    setPixmap(QPixmap(":/images/bullet.png"));


    setScale(0.3);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);


    this->player = player;
}

void Bullet::move()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];

            player->increase();
            delete this;
            return;
        }
    }


    setPos(x(), y() - 10);


    if (pos().y() + pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
