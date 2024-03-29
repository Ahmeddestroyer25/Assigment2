#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "enemy.h"
#include "QMessageBox"
#include <QApplication>


Player::Player() {
    // Load player image and set its size
    setPixmap(QPixmap(":/images/Picture1.png"));
    setScale(0.5);

}

void Player::createEnemy()
{
    // Create enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);


    connect(enemy, SIGNAL(bypassedSpacecraft()), this, SLOT(decrease()));
}
void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800)
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(this);
        bullet->setPos(x()+104,y());
        scene()->addItem(bullet);
    }
}
void Player::decrease() {
    health--;
    if (health < 1) {
        gameOver();
        return;
    }


    QGraphicsTextItem *healthText = new QGraphicsTextItem;

    QGraphicsRectItem *rectItem = new QGraphicsRectItem;


    rectItem->setRect(0, 0, 100, 50);


    rectItem->setBrush(Qt::black);


    scene()->addItem(rectItem);
    healthText = new QGraphicsTextItem;
    scene()->addItem(healthText);
    healthText->setFont(QFont("times", 16));
    healthText->setDefaultTextColor(Qt::blue);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10, 10);

}

void Player::increase() {
    score++;
    QGraphicsRectItem *rectItem = new QGraphicsRectItem;


    rectItem->setRect(500, 0, 800, 50);


    rectItem->setBrush(Qt::black);


    scene()->addItem(rectItem);


    QGraphicsTextItem *scoreText = new QGraphicsTextItem;
    scene()->addItem(scoreText);
    scoreText->setFont(QFont("times", 16));
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(600, 10);

}

void Player::gameOver() {

    /*QGraphicsTextItem *gameOverText = new QGraphicsTextItem;
    gameOverText->setFont(QFont("times", 24));
    gameOverText->setDefaultTextColor(Qt::red);
    gameOverText->setPlainText("Game Over! Your Score: " + QString::number(score));
    gameOverText->setPos(200, 250);
    scene()->addItem(gameOverText);
    */
    QMessageBox::information(nullptr, "Game Over", "Your Score: " + QString::number(score));
    QApplication::quit();

}
