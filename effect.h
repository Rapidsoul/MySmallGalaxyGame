#ifndef EFFECT_H
#define EFFECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Effect: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Effect(QGraphicsItem * parent=0);
public slots:
    void del();
};

#endif // EFFECT_H
