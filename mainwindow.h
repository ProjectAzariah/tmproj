#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <vector>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "sound.h"
#include "object.h"
#include "gamemodel.h"

class MovingBackground;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    GameModel* gameModel;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MovingBackground *mb;
    CuriousCat * cCat;
    sound * sounds;

    QLabel * furBall;
    std::vector<QLabel*> furBalls;
    static int score, health ;
    bool started = false;
    bool cheating = false;

    //background timers
    QTimer * backTimer;
    QTimer * midTimer;
    QTimer * frontTimer;
    QTimer * obstacleTimer;
    bool didCollide;
    QTimer * spawningTimer;
    QTimer * furTimer;

    QTimer * jumpTimer;

    QTimer * hurtTimer;
    int hurtCounter;

<<<<<<< HEAD
    QLabel * end = nullptr;
    std::vector<QString> songs;
    QString song;

    QMediaPlayer player;
    QMediaPlaylist  playList;

=======
>>>>>>> upstream/master
public slots:
    void on_startBtn_clicked();
    void on_cheatBtn_clicked();
    void on_pauseBtn_clicked();
    void on_quitBtn_clicked();    
    void on_resumeBtn_clicked();
    void on_saveBtn_clicked();
    void on_loadBtn_clicked();
    void on_playAgainBtn_clicked();
    void backTimerHit();
    void midTimerHit();
    void frontTimerHit();
    void obstacleTimerHit();
    void spawningTimerHit();
    void furTimerHit();
    void jumpTimerHit();
    void hurtTimerHit();

signals:
    void clicked();
private:
    Ui::MainWindow *ui;
protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent * event);

};

#endif // MAINWINDOW_H
