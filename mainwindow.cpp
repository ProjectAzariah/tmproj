#include <QKeyEvent>
#include <QRect>
#include <vector>
#include <QString>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
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
    connect(mb->easyBtn, SIGNAL(clicked()), SLOT (on_easyBtn_clicked()));
    connect(mb->mediumBtn, SIGNAL(clicked()), SLOT (on_mediumBtn_clicked()));
    connect(mb->hardBtn, SIGNAL(clicked()), SLOT (on_hardBtn_clicked()));
    connect(mb->quitBtn, SIGNAL(clicked()), SLOT(on_quitBtn_clicked()));
    connect(mb->playAgainBtn, SIGNAL(clicked()), SLOT(on_playAgainBtn_clicked()));
    connect(mb->pauseBtn, SIGNAL(clicked()), SLOT(on_pauseBtn_clicked()));
    connect(mb->resumeBtn, SIGNAL(clicked()), SLOT(on_resumeBtn_clicked()));
    connect(mb->saveBtn, SIGNAL(clicked()), SLOT(on_saveBtn_clicked()));
    connect(mb->loadBtn, SIGNAL(clicked()), SLOT(on_loadBtn_clicked()));
    connect(mb->cheatBtn, SIGNAL(clicked()), SLOT(on_cheatBtn_clicked()));

    //background timers
    backTimer = new QTimer(parent);
    backTimer->setInterval(50);
    connect(backTimer, SIGNAL(timeout()), this, SLOT(backTimerHit()));
    backTimer->start();
    //bool active = mb->backTimer->isActive();
    //this->backTimerHit();
    midTimer = new QTimer(parent);
    midTimer->setInterval(20);
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
    jumpTimer->setInterval(0);
    connect(jumpTimer, SIGNAL(timeout()), this, SLOT(jumpTimerHit()));

    didCollide = false;

    sounds = new sound();


    songs = {"play_the_game.mp3","Pixel adventures.mp3","random_silly_chip_song.mp3", "Flights of Fancy.mp3"};
    std::random_shuffle(songs.begin(),songs.end());
    song = songs[0];

    playList.addMedia(QUrl::fromLocalFile(QDir().absoluteFilePath(song)));

    playList.setPlaybackMode(QMediaPlaylist::Loop);
    playList.setCurrentIndex(1);
    player.setPlaylist(&playList);
    player.setVolume(50);
    player.play();


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
    mb->easyBtn->hide();
    mb->mediumBtn->hide();
    mb->hardBtn->hide();
    mb->loadBtn->hide();
    mb->loadBtn->setGeometry(510,270,120, 50);
    mb->introLabel->hide();
    mb->pauseBtn->show();
    mb->cheatBtn->show();



    backTimer->stop();
    midTimer->stop();
    frontTimer->stop();

    obstacleTimer = new QTimer(this);

    spawningTimer = new QTimer(this);

    if(mb->easyBtn->isChecked()){
        backTimer->setInterval(70);
        midTimer->setInterval(40);
        frontTimer->setInterval(10);
        obstacleTimer->setInterval(2);
        spawningTimer->setInterval(4000);
    } else if(mb->mediumBtn->isChecked()){
        backTimer->setInterval(50);
        midTimer->setInterval(15);
        frontTimer->setInterval(5);
        obstacleTimer->setInterval(1);
        spawningTimer->setInterval(2000);
    } else if (mb->hardBtn->isChecked()){
        backTimer->setInterval(30);
        midTimer->setInterval(5);
        frontTimer->setInterval(3);
        obstacleTimer->setInterval(.5);
        spawningTimer->setInterval(1000);
    }

    backTimer->start();
    midTimer->start();
    frontTimer->start();

    connect(obstacleTimer, SIGNAL(timeout()), this, SLOT(obstacleTimerHit()));
    obstacleTimer->start();


    connect(spawningTimer, SIGNAL(timeout()), this, SLOT(spawningTimerHit()));
    spawningTimer->start();


}

void MainWindow:: on_loadBtn_clicked(){
    Obstacle& o = Obstacle::instance();

    o.objects.clear();
    o.spawnedObstacles.clear();

    mb->endScreen->hide();
    mb->playAgainBtn->hide();
    mb->saveBtn->hide();
    mb->gameOverLabel->hide();
    cCat->cat->show();

    MainWindow::on_startBtn_clicked();
    obstacleTimer->setInterval(10);

    QFile data("data.txt");

    if(data.open(QIODevice::ReadOnly)){
            gameModel->setHealth(QString(data.readLine()).toInt());
            gameModel->setScore(QString(data.readLine()).toInt());
            mb->scoreLabel->setText("Score: " + QString::number(gameModel->getScore()));
            mb->healthLabel->setText("Health: " + QString::number(gameModel->getHealth()) +"%");
  }

}

void MainWindow:: on_pauseBtn_clicked(){
    mb->quitBtn->show();
    mb->saveBtn->show();
    mb->pauseBtn->hide();
    mb->cheatBtn->hide();
    mb->resumeBtn->show();

    obstacleTimer->stop();
    spawningTimer->stop();
    backTimer->stop();
    midTimer->stop();
    frontTimer->stop();
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
        QLabel * obst = o.spawnedObstacles[i];
        Object * obj = o.objects[i];

        int hip = obj->getHealthImpact();

        obst->move(obst->x() - 3, obst->y());

        if(!cheating){
            for (unsigned int j = 0; j < cCat->catSensors.size(); j++)
            {
                QLabel * s = cCat->catSensors.at(j);
                if (obst->geometry().intersects(s->geometry()) && !obj->isCollided)
                {
                    //std::cout<<"Cat Health: "<<gameModel->getHealth()<<", Enemy HIP: " <<hip<<endl;
                    hurtTimer->start();
                    gameModel->Hurt(hip);
                    //std::cout<<"Cat's new Health: "<< gameModel->getHealth()<<endl;
                    mb->healthLabel->setText("Health: " + QString::number(gameModel->getHealth()) +"%");
                    obj->isCollided=true;

                }

                if (gameModel->getHealth() <= 0)
                {
                    mb->youLoseLbl->setGeometry(cCat->cat->x(),cCat->cat->y() - 75, 100,100);
                    mb->youLoseLbl->show();
                    backTimer->stop();
                    midTimer->stop();
                    frontTimer->stop();
                    obstacleTimer->stop();
                    spawningTimer->stop();
                    cCat->catMovie->stop();
                 }
            }
        }
     }

     if(gameModel->getHealth() <= 0){
         cCat->cat->hide();
         for(size_t i = 0; i < Obstacle::instance().spawnedObstacles.size(); i++){
             Obstacle::instance().spawnedObstacles[i]->hide();
         }
         gameModel->doScores();
         gameModel->setHealth(100);
         mb->quitBtn->click();
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
        cCat->speed-=2;
        cCat->height+=2;
        if (cCat->counter % 10 == 0)
        {
            jumpTimer->setInterval(jumpTimer->interval() + 1);

        }

        cCat->cat->move(cCat->cat->x(), cCat->cat->y() - 2);
        for (unsigned int i = 0; i < cCat->catSensors.size(); i++)
        {
            QLabel * s = new QLabel(this);
            s = cCat->catSensors.at(i);
            s->move(s->x(), s->y() - 2);
        }
    }
    else if (cCat->height == 200)
    {
        cCat->isClimbing = false;
        cCat->isFalling = true;
        cCat->speed+=2;
        cCat->height-=2;

        cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 2);
        for (unsigned int i = 0; i < cCat->catSensors.size(); i++)
        {
            QLabel * s = new QLabel(this);
            s = cCat->catSensors.at(i);
            s->move(s->x(), s->y() + 2);
        }
    }
    else if (cCat->height == 0)
    {
        cCat->isLanded = true;
        cCat->isFalling = false;
        jumpTimer->setInterval(0);
        jumpTimer->stop();
    }
    else if (cCat->height < 200 && cCat->isFalling && !cCat->isLanded)
    {
        cCat->speed+=2;
        cCat->height-=2;
        if (cCat->counter % 10 == 0)
        {
            jumpTimer->setInterval(jumpTimer->interval() - 1);
        }


        cCat->cat->move(cCat->cat->x(), cCat->cat->y() + 2);
        for (unsigned int i = 0; i < cCat->catSensors.size(); i++)
        {
            QLabel * s = new QLabel(this);
            s = cCat->catSensors.at(i);
            s->move(s->x(), s->y() + 2);
        }

    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch(event->key())
    {
    case 87:
        sounds->jump.play();
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
            sounds->shoot.play();
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

void MainWindow::furTimerHit()
{
    Obstacle& o = Obstacle::instance();

    for (unsigned int i = 0 ; i < furBalls.size(); i++)
    {
        std::cout<<"looking at furball "<<i<<" to see if it hit anyone . . . .\n";
        QLabel * ball = furBalls[i];
        ball->move(ball->x() + 2,ball->y());
        for (unsigned int j = 0; j < o.spawnedObstacles.size(); j++)
            {
                std::cout<<" looking at enemy "<< j << " to see if furrball "<<i<<" destroyed it . . . .\n";
                QLabel * badGuy = new QLabel;
                badGuy = o.spawnedObstacles[i];
                if (/*enemyExists &&*/ ball->geometry().intersects(badGuy->geometry()))
                {
                    //delete ball;
                    delete badGuy;
                    std::cout<<"     furball "<<i<<" got enemy "<<j<<endl;
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
    mb->pauseBtn->hide();
    mb->logoLabel->hide();;
    mb->healthLabel->hide();
    mb->scoreLabel->hide();
    mb->quitBtn->hide();
    mb->cheatBtn->hide();
    mb->youLoseLbl->hide();
    mb->endScreen->show();
    mb->gameOverLabel->show();
    mb->endScreen->setText("Top Scores: \n" + gameModel->Print() + "Your " + mb->scoreLabel->text());
    mb->endScreen->setAlignment(Qt::AlignCenter);
    mb->playAgainBtn->show();
    mb->easyBtn->setGeometry(340,210,90,50);
    mb->easyBtn->show();
    mb->mediumBtn->setGeometry(440,210,125,50);
    mb->mediumBtn->show();
    mb->hardBtn->setGeometry(575,210,90,50);
    mb->hardBtn->show();
    mb->loadBtn->setGeometry(435,350,183, 80);
    mb->loadBtn->show();

    cCat->cat->hide();
    for(size_t i = 0; i < Obstacle::instance().spawnedObstacles.size(); i++){
        Obstacle::instance().spawnedObstacles[i]->hide();
    }

}

void MainWindow::on_playAgainBtn_clicked(){
    gameModel->setHealth(100);
    gameModel->setScore(0);
    mb->gameOverLabel->hide();
    mb->playAgainBtn->hide();
    mb->loadBtn->hide();
    mb->healthLabel->setText("Health: " + QString::number(gameModel->getHealth()) +"%");
    mb->scoreLabel->setText("Score: " + QString::number(gameModel->getScore()));
    mb->youLoseLbl->hide();
    mb->endScreen->hide();
    mb->saveBtn->hide();
    mb->easyBtn->hide();
    mb->mediumBtn->hide();
    mb->hardBtn->hide();

    Obstacle& o = Obstacle::instance();
    for(unsigned int i = 0; i < o.spawnedObstacles.size(); i++){
        delete o.spawnedObstacles[i];
    }
    o.spawnedObstacles.clear();

    for(unsigned int i = 0; i < o.objects.size(); i++){
        delete o.objects[i];
    }
    o.objects.clear();

    mb->logoLabel->show();
    mb->scoreLabel->show();
    mb->healthLabel->show();
    mb->pauseBtn->show();
    mb->cheatBtn->show();
    cCat->cat->show();
    backTimer->start();
    midTimer->start();
    frontTimer->start();
    cCat->catMovie->start();
    obstacleTimer->start();
    spawningTimer->start();
}

void MainWindow::on_resumeBtn_clicked(){
    mb->quitBtn->hide();
    mb->saveBtn->hide();
    mb->pauseBtn->show();
    mb->resumeBtn->hide();
    mb->cheatBtn->show();

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
    if(data.open(QIODevice::ReadWrite | QFile::Truncate)){
        QTextStream out(&data);
        out << gameModel->getHealth() << "\n";
        out << gameModel->getScore() << "\n";
    }
    gameModel->doScores();

mb->quitBtn->click();
}

void MainWindow::on_cheatBtn_clicked(){
    if(cheating){
        cheating = false;
    } else {
        cheating = true;
    }
}

/*void MainWindow::on_easyBtn_clicked()
{
    backTimer->stop();
    midTimer->stop();
    frontTimer->stop();
    backTimer->setInterval(70);
    midTimer->setInterval(40);
    frontTimer->setInterval(10);
    backTimer->start();
    midTimer->start();
    frontTimer->start();

    obstacleTimer->setInterval(2);
    spawningTimer->setInterval(4000);

}

void MainWindow::on_mediumBtn_clicked()
{
    backTimer->stop();
    midTimer->stop();
    frontTimer->stop();
    backTimer->setInterval(50);
    midTimer->setInterval(20);
    frontTimer->setInterval(5);
    backTimer->start();
    midTimer->start();
    frontTimer->start();

    obstacleTimer->setInterval(1);
    spawningTimer->setInterval(2000);


}

void MainWindow::on_hardBtn_clicked()
{
    backTimer->stop();
    midTimer->stop();
    frontTimer->stop();
    backTimer->setInterval(30);
    midTimer->setInterval(10);
    frontTimer->setInterval(3);
    backTimer->start();
    midTimer->start();
    frontTimer->start();

    obstacleTimer->setInterval(.5);
    spawningTimer->setInterval(1000);


}*/
