#include <algorithm>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "object.h"
#include "event.h"
#include "background.h"
#include "mainwindow.h"


CuriousCat::CuriousCat(QWidget *parent)
{
    setX(128);
    setY(450);
    setW(192);
    setH(192);
    setType("CuriousCat");
    //jumpSpeed = 100;
    //gravity = 0;
    height = 0;
    speed = 200;
    isClimbing = false;
    isFalling = false;
    isLanded = true;
    counter = 0;




    catMovie = new QMovie(":/cat.gif");
    cat = new QLabel(parent);
    cat->setMovie(catMovie);
    catMovie->start();
    cat->setGeometry(128,450, 192, 192);
    cat->setScaledContents(true);

    cat->show();


    QLabel * forHeadSensor = new QLabel(parent);
    QPixmap sensor(":/furball2.png");
    forHeadSensor->setGeometry(forHeadX,forHeadY,sensorW, sensorH);

    forHeadSensor->setPixmap(sensor);
    forHeadSensor->setScaledContents(true);
    catSensors.push_back(forHeadSensor);
    forHeadSensor->show();

    QLabel * mouthSensor = new QLabel(parent);
    mouthSensor->setGeometry(mouthX, mouthY, sensorW, sensorH);
    mouthSensor->setPixmap(sensor);
    mouthSensor->setScaledContents(true);
    catSensors.push_back(mouthSensor);
    mouthSensor->show();


    QLabel * frontPawSensor = new QLabel(parent);
    frontPawSensor->setGeometry(frontPawX,frontPawY, sensorW,sensorH);
    frontPawSensor->setPixmap(sensor);
    frontPawSensor->setScaledContents(true);
    catSensors.push_back(frontPawSensor);
    frontPawSensor->show();


    QLabel * backPawSensor = new QLabel(parent);
    backPawSensor->setGeometry(frontPawX - 75, frontPawY, sensorW, sensorH);
    backPawSensor->setPixmap(sensor);
    backPawSensor->setScaledContents(true);
    catSensors.push_back(backPawSensor);
    backPawSensor->show();

    QLabel * tailSensor = new QLabel(parent);
    tailSensor->setGeometry(tailX, tailY, sensorW, sensorH);
    tailSensor->setPixmap(sensor);
    tailSensor->setScaledContents(true);
    catSensors.push_back(tailSensor);
    tailSensor->show();



}


MadDog::MadDog()
{
    setX(250);
    setY(177);
    setW(75);
    setH(75);
    setType("MadDog");
    setHealthImpact(50);
    isCollided = false;
    //isDog = true;
    /*dogMovie = new QMovie(":/dog.gif");
    dog = new QLabel(parent);
    dog->setMovie(dogMovie);
    dogMovie->start();
    dog->setGeometry(250,177, 75, 75);
    dog->setScaledContents(true);
    //objects.push_back(dog);
    dog->show();
    Obstacle& o = Obstacle::instance();

    o.obstacles.push_back(dog);*/

}



/*void MadDog::dogTimerHit()
{
    /*for (unsigned int i = 0; i < spawnedEns.size(); i++)
    {
        QLabel * enemy = new QLabel;
        enemy = spawnedEns[i];
       w enemy->move(enemy->x() - 1, enemy->y());
        if (enemy->geometry().intersects(cat->geometry()) && end == nullptr)
        {
            end = new QLabel(this);
            end->setText("YOU LOSE");
            end->showFullScreen();
            end->setGeometry(cat->x(),cat->y() - 75, 100,100);
            end->setScaledContents(true);
            end->show();
        }
    }
}*/


LawnMower::LawnMower()
{
    setX(350);
    setY(198);
    setW(50);
    setH(50);
    setType("LawnMower");
    setHealthImpact(25);
    isCollided = false;
}


Hole::Hole()
{
    setX(150);
    setY(208);
    setW(75);
    setH(300);
    setType("Hole");
    setHealthImpact(100);
    isCollided = false;
}




//QLabel* Object::objectSpawner(QWidget *parent)
/*{

    QLabel * madDogLabel = new QLabel(parent);
    QMovie * dogMovie = new QMovie(":/dog.gif");
    madDogLabel->setMovie(dogMovie);
    madDogLabel->setGeometry(100,100,50,50);
    madDogLabel->setScaledContents(true);
    dogMovie->start();
    madDogLabel->show();
    //objects.push_back(madDogLabel);

    QLabel* lawnMowerLabel = new QLabel(parent);
    QPixmap mower(":/lawnmower2.png");
    lawnMowerLabel->setPixmap(mower);
    lawnMowerLabel->setGeometry(150, 100, 50,50);
    lawnMowerLabel->setScaledContents(true);
    lawnMowerLabel->show();
    //objects.push_back(lawnMowerLabel);

    QLabel* holeLabel = new QLabel(parent);
    QPixmap hole(":/hole.png");
    holeLabel->setPixmap(hole);
    holeLabel->setGeometry(200,100,20,50);
    holeLabel->setScaledContents(true);
    holeLabel->show();
    //objects.push_back(holeLabel);

    //objects = {madDogLabel,lawnMowerLabel,holeLabel};
    }*/
