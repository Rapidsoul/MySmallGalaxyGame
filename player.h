#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawnEnemy();
private:
    QMediaPlayer * bulletSound;
};

#endif // PLAYER_H
