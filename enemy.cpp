#include "enemy.h"
#include "game.h"
#include "effect.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/enemy.png"));

    int randomNum = rand() % 700;
    setPos(randomNum, 0);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+5);

    if (pos().y() + pixmap().height() > 600)
    {
        Effect *bumEffect = new Effect();
        bumEffect->setPos(x() + pixmap().width()/4, y() + pixmap().height()/2);
        scene()->addItem(bumEffect);

        game->health->decreaseHealth();
        scene()->removeItem(this);
        delete this;
    }
}
