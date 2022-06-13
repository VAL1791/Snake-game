#include "SnakeHead.h"
#include <QBrush>
#include "Fruit.h"
#include "obstacle.h"
#include "SnakeBody.h"
#include "Game.h"
#include <QTimer>

extern Game* game;

SnakeHead::SnakeHead(QGraphicsItem *parent)
{
    setRect(20,20,20,20);
    dir = 'R';
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable,true);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(300);
    SnakeBody* b1 = new SnakeBody();
    b1->setPos(0,20);
    game->scene->addItem(b1);
    snakeBodies.prepend(b1);

}

void SnakeHead::move()
{
    prevPos = pos();
    if (dir == 'U')
    {
        setPos(x(),y()-20);
        if (pos().y() < 0)
        {
            game->displayGameOverWindow();
        }
    }
    else if (dir == 'D')
    {
        setPos(x(),y()+20);
        if (pos().y() >= 420)
        {
            game->displayGameOverWindow();
        }
    }
    else if (dir == 'L'){
        setPos(x()-20,y());
        if (pos().x() < 0)
        {
            game->displayGameOverWindow();
        }
    }
    else if (dir == 'R')
    {
        setPos(x()+20,y());
        if (pos().x() >= 420)
        {
            game->displayGameOverWindow();
        }

    }

    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i)
    {
        if (typeid(*cItems[i]) == typeid(Fruit))
        {
            elongate();
            scene()->removeItem(cItems[i]);
            delete cItems[i];
            game->score->increase();
            Fruit * fruit = new Fruit();
            scene()->addItem(fruit);
        }
        else if (typeid(*cItems[i]) == typeid(Obstacle))
        {
            game->displayGameOverWindow();
        }

        else if ((typeid(*cItems[i]) == typeid(SnakeBody)) && (cItems[i] != snakeBodies.last()))
        {
            game->displayGameOverWindow();
        }
    }
    moveBodies();
}

void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    // move up
    if (event->key() == Qt::Key_W)
    {
        dir = 'U';
    }

    // move down
    if (event->key() == Qt::Key_S)
    {
        dir = 'D';
    }

    // move right
    if (event->key() == Qt::Key_D)
    {
        dir = 'R';
    }

    // move left
    if (event->key() == Qt::Key_A)
    {
        dir = 'L';
    }
}

void SnakeHead::elongate()
{
    SnakeBody* body = new SnakeBody();
    snakeBodies.prepend(body);
    body->setPos(-200,-200);
    game->scene->addItem(body);
}

void SnakeHead::moveBodies()
{
    for (size_t i = 0, n = snakeBodies.size()-1; i < n; ++i)
    {
        snakeBodies[i]->setPos(snakeBodies[i+1]->pos());
    }
    snakeBodies.last()->setPos(prevPos);
}
