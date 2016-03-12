#ifndef GAMEMODEL_H
#define GAMEMODEL_H



class object {
public:
    virtual void saveGame();
    virtual void loadGame();
};

class gameModel
{
public:
    gameModel();
};



#endif // GAMEMODEL_H
