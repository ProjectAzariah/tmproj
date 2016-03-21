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
    Object * dog = new MadDog();
    madDogLabel->setMovie(dogMovie);
    madDogLabel->setGeometry(parent->width(),200,50,50);
    madDogLabel->setScaledContents(true);
    dogMovie->start();
    madDogLabel->hide();
    //madDogLabel->show();
    o.obstacles.push_back(madDogLabel);

    QLabel* lawnMowerLabel = new QLabel(parent);
    QPixmap mower(":/lawnmower2.png");
    lawnMowerLabel->setPixmap(mower);
    lawnMowerLabel->setGeometry(parent->width(), 201, 50,50);
    lawnMowerLabel->setScaledContents(true);
    lawnMowerLabel->hide();
    //lawnMowerLabel->show();
    o.obstacles.push_back(lawnMowerLabel);

    QLabel* holeLabel = new QLabel(parent);
    QPixmap hole(":/hole.png");
    holeLabel->setPixmap(hole);
    holeLabel->setGeometry(parent->width(),202,50,300);
    holeLabel->setScaledContents(true);
    holeLabel->hide();
    //holeLabel->show();
    o.obstacles.push_back(holeLabel);
    std::random_shuffle(o.obstacles.begin(), o.obstacles.end());

    QLabel * ob = new QLabel(parent);

    ob = o.obstacles[0];
    if (ob->y() == 200)
    {
        Object * obj = new MadDog();
        objects.push_back(obj);
    }
    else if (ob->y() == 201)
    {
        Object * obj = new LawnMower();
        objects.push_back(obj);
    }
    else if (ob->y() == 202)
    {
        Object * obj = new Hole();
        objects.push_back(obj);
    }

    ob->show();
    spawnedObstacles.push_back(ob);

    return ob;


}

