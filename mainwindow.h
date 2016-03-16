#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "object.h"

class MovingBackground;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MovingBackground *mb;
    CuriousCat * cCat;
    QLabel * furBall;
    std::vector<QLabel*> furBalls;
    int score = 0;
    int health = 100;

    //background timers
    QTimer * backTimer;
    QTimer * midTimer;
    QTimer * frontTimer;
    QTimer * obstacleTimer;
    QTimer * spawningTimer;
    QTimer * furtime;

public slots:
    void on_startBtn_clicked();
    void on_quitBtn_clicked();
    void backTimerHit();
    void midTimerHit();
    void frontTimerHit();
    void obstacleTimerHit();
    void spawningTimerHit();
    void furTimeHit();






private:
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent * event);

};

#endif // MAINWINDOW_H
