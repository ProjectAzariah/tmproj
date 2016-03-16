#include <QKeyEvent>
#include <QRect>
#include <vector>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "background.h"
#include "event.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mb = new MovingBackground(this);
    //background timers
    backTimer = new QTimer(parent);
    backTimer->setInterval(70);
    connect(backTimer, SIGNAL(timeout()), this, SLOT(backTimerHit()));
    backTimer->start();
    //bool active = mb->backTimer->isActive();
    //this->backTimerHit();
    midTimer = new QTimer(parent);
    midTimer->setInterval(40);
    connect(midTimer, SIGNAL(timeout()), this, SLOT(midTimerHit()));
    midTimer->start();
    //this->midTimerHit();
    frontTimer = new QTimer(parent);
    frontTimer->setInterval(10);
    connect(frontTimer, SIGNAL(timeout()), this, SLOT(frontTimerHit()));
    frontTimer->start();

    //obstacle timers
    obstacleTimer = new QTimer(this);
    obstacleTimer->setInterval(10);
    connect(obstacleTimer, SIGNAL(timeout()), this, SLOT(obstacleTimerHit()));
    obstacleTimer->start();

    //spawining timers
    spawningTimer = new QTimer(this);
    spawningTimer->setInterval(1750);
    connect(spawningTimer, SIGNAL(timeout()), this, SLOT(spawningTimerHit()));
    spawningTimer->start();

    //furballtimer
    furtime = new QTimer(this);
    furtime->setInterval(10);
    connect(furtime, SIGNAL(timeout()), this, SLOT(furTimeHit()));

    Obstacle& o = Obstacle::instance();
/*
    o.obstacleTimer = new QTimer(this);
    o.obstacleTimer->setInterval(10);
    connect(o.obstacleTimer, SIGNAL(timeout()), this, SLOT(enemyTimerHit()));

*/
    cCat =  new CuriousCat(this);
    MadDog();
    LawnMower();
    Hole();
    o.spawnObstacles(this);
    //o.spawnObstacles(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::backTimerHit()
{
    if (mb->backLabel->x() >= -400 && mb->backLabel2->x() >= -400)
    {
        mb->backLabel->move(mb->backLabel->x() - 1, mb->backLabel->y());
        mb->backLabel2->move(mb->backLabel2->x() - 1, mb->backLabel2->y());
    }
    else if (mb->backLabel->x() < -400)
    {
        mb->backLabel->hide();
        mb->backLabel->move(mb->backLabel->x() + (mb->backLabel->width() * 2) - 1 , mb->backLabel->y());
        mb->backLabel2->move(mb->backLabel2->x() - 1, mb->backLabel2->y());
        mb->backLabel->show();
    }
    else if (mb->backLabel2->x() < -400)
    {
        mb->backLabel2->hide();
        mb->backLabel2->move(mb->backLabel2->x() + (mb->backLabel2->width() * 2) - 1 , mb->backLabel2->y());
        mb->backLabel->move(mb->backLabel->x() - 1, mb->backLabel->y());
        mb->backLabel2->show();
    }


}

void MainWindow::midTimerHit()
{
    if (mb->midLabel->x() >= -400 && mb->midLabel2->x() >= -400)
    {
        mb->midLabel->move(mb->midLabel->x() - 1, mb->midLabel->y());
        mb->midLabel2->move(mb->midLabel2->x() - 1, mb->midLabel2->y());
    }
    else if (mb->midLabel->x() < -400)
    {
        mb->midLabel->hide();
        mb->midLabel->move(mb->midLabel->x() + (mb->midLabel->width() * 2) -1 , mb->midLabel->y());
        mb->midLabel2->move(mb->midLabel2->x() - 1, mb->midLabel2->y());
        mb->midLabel->show();
    }
    else if (mb->midLabel2->x() < -400)
    {
        mb->midLabel2->hide();
        mb->midLabel2->move(mb->midLabel2->x() + (mb->midLabel2->width() * 2) - 1, mb->midLabel2->y());
        mb->midLabel->move(mb->midLabel->x() - 1, mb->midLabel->y());
        mb->midLabel2->show();
    }


}

void MainWindow::frontTimerHit()
{
    if (mb->frontLabel->x() >= -400 && mb->frontLabel2->x() >= -400)
    {
        mb->frontLabel->move(mb->frontLabel->x() - 1, mb->frontLabel->y());
        mb->frontLabel2->move(mb->frontLabel2->x() - 1, mb->frontLabel2->y());
    }
    else if (mb->frontLabel->x() < -400)
    {
        mb->frontLabel->hide();
        mb->frontLabel->move(mb->frontLabel->x() + (mb->frontLabel->width() * 2) - 1, mb->frontLabel->y());
        mb->frontLabel2->move(mb->frontLabel2->x() - 1, mb->frontLabel2->y());
        mb->frontLabel->show();
    }
    else if (mb->frontLabel2->x() < -400)
    {
        mb->frontLabel2->hide();
        mb->frontLabel2->move(mb->frontLabel2->x() + (mb->frontLabel2->width() * 2) - 1, mb->frontLabel2->y());
        mb->frontLabel->move(mb->frontLabel->x() - 1, mb->frontLabel->y());
        mb->frontLabel2->show();
    }


}

void MainWindow::on_startBtn_clicked(){
    mb->startBtn->setDisabled(true);
    mb->startBtn->hide();

    mb->introLabel->hide();
}

void MainWindow::obstacleTimerHit()
{
    Obstacle& o = Obstacle::instance();

    for (unsigned int i = 0; i < o.spawnedObstacles.size(); i++)
    {
        QLabel * obst = new QLabel;
        obst = o.spawnedObstacles[i];
        obst->move(obst->x() - 1, obst->y());
    }

}

void MainWindow::spawningTimerHit()
{
    Obstacle& o = Obstacle::instance();

    //enemyExists = true;
    QLabel * obst = new QLabel(this);
    obst = o.spawnObstacles(this);
    obst->show();
    obstacleTimer->start();
    //label->move(0, label->y());
    this->obstacleTimerHit();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    //qDebug() << event->key();   //uncomment this line if you want to figure out what key number a key is for the case in the
    switch(event->key())
    {
    case 87:



        cCat->cat->move(cCat->cat->x(), cCat->cat->y() - 76);
        cCat->catMovie->stop();
        break;
    case 68:
        furBall = new QLabel(this);
        QPixmap fBall(":/furball2.png");
        furBall->setPixmap(fBall);
        furBall->setScaledContents(true);
        furBall->setGeometry(cCat->cat->x() + 35 ,cCat->cat->y() + 30  ,30,20);
        furBall->show();
        furBalls.push_back(furBall);
        //QTimer * flameTime = new QTimer(this);
        //flameTime->setInterval(20);
        //connect(flameTime, SIGNAL(timeout()), this, SLOT(flameTimeHit()));
        furtime->start();
        //label->move(0, label->y());
        this->furTimeHit();
        break;
    }





}
void MainWindow::keyReleaseEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case 87:
        cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 76);
        cCat->catMovie->start();
        break;
    case 68:
        break;
    }


}

void MainWindow::furTimeHit()
{
    Obstacle& o = Obstacle::instance();

    for (unsigned int i = 0 ; i < furBalls.size(); i++)
    {
        QLabel * ball = furBalls[i];
        ball->move(ball->x() + 2 , ball->y());
        /*if (enemyExists == false)
        {

        }
        else if (enemyExists)
        {*/
            for (unsigned int j = 0; j < o.spawnedObstacles.size(); j++)
            {
                QLabel * badGuy = new QLabel;
                badGuy = o.spawnedObstacles[i];
                if (/*enemyExists &&*/ ball->geometry().intersects(badGuy->geometry()))
                {
                    //delete ball;
                    delete badGuy;
                    o.spawnedObstacles.erase(o.spawnedObstacles.cbegin());
                    furBalls.erase(furBalls.cbegin());
                    //ball = new QLabel(this);
                    badGuy = new QLabel(this);
                    delete ball;
                    ball = new QLabel(this);
                }
                else if (/*enemyExists && */badGuy->x() < -75)
                {
                    delete badGuy;
                    o.spawnedObstacles.erase(o.spawnedObstacles.cbegin());
                    badGuy = new QLabel(this);
                }
                else if (ball->x() > this->width())
                {
                    delete ball;
                    furBalls.erase(furBalls.cbegin());
                    ball = new QLabel(this);
                }
            }
       // }


        /*else if (ball->geometry().intersects(dog->geometry()))
        {
            delete dog;
            //dog->deleteLater();
            dog = new QLabel(this);

        }*/
    }


}



