#include <algorithm>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "object.h"
#include "event.h"
#include "background.h"
#include "mainwindow.h"


//loads an object
void Object::loadGame(QFile &file) {
    if(file.open(QIODevice::ReadWrite)){
            QString s = file.readLine();

            QString str = file.readLine();
            int x = str.toInt();
            QString str2 = file.readLine();
            int y = str2.toInt();

            this->setType(s.toStdString());
            this->setX(x);
            this->setY(y);
    }
}

CuriousCat::CuriousCat(QWidget *parent)
{
    setX(128);
    setY(450);
    setW(192);
    setH(192);
    setType("CuriousCat");
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

    QLabel * mouthSensor = new QLabel(parent);
    mouthSensor->setGeometry(mouthX, mouthY, sensorW, sensorH);
    catSensors.push_back(mouthSensor);


    QLabel * frontPawSensor = new QLabel(parent);
    frontPawSensor->setGeometry(frontPawX,frontPawY, sensorW,sensorH);
    catSensors.push_back(frontPawSensor);


    QLabel * backPawSensor = new QLabel(parent);
    backPawSensor->setGeometry(frontPawX - 75, frontPawY, sensorW, sensorH);
    catSensors.push_back(backPawSensor);
}

//saves a cat
void CuriousCat::saveGame(QTextStream &out) {
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
}

//saves a dog
void MadDog::saveGame(QTextStream &out) {

        out << "MadDog" << "\n";
        out << this->x << "\n";
        out << this->y << "\n";
}

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

//saves a lawnmower
void LawnMower::saveGame(QTextStream &out) {
        out << "Lawnmower" << "\n";
        out << this->x << "\n";
        out << this->y << "\n";
}

//saves a hole
void Hole::saveGame(QTextStream &out) {
        out << "Hole" << "\n";
        out << this->x << "\n";
        out << this->y << "\n";
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
