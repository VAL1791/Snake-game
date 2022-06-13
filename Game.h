#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Score.h"
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL); // constructor
    void displayMainMenu();

    QGraphicsScene* scene;
    Score * score = new Score(); // public attributes
    void displayGameOverWindow();
    void displayCongratulation();
public slots:
    void start();
    void restartGame();
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
        void drawGUI();
    void addObstacle(int x1, int y1, int x2, int y2);
};

#endif // GAME_H
