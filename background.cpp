#include "background.h"
#include "mainwindow.h"
#include <QWidget>
#include <QString>


MovingBackground::MovingBackground(QWidget *parent)
{

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
    logoLabel->setGeometry(325,0,350,60);
    logoLabel->setScaledContents(true);
    logoLabel->show();

    //makes gameOver label
    QPixmap logoTwo(":/gameover.png");
    gameOverLabel = new QLabel(parent);
    gameOverLabel->setPixmap(logoTwo);
    gameOverLabel->setGeometry(330,15,425,80);
    gameOverLabel->setScaledContents(true);
    gameOverLabel->hide();

    //score label
    scoreLabel = new QLabel(parent);
    scoreLabel->setText("Score: 0");

    QFont toggleFont = scoreLabel->font();
    toggleFont.setPointSize(16);
    toggleFont.setBold(true);

    scoreLabel->setFont(toggleFont);
    scoreLabel->setGeometry(760,0,150,50);
    scoreLabel->setScaledContents(true);
    scoreLabel->hide();

    //health label
    //eventually change to number of hearts
    healthLabel = new QLabel(parent);
    healthLabel->setText("Health: 100%");
    healthLabel->setGeometry(100,0,150,50);
    healthLabel->setScaledContents(true);
    healthLabel->setFont(toggleFont);
    healthLabel->hide();

    //makes intro box
    introLabel = new QTextEdit(parent);
    introLabel->setText("Corben the Curious Cat's curiousity has finally gotten the best of him and he has decided to go explore the dangerous outdoors. Help him avoid potential death by making him jump('W') to avoid the harmful dogs and lawnmowers and deadly holes and throw furballs('D') to defend himself before his health runs out. click START to begin!");
    introLabel->setGeometry(120,60,800,160);
    //set font
    introLabel->setAlignment(Qt::AlignCenter);
    QFont font = introLabel->font();
    font.setPointSize(18);
    introLabel->setFont(font);
    introLabel->setDisabled(true);
    introLabel->show();

    //makes start button
    QPixmap start(":/start.png");
    startBtn = new QPushButton(parent);    
    QIcon ButtonIcon(start);
    startBtn->setIcon(ButtonIcon);
    startBtn->setGeometry(370,270,120, 50);
    startBtn->setIconSize(start.rect().size());
    startBtn->show();

    //makes pause button
    pauseBtn = new QPushButton(parent);
    pauseBtn->setText("&PAUSE");
    pauseBtn->setFont(toggleFont);
    pauseBtn->setGeometry(390,75,90, 30);
    pauseBtn->hide();

    //makes cheat button
    cheatBtn = new QPushButton(parent);
    cheatBtn->setText("&CHEAT");
    cheatBtn->setFont(toggleFont);
    cheatBtn->setGeometry(525,75,90, 30);
    cheatBtn->hide();


    //makes save button
    QPixmap save(":/save.png");
    saveBtn = new QPushButton(parent);
    QIcon ButtonThreeIcon(save);
    saveBtn->setIcon(ButtonThreeIcon);
    saveBtn->setGeometry(380,175,235, 80);
    saveBtn->setIconSize(save.rect().size());
    saveBtn->hide();



    //makes quit button
    QPixmap quit(":/quit.png");
    quitBtn = new QPushButton(parent);
    QIcon ButtonFiveIcon(quit);
    quitBtn->setIcon(ButtonFiveIcon);
    quitBtn->setGeometry(420,275,155, 80);
    quitBtn->setIconSize(quit.rect().size());
    quitBtn->hide();

    //makes resume button
    QPixmap resume(":/resume.png");
    resumeBtn = new QPushButton(parent);
    QIcon ButtonFourIcon(resume);
    resumeBtn->setIcon(ButtonFourIcon);
    resumeBtn->setGeometry(420,75,155, 80);
    resumeBtn->setIconSize(quit.rect().size());
    resumeBtn->hide();

    //makes endScreen
    endScreen = new QTextEdit(parent);
    endScreen->setGeometry(225,100,600,350);
    endScreen->setDisabled(true);
    endScreen->setFont(toggleFont);
    endScreen->hide();

    //makes load button
    QPixmap load(":/load.png");
    loadBtn = new QPushButton(parent);
    QIcon ButtonSixIcon(load);
    loadBtn->setIcon(ButtonSixIcon);
    loadBtn->setGeometry(510,270,120, 50);
    loadBtn->setIconSize(load.rect().size());
    loadBtn->show();

    //play again button
    QPixmap playAgain(":/playagain.png");
    playAgainBtn = new QPushButton(parent);
    QIcon ButtonTwoIcon(playAgain);
    playAgainBtn->setIcon(ButtonTwoIcon);
    playAgainBtn->setGeometry(435,250,183, 80);
    playAgainBtn->setIconSize(playAgain.rect().size());
    playAgainBtn->hide();

    youLoseLbl = new QLabel(parent);
    youLoseLbl->setText("YOU LOSE");
    youLoseLbl->showFullScreen();
    youLoseLbl->setScaledContents(true);
    youLoseLbl->hide();

    //Difficulty Toggles

    easyBtn = new QRadioButton(parent);
    easyBtn->setText("EASY");
    easyBtn->setGeometry(330,210,90,50);
    easyBtn->setFont(toggleFont);
    easyBtn->toggle();
    easyBtn->show();

    mediumBtn = new QRadioButton(parent);
    mediumBtn->setText("MEDIUM");
    mediumBtn->setGeometry(430,210,125,50);
    mediumBtn->setFont(toggleFont);
    mediumBtn->show();

    hardBtn = new QRadioButton(parent);
    hardBtn->setText("HARD");
    hardBtn->setGeometry(565,210,90,50);
    hardBtn->setFont(toggleFont);
    hardBtn->show();
}
