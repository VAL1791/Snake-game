#include "obstacle.h"
#include <QBrush>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QTimer>
#include "Fruit.h"

Obstacle::Obstacle(QGraphicsItem *parent)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        if (typeid(*cItems[i]) == typeid(Fruit)){
            scene()->removeItem(cItems[i]);
            delete cItems[i];
            Fruit * fruit = new Fruit();
            scene()->addItem(fruit);
        }
    }
}

