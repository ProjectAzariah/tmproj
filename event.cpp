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
  //instance_->catX =
  return *instance_;
}






QLabel* Obstacle::spawnObstacles(QWidget *parent)
{

    Obstacle& o = Obstacle::instance();


    QLabel * madDogLabel = new QLabel(parent);
    QMovie * dogMovie = new QMovie(":/dog.gif");
    Object * dog = new MadDog();
    madDogLabel->setMovie(dogMovie);
    madDogLabel->setGeometry(parent->width(),460,128,192);
    madDogLabel->setScaledContents(true);
    dogMovie->start();
    madDogLabel->hide();
    //madDogLabel->show();
    o.obstacles.push_back(madDogLabel);

    QLabel* lawnMowerLabel = new QLabel(parent);
    QPixmap mower(":/lawnmower2.png");
    lawnMowerLabel->setPixmap(mower);
    lawnMowerLabel->setGeometry(parent->width(), 514, 128,128);
    lawnMowerLabel->setScaledContents(true);
    lawnMowerLabel->hide();
    //lawnMowerLabel->show();
    o.obstacles.push_back(lawnMowerLabel);

    QLabel* holeLabel = new QLabel(parent);
    QPixmap hole(":/hole.png");
    holeLabel->setPixmap(hole);
    holeLabel->setGeometry(parent->width(),517,128,768);
    holeLabel->setScaledContents(true);
    holeLabel->hide();
    //holeLabel->show();
    o.obstacles.push_back(holeLabel);
    std::random_shuffle(o.obstacles.begin(), o.obstacles.end());

    QLabel * ob = new QLabel(parent);

    ob = o.obstacles[0];
    if (ob->y() == 460)
    {
        Object * obj = new MadDog();
        obj->setHealthImpact(50);
        objects.push_back(obj);
    }
    else if (ob->y() == 514)
    {
        Object * obj = new LawnMower();
        obj->setHealthImpact(25);
        objects.push_back(obj);
    }
    else if (ob->y() == 517)
    {
        Object * obj = new Hole();
        obj->setHealthImpact(100);
        objects.push_back(obj);
    }

    ob->show();
    spawnedObstacles.push_back(ob);

    return ob;
}
