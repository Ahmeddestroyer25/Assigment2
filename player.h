#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

    int getHealth() const;
    int getScore() const;
    void keyPressEvent(QKeyEvent * event);

public slots:
    void createEnemy();
    void decrease();
    void increase();
    void gameOver();

private:
    int health = 3;
    int score = 0;
};

#endif // PLAYER_H
