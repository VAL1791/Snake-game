#include "MyRect.h"
#include <QKeyEvent>
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event){
    qDebug() << "A key was pressed";
    if (event->key() == Qt::Key_A){
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_D){
        setPos(x()+20,y());
    }
    else if (event->key() == Qt::Key_W){
        setPos(x(),y()-20);
    }
    else if (event->key() == Qt::Key_S){
        setPos(x(),y()+20);
    }
}
