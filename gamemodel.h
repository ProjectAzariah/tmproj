#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "highscore.h"

#include <QString>
#include <QFile>


class GameModel
{
private:
    int health, score;
    static GameModel* gameModel;
    vector<int> playerScore;


    GameModel():health(100), score(0) {}

public:

    HighScore highscore;
    static GameModel* instance();

    void Hurt(int amount){ health -= amount;}
    void AddScore(){ score+=2;}

    void setHealth(int h){health = h;}
    void setScore (int s){score = s;}

    int getHealth() {return health;}
    int getScore() {return score;}

    QString Print();
    void saveCurrentScore();
    void doScores();
};



#endif // GAMEMODEL_H
