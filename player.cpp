#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "enemy.h"
#include "gameover.h"

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

    // Connect bypassedSpacecraft signal to decrease function
    connect(enemy, SIGNAL(bypassedSpacecraft()), this, SLOT(decrease()));
}
void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
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

    // Update health display
    QGraphicsTextItem *healthText = new QGraphicsTextItem;
    /*scene()->addItem(healthText);
    healthText->hide();
    healthText->setFont(QFont("times", 16));
    healthText->setDefaultTextColor(Qt::red);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10, 10);*/
    if (healthText) {
        delete healthText;
    }
    healthText = new QGraphicsTextItem;
    scene()->addItem(healthText);
    healthText->setFont(QFont("times", 16));
    healthText->setDefaultTextColor(Qt::red);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10, 10);

}

void Player::increase() {
    score++;

    // Update score display
    QGraphicsTextItem *scoreText = new QGraphicsTextItem;
    scene()->addItem(scoreText);
    scoreText->setFont(QFont("times", 16));
    scoreText->setDefaultTextColor(Qt::red);
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(600, 10);

}

void Player::gameOver() {
    // Game over handling
    QGraphicsTextItem *gameOverText = new QGraphicsTextItem;
    gameOverText->setFont(QFont("times", 24));
    gameOverText->setDefaultTextColor(Qt::red);
    gameOverText->setPlainText("Game Over! Your Score: " + QString::number(score));
    gameOverText->setPos(200, 250);
    scene()->addItem(gameOverText);
}
