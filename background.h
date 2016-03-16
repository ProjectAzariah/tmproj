#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QLabel>
#include <QTimer>
#include <QMovie>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QPushButton>

#include "mainwindow.h"
#include "object.h"

class MovingBackground : public QObject
{
    Q_OBJECT

public:
    //background labels
    QLabel * backLabel;
    QLabel * logoLabel;
    QLabel * backLabel2;
    QLabel * midLabel;
    QLabel * midLabel2;
    QLabel * frontLabel;
    QLabel * frontLabel2;
    QTextEdit * introLabel;
    QPushButton * startBtn;
    QLabel* scoreLabel;
    QLabel* healthLabel;
    QPushButton * quitBtn;
    QTextEdit * endScreen;
    QPushButton * playAgainBtn;




public:
    explicit MovingBackground(QWidget *parent);

};





#endif // BACKGROUND_H
