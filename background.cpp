#include "background.h"
#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>


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




}



