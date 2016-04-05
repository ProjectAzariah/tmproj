#include "highscore.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include "background.h"
#include "gamemodel.h"

using namespace std;

void HighScore::saveCurrentScore(string name){
    for(size_t i = 0; i < playerScore.size(); i++){
        playerNames.insert(playerNames.begin() +i, name);
        playerScore.insert(playerScore.begin() + i, GameModel::instance()->getScore());
    }
}

void HighScore::loadFromFile()
{
   ifstream infile("highscore.txt");

   char *buffer;
   long size;

   infile.seekg(0, ifstream::end);
   size = infile.tellg();
   infile.seekg(0);

   //allocate memory
   buffer = new char [size];

   infile.read(buffer, size);



}



void HighScore::saveToFile(){
    ofstream scoreFile;
    scoreFile.open("highscores.txt");
    for(size_t i = 0; i < playerNames.size(); i++ ){
         scoreFile << playerNames.at(i);
         scoreFile << playerScore.at(i);
    }
    scoreFile.close();
}

void HighScore::Print(){
       QString text;
        QString num;
        QString from;

        for(size_t i = 0; i < playerNames.size(); i++) {
            num = "";
            text += num.number((i + 1), 10);
            text += ": ";
            from = "";
            text += from.fromStdString(playerNames.at(i));
            text += " - ";
            num = "";
            text += num.number(playerScore.at(i), 10);
            text += "\n";


        }


}

/*void HighScore::BubbleSort(vector<string> &playerscore){

}*/

void HighScore::testCases(){
    //don't work any more
    /*HighScore points("Bob", 40,  3);

    assert(points.getScore() == 40);
    assert(points.getName() == "Bob");
    assert(points.getDate() == 3);*/
}
