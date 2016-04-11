#include "highscore.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include "background.h"
#include "gamemodel.h"

#include <vector>
#include <algorithm>

using namespace std;

void HighScore::saveCurrentScore(){
    playerScore.push_back(GameModel::instance()->getScore());
}

QString HighScore::Print(){
        QString text;
        QString num;

        sort(playerScore.begin(), playerScore.end());
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
