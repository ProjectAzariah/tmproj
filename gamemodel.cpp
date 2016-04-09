#include "gamemodel.h"
#include <algorithm>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <iostream>

using namespace std;



GameModel* GameModel::gameModel = nullptr;

GameModel* GameModel::instance(){
    if(gameModel == nullptr){
        gameModel = new GameModel;
    }
    return gameModel;
}

void GameModel::saveCurrentScore(){
    playerScore.push_back(score);
}

QString GameModel::Print(){
        QString text;
        QString num;

        if (playerScore.size()>=3){
        for(size_t i = 0; i < 3; i++) {
            num ="";
            text += num.number((i + 1), 10);
            text += ": ";
            text += num.number(playerScore.at(i), 10);
            text += "\n";
        }
        }else{
            int size = playerScore.size();
            int blanks = 3-size;
            size_t i =0;
            for(i; i < size; i++){
                num="";
                text += num.number((i + 1), 10);
                text += ": ";
                text += num.number(playerScore.at(i), 10);
                text += "\n";
            }
            for(size_t i2=0; i2 < blanks; i2++){
                text += num.number((i+1), 10);
                text += ": ---";
                text += "\n";
                i++;
            }
        }
        return text;
}

void GameModel::doScores(){
    QFile scores("scores.txt");
    QTextStream out(&scores);

    if(scores.open(QIODevice::ReadWrite | QIODevice::Append)){
        out << score << "\n";
    }
    scores.close();

    playerScore.clear();

    if(scores.open(QIODevice::ReadOnly)){
    QTextStream in(&scores);
    while(!in.atEnd()){
        QString temp = scores.readLine();
        playerScore.push_back(temp.toInt());
    }
        scores.close();
    }

    std::sort(playerScore.begin(), playerScore.end(), std::greater<int>());

    if(playerScore.size() > 3){
        playerScore.erase(playerScore.begin()+3, playerScore.end());
        if(scores.open(QIODevice::ReadWrite | QIODevice::Truncate)){
            for(size_t i=0; i < playerScore.size(); i++){
                out << playerScore.at(i) << "\n";
            }
        }
    }
}
