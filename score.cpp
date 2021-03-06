#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void Score::increaseScore()
{
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
