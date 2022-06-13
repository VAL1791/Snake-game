#include "Fruit.h"
#include "obstacle.h"
#include <QBrush>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QTimer>

Fruit::Fruit(QGraphicsItem *parent)
{
    int rnd_x = rand()%20 * 20 + 40;
    int rnd_y = rand()%20 * 20 + 40;
    setPos(rnd_x, rnd_y);
    // draw
    setRect(0,0,10,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}

