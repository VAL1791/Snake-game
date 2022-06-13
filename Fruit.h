#ifndef FRUIT_H
#define FRUIT_H

#include <QGraphicsEllipseItem>

class Fruit: public QObject, public QGraphicsEllipseItem
{
public:
    Fruit(QGraphicsItem* parent=NULL);
};

#endif // FRUIT_H
