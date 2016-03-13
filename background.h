#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QLabel>
#include <QTimer>
#include <QMovie>
#include <QFile>
#include <QTextStream>

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
    //QLabel * cat;
    QMovie * catMovie;
public:
    explicit CuriousCat(QWidget *parent)
    {
        catMovie = new QMovie(":/cat.gif");
        label = new QLabel(parent);
        label->setMovie(catMovie);
        catMovie->start();
        label->setGeometry(50,176, 75, 75);
        label->setScaledContents(true);

        label->show();
    }

   /* //saves a game object
    void saveGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
            QTextStream out(&data);

            out << label->x() << "\n";
            out << label->y() << "\n";
        }
    }

    //loads a game object
    void loadGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
                QString str = data.readLine();
                int catx = str.toInt();
                QString str2 = data.readLine();
                int caty = str2.toInt();

                label->setGeometry(catx, caty, 75, 75);
        }
    }*/
};

class MadDog : Object
{
private:
    //QLabel * dog;
    QMovie * dogMovie;
public:
    explicit MadDog(QWidget *parent)
    {
        dogMovie = new QMovie(":/dog.gif");
        label = new QLabel(parent);
        label->setMovie(dogMovie);
        dogMovie->start();
        label->setGeometry(250,177, 75, 75);
        label->setScaledContents(true);

        label->show();

    }

    //saves a game object
    /*void saveGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
            QTextStream out(&data);

            out << label->x() << "\n";
            out << label->y() << "\n";
        }
    }

    //loads a game object
    void loadGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
                QString str = data.readLine();
                int x = str.toInt();
                QString str2 = data.readLine();
                int y = str2.toInt();

                label->setGeometry(x, y, 75, 75);
        }
    }*/
};

class LawnMower : Object
{
private:
    //QLabel * mower;
public:
    explicit LawnMower(QWidget * parent)
    {
        QPixmap mowerPic(":/lawnmower2.png");
        label = new QLabel(parent);
        label->setPixmap(mowerPic);
        label->setGeometry(350, 198, 50,50);
        label->setScaledContents(true);
        label->show();

    }

    //saves a game object
    /*void saveGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
            QTextStream out(&data);

            out << label->x() << "\n";
            out << label->y() << "\n";
        }
    }

    //loads a game object
    void loadGame() {
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
                QString str = data.readLine();
                int x = str.toInt();
                QString str2 = data.readLine();
                int y = str2.toInt();

                label->setGeometry(x, y, 50, 50);
        }
    }*/
};



#endif // BACKGROUND_H
