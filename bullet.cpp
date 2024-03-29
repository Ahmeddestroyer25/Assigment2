#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "enemy.h"
#include "player.h"
class Player;

Bullet::Bullet(Player *player) : QObject(), QGraphicsPixmapItem()
{
    // Load bullet image
    setPixmap(QPixmap(":/images/bullet.png"));

    // Set bullet size
    setScale(0.3);
    // Generate the Bullets automatically
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    // Store reference to the player
    this->player = player;
}

void Bullet::move()
{
    // Handle collision with enemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            // Increase score via player objec
            player->increase();
            delete this;
            return;
        }
    }

    // Move the bullet upwards
    setPos(x(), y() - 10);

    // Remove bullet if it goes out of scene
    if (pos().y() + pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
