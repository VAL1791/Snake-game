#include "Score.h"
#include <QFont>
#include "Game.h"


extern Game* game;

Score::Score(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    score = 1;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    if (score >=30)
    {
        game->displayCongratulation();
    }
}

int Score::getScore()
{
    return score;
}

