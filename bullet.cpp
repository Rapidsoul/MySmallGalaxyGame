#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "effect.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bullet.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            game->score->increaseScore();
            Effect *bumEffect = new Effect();
            bumEffect->setPos(colliding_items[i]->x(), colliding_items[i]->y());
            scene()->addItem(bumEffect);

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y()-10);
    if (pos().y() + pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }

}
