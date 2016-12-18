#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QtMultimedia/QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QMessageBox>

Game::Game(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    player = new Player();
    player->setPos(this->width()/2, this->height() - player->pixmap().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    timer->start(2000);

    QObject::connect(health, SIGNAL(lessThenNull()), this, SLOT(endGame()));

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/main.wma"));
    music->play();

    show();
}

void Game::endGame()
{
    QMessageBox *message = new QMessageBox();
    message->text() = "End game!";
    message->show();
}
