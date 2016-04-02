

#include "gamemodel.h"

using namespace std;

GameModel* GameModel::gameModel = nullptr;

GameModel* GameModel::instance(){
    if(gameModel == nullptr){
        gameModel = new GameModel;
    }
    return gameModel;
}




