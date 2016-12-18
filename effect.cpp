#include "effect.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game *game;

Effect::Effect(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bum.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(del()));
    timer->start(1000);
}

void Effect::del()
{
    scene()->removeItem(this);
    delete this;
}
