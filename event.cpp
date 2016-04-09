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

    QLabel * enemyLabel = new QLabel(parent);
    Object * enemyObject;

    int enemySelect = rand() % 3;

    if(enemySelect==0){
        QMovie * dogMovie = new QMovie(":/dog.gif");
        enemyObject = new MadDog();
        enemyLabel->setMovie(dogMovie);
        enemyLabel->setGeometry(parent->width(),460,128,192);
        dogMovie->start();
    }else if(enemySelect = 1){
        enemyObject = new LawnMower;
        QPixmap mower(":/lawnmower2.png");
        enemyLabel->setPixmap(mower);
        enemyLabel->setGeometry(parent->width(), 514, 128,128);
    }else if(enemySelect==2){
        enemyObject =new Hole;
        QPixmap hole(":/hole.png");
        enemyLabel->setPixmap(hole);
        enemyLabel->setGeometry(parent->width(),615,128,768);
    }

    enemyLabel->setScaledContents(true);
    enemyLabel->show();

    objects.push_back(enemyObject);
    spawnedObstacles.push_back(enemyLabel);

    return enemyLabel;


}

