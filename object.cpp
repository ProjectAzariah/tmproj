#include <algorithm>
#include <string>

#include "object.h"
#include "event.h"
#include "background.h"
#include "mainwindow.h"


//loads an object
void Object::loadGame() {
    QFile data("data.txt");
    if(data.open(QIODevice::ReadWrite)){
            QString s = data.readLine();

            QString str = data.readLine();
            int x = str.toInt();
            QString str2 = data.readLine();
            int y = str2.toInt();

            this->setType(s.toStdString());
            this->setX(x);
            this->setY(y);
    }
}

CuriousCat::CuriousCat(QWidget *parent)
{
    setX(50);
    setY(176);
    setW(75);
    setH(75);
    setType("CuriousCat");


    catMovie = new QMovie(":/cat.gif");
    cat = new QLabel(parent);
    cat->setMovie(catMovie);
    catMovie->start();
    cat->setGeometry(50,176, 75, 75);
    cat->setScaledContents(true);

    cat->show();
}

MadDog::MadDog()
{
    setX(250);
    setY(177);
    setW(75);
    setH(75);
    setType("MadDog");
    setHealthImpact(50);
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

//saves a dog
void MadDog::saveGame() {
    QFile data("data.txt");
    if(data.open(QIODevice::ReadWrite)){
        QTextStream out(&data);

        out << this->x << "\n";
        out << this->y << "\n";
    }
}



void MadDog::dogTimerHit()
{
    /*for (unsigned int i = 0; i < spawnedEns.size(); i++)
    {
        QLabel * enemy = new QLabel;
        enemy = spawnedEns[i];
        enemy->move(enemy->x() - 1, enemy->y());
        if (enemy->geometry().intersects(cat->geometry()) && end == nullptr)
        {
            end = new QLabel(this);
            end->setText("YOU LOSE");
            end->showFullScreen();
            end->setGeometry(cat->x(),cat->y() - 75, 100,100);
            end->setScaledContents(true);
            end->show();
        }
    }*/
}

LawnMower::LawnMower()
{
    setX(350);
    setY(198);
    setW(50);
    setH(50);
    setType("LawnMower");
    setHealthImpact(25);
    /*QPixmap mowerPic(":/lawnmower2.png");
    mower = new QLabel(parent);
    mower->setPixmap(mowerPic);
    mower->setGeometry(350, 198, 50,50);
    mower->setScaledContents(true);
    mower->show();
    Obstacle& o = Obstacle::instance();

    o.obstacles.push_back(mower);

    //objects.push_back(mower);*/

}

//saves a lawnmower
void LawnMower::saveGame() {
    QFile data("data.txt");
    if(data.open(QIODevice::ReadWrite)){
        QTextStream out(&data);

        out << this->x << "\n";
        out << this->y << "\n";
    }
}


    //saves a hole
    void Hole::saveGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
            QTextStream out(&data);

            out << this->x << "\n";
            out << this->y << "\n";
        }
    }

Hole::Hole()
{
    setX(150);
    setY(208);
    setW(75);
    setH(300);
    setType("Hole");
    setHealthImpact(100);
    /*QPixmap holePic(":/hole.png");
    hole = new QLabel(parent);
    hole->setPixmap(holePic);
    hole->setGeometry(150, 208, 75,300);
    hole->setScaledContents(true);
    hole->show();
    Obstacle& o = Obstacle::instance();

    o.obstacles.push_back(hole);*/
    //objects.push_back(hole);
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
