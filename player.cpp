#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/shooting.wav"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
            setPos(x()-10, y());

    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + pixmap().width() < 800)
            setPos(x()+10, y());
    }
    if (event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().size().width()/2, y() - bullet->pixmap().size().height());
        scene()->addItem(bullet);
        if (bulletSound->state() == QMediaPlayer::PlayingState)
        {
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState)
        {
            bulletSound->play();
        }
    }
}

void Player::spawnEnemy()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
