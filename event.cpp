#include "background.h"
#include "event.h"
#include "mainwindow.h"
#include "object.h"

Obstacle* Obstacle::instance_ = nullptr;

// Definition for get-instance method (which constructs an instance when needed)
Obstacle& Obstacle::instance()
{
  if (instance_ == nullptr)
  {
    instance_ = new Obstacle();
  }
  return *instance_;
}






QLabel* Obstacle::spawnObstacles(QWidget *parent)
{

    Obstacle& o = Obstacle::instance();


    QLabel * madDogLabel = new QLabel(parent);
    QMovie * dogMovie = new QMovie(":/dog.gif");
    madDogLabel->setMovie(dogMovie);
    madDogLabel->setGeometry(parent->width(),177,75,75);
    madDogLabel->setScaledContents(true);
    dogMovie->start();
    madDogLabel->hide();
    //madDogLabel->show();
    o.obstacles.push_back(madDogLabel);

    QLabel* lawnMowerLabel = new QLabel(parent);
    QPixmap mower(":/lawnmower2.png");
    lawnMowerLabel->setPixmap(mower);
    lawnMowerLabel->setGeometry(parent->width(), 175, 70,70);
    lawnMowerLabel->setScaledContents(true);
    lawnMowerLabel->hide();
    //lawnMowerLabel->show();
    o.obstacles.push_back(lawnMowerLabel);

    QLabel* holeLabel = new QLabel(parent);
    QPixmap hole(":/hole.png");
    holeLabel->setPixmap(hole);
    holeLabel->setGeometry(parent->width(),191,100,400);
    holeLabel->setScaledContents(true);
    holeLabel->hide();
    //holeLabel->show();
    o.obstacles.push_back(holeLabel);
    std::random_shuffle(o.obstacles.begin(), o.obstacles.end());

    QLabel * ob = new QLabel(parent);
    ob = o.obstacles[0];
    ob->show();
    spawnedObstacles.push_back(ob);

    return ob;


}

