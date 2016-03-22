#include "background.h"
#include "mainwindow.h"
#include <QWidget>
#include <QString>


MovingBackground::MovingBackground(QWidget *parent)
{
    //QVBoxLayout *layout = new QVBoxLayout;
        //layout->addWidget(formWidget);
        //setLayout(layout);

    //this creates the back-most picture for the background
    QPixmap background(":/Sky_back_layer.png");
    backLabel = new QLabel(parent);
    backLabel->setPixmap(background);
    backLabel->setGeometry(parent->geometry());
    backLabel->setScaledContents(true);
    backLabel->show();

    backLabel2 = new QLabel(parent);
    backLabel2->setPixmap(background);
    backLabel2->setGeometry(backLabel->geometry());
    backLabel2->move(backLabel->x() + backLabel->width(), backLabel->y());
    backLabel2->setScaledContents(true);
    backLabel2->show();

    //this creates the middle picture for the background
    QPixmap midground(":/Vegetation_(middle_layer).png");
    midLabel = new QLabel(parent);
    midLabel->setPixmap(midground);
    midLabel->setGeometry(parent->geometry());
    midLabel->setScaledContents(true);
    midLabel->show();

    midLabel2 = new QLabel(parent);
    midLabel2->setPixmap(midground);
    midLabel2->setGeometry(midLabel->geometry());
    midLabel2->move(midLabel->x() + midLabel->width(), midLabel->y());
    midLabel2->setScaledContents(true);
    midLabel2->show();

    //this creates the front-most picture for the background
    QPixmap foreground(":/Ground_(front_layer).png");
    frontLabel = new QLabel(parent);
    frontLabel->setPixmap(foreground);
    frontLabel->setGeometry(parent->geometry());
    frontLabel->setScaledContents(true);
    frontLabel->show();

    frontLabel2 = new QLabel(parent);
    frontLabel2->setPixmap(foreground);
    frontLabel2->setGeometry(frontLabel->geometry());
    frontLabel2->move(frontLabel->x() + frontLabel->width(), frontLabel->y());
    frontLabel2->setScaledContents(true);
    frontLabel2->show();

    //makes Game Logo
    QPixmap logo(":/logo.png");
    logoLabel = new QLabel(parent);
    logoLabel->setPixmap(logo);
    logoLabel->setGeometry(100,0,200,30);
    logoLabel->setScaledContents(true);
    logoLabel->show();

    //makes gameOver label
    QPixmap logoTwo(":/gameover.png");
    gameOverLabel = new QLabel(parent);
    gameOverLabel->setPixmap(logoTwo);
    gameOverLabel->setGeometry(100,0,210,50);
    gameOverLabel->setScaledContents(true);
    gameOverLabel->hide();

    //score label
    scoreLabel = new QLabel(parent);
    scoreLabel->setText("Score: 0");
    scoreLabel->setGeometry(310,0,80,30);
    scoreLabel->setScaledContents(true);
    scoreLabel->hide();

    //health label
    //eventually change to number of hearts
    healthLabel = new QLabel(parent);
    healthLabel->setText("Health: 100%");
    healthLabel->setGeometry(10,0,80,30);
    healthLabel->setScaledContents(true);
    healthLabel->hide();

    //makes intro box
    introLabel = new QTextEdit(parent);
    introLabel->setText("Corben the Curious Cat's curiousity has finally gotten the best of him and he has decided to go explore the dangerous outdoors. Help him avoid potential death by making him jump('W') to avoid the harmful dogs and lawnmowers and deadly holes and throw furballs('D') to defend himself before his health runs out. click START to begin!");
    introLabel->setGeometry(0,30,400,150);
    //set font
    introLabel->setAlignment(Qt::AlignCenter);
    QFont font = introLabel->font();
    font.setPointSize(12);
    introLabel->setFont(font);
    introLabel->setDisabled(true);
    introLabel->show();

    //makes start button
    QPixmap start(":/start.png");
    startBtn = new QPushButton(parent);    
    QIcon ButtonIcon(start);
    startBtn->setIcon(ButtonIcon);
    startBtn->setGeometry(150,185,120, 50);
    startBtn->setIconSize(start.rect().size());
    startBtn->show();

    //makes load button
    QPixmap load(":/load.png");
    loadBtn = new QPushButton(parent);
    QIcon ButtonSixIcon(load);
    loadBtn->setIcon(ButtonSixIcon);
    loadBtn->setGeometry(150,242,120, 50);
    loadBtn->setIconSize(start.rect().size());
    loadBtn->show();

    //makes pause button
    pauseBtn = new QPushButton(parent);
    pauseBtn->setText("&PAUSE");
    pauseBtn->setGeometry(160,40,90, 30);
    pauseBtn->hide();

    //makes resume button
    QPixmap resume(":/resume.png");
    resumeBtn = new QPushButton(parent);
    QIcon ButtonFourIcon(resume);
    resumeBtn->setIcon(ButtonFourIcon);
    resumeBtn->setGeometry(5,115,110, 50);
    resumeBtn->setIconSize(start.rect().size());
    resumeBtn->hide();


    //makes save button
    QPixmap save(":/save.png");
    saveBtn = new QPushButton(parent);
    QIcon ButtonThreeIcon(save);
    saveBtn->setIcon(ButtonThreeIcon);
    saveBtn->setGeometry(145,115,120, 50);
    saveBtn->setIconSize(start.rect().size());
    saveBtn->hide();



    //makes quit button
    QPixmap quit(":/quit.png");
    quitBtn = new QPushButton(parent);
    QIcon ButtonFiveIcon(quit);
    quitBtn->setIcon(ButtonFiveIcon);
    quitBtn->setGeometry(280,115,110, 50);
    quitBtn->setIconSize(start.rect().size());
    quitBtn->hide();

    //makes endScreen
    endScreen = new QTextEdit(parent);
    endScreen->setGeometry(80,60,240,150);
    endScreen->setDisabled(true);
    endScreen->hide();

    //play again button
    QPixmap playAgain(":/playagain.png");
    playAgainBtn = new QPushButton(parent);
    QIcon ButtonTwoIcon(playAgain);
    playAgainBtn->setIcon(ButtonTwoIcon);
    playAgainBtn->setGeometry(130,150,150, 45);
    playAgainBtn->setIconSize(start.rect().size());
    playAgainBtn->hide();
}
