#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QLabel>
#include <QTimer>
#include <QMovie>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>

#include "mainwindow.h"
#include "object.h"

class MovingBackground : public QObject
{
    Q_OBJECT

public:
    //background labels
    QLabel * backLabel;
    QLabel * logoLabel;
    QLabel * gameOverLabel;
    QLabel * backLabel2;
    QLabel * midLabel;
    QLabel * midLabel2;
    QLabel * frontLabel;
    QLabel * frontLabel2;
    QTextEdit * introLabel;
    QPushButton* pauseBtn;
    QPushButton* cheatBtn;
    QPushButton * startBtn;
    QPushButton * loadBtn;
    QRadioButton * easyBtn;
    QRadioButton * mediumBtn;
    QRadioButton * hardBtn;
    QLabel* scoreLabel;
    QLabel* healthLabel;
    QPushButton * saveBtn;
    QPushButton * quitBtn;
    QPushButton * resumeBtn;
    QTextEdit * endScreen;
    QPushButton * playAgainBtn;
    QLabel * youLoseLbl;





public:
    explicit MovingBackground(QWidget *parent);

};





#endif // BACKGROUND_H
