#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "SnakeBody.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QObject>

class SnakeHead: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    SnakeHead(QGraphicsItem* parent=NULL); // constructors
    void keyPressEvent(QKeyEvent* event);
    void elongate();
    void moveBodies();

public slots:
    void move();
private:
    QList<SnakeBody*> snakeBodies;
    QPointF prevPos;
    char dir;

};

#endif // SNAKEHEAD_H
