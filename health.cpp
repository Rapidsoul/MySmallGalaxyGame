#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decreaseHealth()
{
    health--;
    setPlainText("Health: " + QString::number(health));
    if (getHealth() == 0)
        emit lessThenNull();
}

int Health::getHealth()
{
    return health;
}
