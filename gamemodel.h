#ifndef GAMEMODEL_H
#define GAMEMODEL_H


class GameModel
{
private:
    int health, score;
    static GameModel* gameModel;

    GameModel():health(100), score(0) {}

public:
    static GameModel* instance();

    void Hurt(int amount){ health -= amount;}
    void AddScore(){ score+=2;}

    void setHealth(int h){health = h;}
    void setScore (int s){score = s;}

    int getHealth() {return health;}
    int getScore() {return score;}
};



#endif // GAMEMODEL_H
