#include "Game.h"
#include "SnakeHead.h"
#include "Fruit.h"
#include "obstacle.h"
#include "Score.h"
#include "Button.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFile>
#include <QStringList>
#include <QDebug>


Game::Game(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene(0, 0, 440, 440);
    setScene(scene);
}

void Game::start(){
    scene->clear();
    SnakeHead* snakeHead = new SnakeHead();
    scene->addItem(snakeHead);
    snakeHead->setFocus();

    Fruit * fruit = new Fruit();
    scene->addItem(fruit);

    QFile file("/Users/vav/Desktop/obs.csv"); // OBSTACLES FILE PATH
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
    }

    int cnt = 0;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (cnt!=0){
            addObstacle(line.split(',')[0].toInt(),
                        line.split(',')[1].toInt(),
                        line.split(',')[2].toInt(),
                        line.split(',')[3].toInt());
            }
            cnt++;
        }

    drawGUI();
    score = new Score();
    scene->addItem(score);

}

void Game::restartGame()
{
    scene->clear();
    start();
}

void Game::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Snake Game"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("New Game"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::displayCongratulation()
{

    for (size_t i = 0, n = scene->items().size(); i < n; i++)
    {
        scene->items()[i]->setEnabled(false);
    }

    drawPanel(0,0,460,460,Qt::black,0.65);
    drawPanel(60,60,340,340,Qt::lightGray,0.75);

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Conratulations!"));
    QFont titleFont("comic sans", 30);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 80;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    QGraphicsTextItem* subtitleText = new QGraphicsTextItem(QString("You Won!"));
    subtitleText->setFont(titleFont);
    txPos = this->width()/2 - subtitleText->boundingRect().width()/2;
    tyPos = 140;
    subtitleText->setPos(txPos,tyPos);
    scene->addItem(subtitleText);
}



void Game::displayGameOverWindow(){
    for (size_t i = 0, n = scene->items().size(); i < n; i++)
    {
        scene->items()[i]->setEnabled(false);
    }


    drawPanel(0,0,460,460,Qt::black,0.65);
    drawPanel(60,60,340,340,Qt::lightGray,0.75);

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("The End"));
    QFont titleFont("comic sans", 30);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 80;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playAgain = new Button(QString("Retry"));
    int bxPos = this->width()/2 - playAgain->boundingRect().width()/2;
    int byPos = 180;
    playAgain->setPos(bxPos,byPos);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    Button* quit = new Button(QString("Exit"));
    int qxPos = this->width()/2 - quit->boundingRect().width()/2;
    int qyPos = 280;
    quit->setPos(qxPos,qyPos);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::drawGUI()
{
    drawPanel(0, 0, 420, 20, Qt::darkCyan,1);
    drawPanel(0, 20, 20, 420, Qt::darkCyan,1);
    drawPanel(20, 420, 420, 20, Qt::darkCyan,1);
    drawPanel(420, 0, 20, 420, Qt::darkCyan,1);
}

void Game::addObstacle(int x1, int y1, int x2, int y2)
{
    Obstacle* obstacle = new Obstacle();
    obstacle->setPos(x1*10 + 1, y1*10 + 1);
    obstacle->setRect(x1*10 + 1, y1*10 + 1, (x2-x1) * 20-3, (y2-y1)*20-3);
    scene->addItem(obstacle);
}
