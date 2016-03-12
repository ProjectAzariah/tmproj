#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QLabel>
#include <QTimer>
#include <QMovie>
#include "object.h"

class MovingBackground
{

private:
    QLabel * backLabel;
    QLabel * backLabel2;
    QLabel * midLabel;
    QLabel * midLabel2;
//cat was on this line and cat movie on next
    QLabel * frontLabel;
    QLabel * frontLabel2;


public:
    explicit MovingBackground(QWidget *parent);

};

class CuriousCat : Object
{
private:
    QLabel * cat;
    QMovie * catMovie;
public:
    explicit CuriousCat(QWidget *parent)
    {
        catMovie = new QMovie(":/cat.gif");
        cat = new QLabel(parent);
        cat->setMovie(catMovie);
        catMovie->start();
        cat->setGeometry(50,176, 75, 75);
        cat->setScaledContents(true);

        cat->show();
    }




};

class MadDog : Object
{
private:
    QLabel * dog;
    QMovie * dogMovie;
public:
    explicit MadDog(QWidget *parent)
    {
        dogMovie = new QMovie(":/dog.gif");
        dog = new QLabel(parent);
        dog->setMovie(dogMovie);
        dogMovie->start();
        dog->setGeometry(250,177, 75, 75);
        dog->setScaledContents(true);

        dog->show();

    }
};

class LawnMower : Object
{
private:
    QLabel * mower;
public:
    explicit LawnMower(QWidget * parent)
    {
        QPixmap mowerPic(":/lawnmower2.png");
        mower = new QLabel(parent);
        mower->setPixmap(mowerPic);
        mower->setGeometry(350, 198, 50,50);
        mower->setScaledContents(true);
        mower->show();

    }
};



#endif // BACKGROUND_H
