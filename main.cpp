#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QFont>
#include <QGraphicsTextItem>
#include<QGraphicsPixmapItem>
#include "player.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the Scene
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 800, 600);

    // Create the View
    QGraphicsView *view = new QGraphicsView;
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create the Player
    Player *player = new Player();
    player->setPixmap(QPixmap(":/images/Picture1.png"));
    player->setScale(0.5);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(view->width() / 2 - player->pixmap().width() / 2,400);

    // Assign scene to the view
    view->setScene(scene);
    view->setBackgroundBrush(Qt::black);

    view->show();

    // Create the Enemies automatically
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(createEnemy()));
    timer->start(2000);



    return a.exec();
}
