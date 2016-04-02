#include <QKeyEvent>
#include <QRect>
#include <vector>
#include <QString>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "background.h"
#include "event.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gameModel = GameModel::instance();

    ui->setupUi(this);
    mb = new MovingBackground(this);

    connect(mb->startBtn, SIGNAL(clicked()), SLOT(on_startBtn_clicked()));
    connect(mb->quitBtn, SIGNAL(clicked()), SLOT(on_quitBtn_clicked()));
    connect(mb->playAgainBtn, SIGNAL(clicked()), SLOT(on_playAgainBtn_clicked()));
    connect(mb->pauseBtn, SIGNAL(clicked()), SLOT(on_pauseBtn_clicked()));
    connect(mb->resumeBtn, SIGNAL(clicked()), SLOT(on_resumeBtn_clicked()));
    connect(mb->saveBtn, SIGNAL(clicked()), SLOT(on_saveBtn_clicked()));
    connect(mb->loadBtn, SIGNAL(clicked()), SLOT(on_loadBtn_clicked()));

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


    //furballtimer
    furTimer = new QTimer(this);
    furTimer->setInterval(10);
    connect(furTimer, SIGNAL(timeout()), this, SLOT(furTimerHit()));
    //furTimer->start();
    hurtTimer = new QTimer(this);

    //hurtTimer
    hurtTimer->setInterval(100);
    connect(hurtTimer, SIGNAL(timeout()),this,SLOT(hurtTimerHit()));

    hurtCounter = 0;

    //jumpTimer
    jumpTimer = new QTimer(this);
    jumpTimer->setInterval(1);
    connect(jumpTimer, SIGNAL(timeout()), this, SLOT(jumpTimerHit()));

    didCollide = false;

    cCat =  new CuriousCat(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::backTimerHit()
{
    if (mb->backLabel->x() >= -1024 && mb->backLabel2->x() >= -1024)
    {
        mb->backLabel->move(mb->backLabel->x() - 1, mb->backLabel->y());
        mb->backLabel2->move(mb->backLabel2->x() - 1, mb->backLabel2->y());
    }
    else if (mb->backLabel->x() < -1024)
    {
        mb->backLabel->hide();
        mb->backLabel->move(mb->backLabel->x() + (mb->backLabel->width() * 2) - 1 , mb->backLabel->y());
        mb->backLabel2->move(mb->backLabel2->x() - 1, mb->backLabel2->y());
        mb->backLabel->show();
    }
    else if (mb->backLabel2->x() < -1024)
    {
        mb->backLabel2->hide();
        mb->backLabel2->move(mb->backLabel2->x() + (mb->backLabel2->width() * 2) - 1 , mb->backLabel2->y());
        mb->backLabel->move(mb->backLabel->x() - 1, mb->backLabel->y());
        mb->backLabel2->show();
    }


}

void MainWindow::midTimerHit()
{
    if (mb->midLabel->x() >= -1024 && mb->midLabel2->x() >= -1024)
    {
        mb->midLabel->move(mb->midLabel->x() - 1, mb->midLabel->y());
        mb->midLabel2->move(mb->midLabel2->x() - 1, mb->midLabel2->y());
    }
    else if (mb->midLabel->x() < -1024)
    {
        mb->midLabel->hide();
        mb->midLabel->move(mb->midLabel->x() + (mb->midLabel->width() * 2) -1 , mb->midLabel->y());
        mb->midLabel2->move(mb->midLabel2->x() - 1, mb->midLabel2->y());
        mb->midLabel->show();
    }
    else if (mb->midLabel2->x() < -1024)
    {
        mb->midLabel2->hide();
        mb->midLabel2->move(mb->midLabel2->x() + (mb->midLabel2->width() * 2) - 1, mb->midLabel2->y());
        mb->midLabel->move(mb->midLabel->x() - 1, mb->midLabel->y());
        mb->midLabel2->show();
    }


}

void MainWindow::frontTimerHit()
{
    if (mb->frontLabel->x() >= -1024 && mb->frontLabel2->x() >= -1024)
    {
        mb->frontLabel->move(mb->frontLabel->x() - 1, mb->frontLabel->y());
        mb->frontLabel2->move(mb->frontLabel2->x() - 1, mb->frontLabel2->y());
    }
    else if (mb->frontLabel->x() < -1024)
    {
        mb->frontLabel->hide();
        mb->frontLabel->move(mb->frontLabel->x() + (mb->frontLabel->width() * 2) - 1, mb->frontLabel->y());
        mb->frontLabel2->move(mb->frontLabel2->x() - 1, mb->frontLabel2->y());
        mb->frontLabel->show();
    }
    else if (mb->frontLabel2->x() < -1024)
    {
        mb->frontLabel2->hide();
        mb->frontLabel2->move(mb->frontLabel2->x() + (mb->frontLabel2->width() * 2) - 1, mb->frontLabel2->y());
        mb->frontLabel->move(mb->frontLabel->x() - 1, mb->frontLabel->y());
        mb->frontLabel2->show();
    }

}

void MainWindow::on_startBtn_clicked(){
    started=true;
    mb->healthLabel->show();
    mb->scoreLabel->show();
    mb->startBtn->setDisabled(true);
    mb->startBtn->hide();
    mb->loadBtn->hide();
    mb->introLabel->hide();
    mb->pauseBtn->show();

    obstacleTimer = new QTimer(this);
    obstacleTimer->setInterval(2);
    connect(obstacleTimer, SIGNAL(timeout()), this, SLOT(obstacleTimerHit()));
    obstacleTimer->start();

    spawningTimer = new QTimer(this);
    spawningTimer->setInterval(3000);
    connect(spawningTimer, SIGNAL(timeout()), this, SLOT(spawningTimerHit()));
    spawningTimer->start();

    Obstacle& o = Obstacle::instance();

    MadDog();
    LawnMower();
    Hole();
    o.spawnObstacles(this);
}
//ATTENTION: THIS IS WHERE I PUT THE CODE FOR THE GAME TO STOP WHEN THE CAT RUNS INTO

void MainWindow:: on_loadBtn_clicked(){
    started=true;
    mb->healthLabel->show();
    mb->scoreLabel->show();
    mb->startBtn->setDisabled(true);
    mb->startBtn->hide();
    mb->loadBtn->hide();
    mb->introLabel->hide();
    mb->pauseBtn->show();

    obstacleTimer = new QTimer(this);
    obstacleTimer->setInterval(5);
    connect(obstacleTimer, SIGNAL(timeout()), this, SLOT(obstacleTimerHit()));
    obstacleTimer->start();

    spawningTimer = new QTimer(this);
    spawningTimer->setInterval(2000);
    connect(spawningTimer, SIGNAL(timeout()), this, SLOT(spawningTimerHit()));
    spawningTimer->start();

    Obstacle& o = Obstacle::instance();

    MadDog();
    LawnMower();
    Hole();

    o.obstacles.clear();

    QFile data("data.txt");

    if(data.open(QIODevice::ReadWrite)){
            QString num = data.readLine();
            int numObjs = num.toInt();
            gameModel->setScore(QString(data.readLine()).toInt());
            gameModel->setScore(QString(data.readLine()).toInt());
            Object* obj = new Object();

            for(int i=0; i < numObjs; i++){
                obj->loadGame(data);
                if(obj->getType() == "MadDog"){
                    QLabel * madDogLabel = new QLabel(this);
                    QMovie * dogMovie = new QMovie(":/dog.gif");
                    madDogLabel->setMovie(dogMovie);
                    madDogLabel->setGeometry(this->width(),200,50,50);
                    madDogLabel->setScaledContents(true);
                    dogMovie->start();
                    madDogLabel->hide();
                    //madDogLabel->show();
                    o.obstacles.push_back(madDogLabel);
                }else if(obj->getType() == "Lawnmower"){
                    QLabel* lawnMowerLabel = new QLabel(this);
                    QPixmap mower(":/lawnmower2.png");
                    lawnMowerLabel->setPixmap(mower);
                    lawnMowerLabel->setGeometry(this->width(), 201, 50,50);
                    lawnMowerLabel->setScaledContents(true);
                    lawnMowerLabel->hide();
                    //lawnMowerLabel->show();
                    o.obstacles.push_back(lawnMowerLabel);
                }else if(obj->getType() == "Hole"){
                    QLabel* holeLabel = new QLabel(this);
                    QPixmap hole(":/hole.png");
                    holeLabel->setPixmap(hole);
                    holeLabel->setGeometry(this->width(),202,50,300);
                    holeLabel->setScaledContents(true);
                    holeLabel->hide();
                    //holeLabel->show();
                    o.obstacles.push_back(holeLabel);
                    //std::random_shuffle(o.obstacles.begin(), o.obstacles.end());
                }
                }
            }


}

void MainWindow:: on_pauseBtn_clicked(){
    mb->quitBtn->show();
    mb->saveBtn->show();
    mb->pauseBtn->hide();
    mb->resumeBtn->show();

    obstacleTimer->stop();
    spawningTimer->stop();
    backTimer->stop();
    midTimer->stop();
    frontTimer->stop();
    obstacleTimer->stop();
    spawningTimer->stop();
    //furtime->stop();
    //cCat->catMovie->stop();
    /*for(int i = 0; i < Obstacle::instance().obstacles.size(); i++){
        QLabel * ob = Obstacle::instance().obstacles[i];
        if(!(ob->movie())){
            ob->movie()->stop();
        }
    }*/
}

void MainWindow::obstacleTimerHit()
{
    Obstacle& o = Obstacle::instance();

    for (unsigned int i = 0; i < o.spawnedObstacles.size(); i++)
    {
        QLabel * obst = new QLabel;
        Object * obj = new Object;
        obst = o.spawnedObstacles[i];
        obj = o.objects[i];
        //std::string str = obj->getType();
        //std::cout << str << "\n";
        int hip = obj->getHealthImpact();
        //std::cout << hip <<  "\n";
        //std::cout << "CCAT HEALTH IS FIRST AT:   " << cCat->health << "\n";
        obst->move(obst->x() - 1, obst->y());
//HERE IS COMMENTED OUT THE CODE FOR KILLING CAT AND STOPPING GAME
        for (unsigned int j = 0; j < cCat->catSensors.size(); j++)
        {
            QLabel * s = new QLabel(this);
            s = cCat->catSensors.at(j);
            if (obst->geometry().intersects(s->geometry()) && !obj->isCollided)
            {
                hurtTimer->start();

                //didCollide = true;
                obj->isCollided = true;
                std::cout << "WE HAVE IMPACT" << "\n";
                std::cout << "CCAT HEALTH BEFORE HIP : " << cCat->health << "\n";
                cCat->health -= hip;
                std::cout << "CCAT HEALTH IS AT :   " << cCat->health << "\n";
                //hurtTimerHit();
                //cCat->health = cCat->health - obj->getHealthImpact();
                //break;
            }

            if (cCat->health <= 0)
            {
                std::cout << cCat->health << " IS CATS CURRENT HEALTH"<< "\n";
                end = new QLabel(this);
                end->setText("YOU LOSE");
                end->showFullScreen();
                end->setGeometry(cCat->cat->x(),cCat->cat->y() - 75, 100,100);
                end->setScaledContents(true);
                end->show();
                backTimer->stop();
                midTimer->stop();
                frontTimer->stop();
                obstacleTimer->stop();
                spawningTimer->stop();
                cCat->catMovie->stop();

             }
                /*else if (cCat->health > 0)
                {
                    hurtTimer->start();
                }*/

            }
        }



}

void MainWindow::hurtTimerHit()
{
    hurtCounter++;

    if (cCat->cat->isVisible() && hurtCounter < 12)
    {
        cCat->cat->hide();
    }
    else if (!cCat->cat->isVisible() && hurtCounter < 12)
    {
        cCat->cat->show();
    }
    if (hurtCounter == 12)
    {
        cCat->cat->show();
        hurtCounter = 0;
        hurtTimer->stop();
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

    if (started){
        gameModel->AddScore();
    }
    mb->scoreLabel->setText("Score: "+ QString::number(gameModel->getScore()));
}

void MainWindow::jumpTimerHit()
{
    cCat->counter++;
    if (cCat->height < 200 && cCat->isClimbing)
    {
        cCat->speed--;
        cCat->height++;
        if (cCat->counter % 20 == 0)
        {
            jumpTimer->setInterval(jumpTimer->interval() + 1);
            qDebug() << jumpTimer->interval() << endl;

        }

        cCat->cat->move(cCat->cat->x(), cCat->cat->y() - 1);
        for (unsigned int i = 0; i < cCat->catSensors.size(); i++)
        {
            QLabel * s = new QLabel(this);
            s = cCat->catSensors.at(i);
            s->move(s->x(), s->y() - 1);
        }
    }
    else if (cCat->height == 200)
    {
        cCat->isClimbing = false;
        cCat->isFalling = true;
        cCat->speed++;
        cCat->height--;

        cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 1);
    }
    else if (cCat->height == 0)
    {
        cCat->isLanded = true;
        cCat->isFalling = false;
        //jumpTimer->setInterval(1);
        jumpTimer->stop();
    }
    else if (cCat->height < 200 && cCat->isFalling && !cCat->isLanded)
    {
        cCat->speed++;
        cCat->height--;
        if (cCat->counter % 20 == 0)
        {
            jumpTimer->setInterval(jumpTimer->interval() - 1);
            qDebug() << jumpTimer->interval() << endl;
        }


        cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 1);
        for (unsigned int i = 0; i < cCat->catSensors.size(); i++)
        {
            QLabel * s = new QLabel(this);
            s = cCat->catSensors.at(i);
            s->move(s->x(), s->y() + 1);
        }

    }

    /*if (cCat->gravity < 100)
    {
        cCat->gravity += 1;
        cCat->cat->move(cCat->cat->x(),cCat->cat->y() - 1);
        if (cCat->gravity == 100)
        {
            jumpTimer->setInterval(1000);
        }
    }

    else if (cCat->gravity >= 100)
    {
        jumpTimer->setInterval(5);
        //cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 76);
        //cCat->gravity -= 1;
        if (cCat->cat->y() != 176)
        {
            cCat->cat->move(cCat->cat->x(),cCat->cat->y() + 1);

        }
        else
        {
            cCat->gravity = 0;
            jumpTimer->stop();
        }

    }*/
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    //qDebug() << event->key();   //uncomment this line if you want to figure out what key number a key is for the case in the
    switch(event->key())
    {
    case 87:
        if (cCat->isLanded)
        {
            cCat->isLanded = false;
            cCat->isClimbing = true;
        }

        jumpTimer->start();

        //cCat->cat->move(cCat->cat->x(), cCat->cat->y() - 76);
        //cCat->catMovie->stop();



        break;
    case 68:
        if (furBalls.size() < 2)
        {
            furBall = new QLabel(this);
            QPixmap fBall(":/furball2.png");
            furBall->setPixmap(fBall);
            furBall->setScaledContents(true);
            furBall->setGeometry(cCat->cat->x() + 145 ,cCat->cat->y() + 90  ,35,35);
            furBall->show();
            furBalls.push_back(furBall);
            furTimer->start();
            this->furTimerHit();
        }

        break;
    }





}
void MainWindow::keyReleaseEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    case 87:
       // jumpTimer->stop();
        //cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 76);
        //wcCat->catMovie->start();


        break;
    case 68:
        break;
    }


}

void MainWindow::furTimerHit()
{
    Obstacle& o = Obstacle::instance();

    for (unsigned int i = 0 ; i < furBalls.size(); i++)
    {
        QLabel * ball = furBalls[i];
        ball->move(ball->x() + 2,ball->y());
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
                if (/*enemyExists && */badGuy->x() < -75)
                {
                    delete badGuy;
                    o.spawnedObstacles.erase(o.spawnedObstacles.cbegin());
                    badGuy = new QLabel(this);
                }
                if (ball->x() > this->width())
                {
                    delete ball;
                    furBalls.erase(furBalls.cbegin());
                    ball = new QLabel(this);
                }
            }
    }
}

void MainWindow::on_quitBtn_clicked(){
    mb->resumeBtn->hide();
    mb->logoLabel->hide();;
    mb->healthLabel->hide();
    mb->scoreLabel->hide();
    mb->quitBtn->hide();
    mb->endScreen->show();
    mb->gameOverLabel->show();
    mb->endScreen->setText("Top Scores: ------\n                ------\n                 ------\nYour Score:" + mb->scoreLabel->text());
    mb->playAgainBtn->show();

    cCat->cat->hide();
    for(size_t i = 0; i < Obstacle::instance().obstacles.size(); i++){
        Obstacle::instance().obstacles[i]->hide();
    }

}

void MainWindow::on_playAgainBtn_clicked(){
    gameModel->setHealth(100);
    gameModel->setScore(0);
    mb->gameOverLabel->hide();
    mb->logoLabel->show();
    mb->endScreen->hide();
    mb->playAgainBtn->hide();
    mb->scoreLabel->setText("Score: " + QString::number(gameModel->getScore()));
    mb->scoreLabel->show();
    mb->healthLabel->show();
    mb->quitBtn->hide();
    mb->saveBtn->hide();
    mb->resumeBtn->hide();
    cCat->cat->show();
    backTimer->start();
    midTimer->start();
    frontTimer->start();
    mb->startBtn->clicked();
}

void MainWindow::on_resumeBtn_clicked(){
    mb->quitBtn->hide();
    mb->saveBtn->hide();
    mb->pauseBtn->show();
    mb->resumeBtn->hide();

    obstacleTimer->start();
    spawningTimer->start();
    backTimer->start();
    midTimer->start();
    frontTimer->start();
    obstacleTimer->start();
    spawningTimer->start();
    //furtime->start();
}

void MainWindow::on_saveBtn_clicked(){
        QFile data("data.txt");
        if(data.open(QIODevice::ReadWrite)){
            QTextStream out(&data);

            out << Obstacle::instance().objects.size() << "\n";
            out << gameModel->getHealth() << "\n";
            out << gameModel->getScore() << "\n";

            for(Object *obj : Obstacle::instance().objects) {
                obj->saveGame(out);
            }
        }

    mb->quitBtn->click();
}
