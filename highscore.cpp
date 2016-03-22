#include "highscore.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

/*void HighScore::add(){
    for(size_t i = 0; i <playerscores.size(); i++){
        playerscores.add(i);
    }
}*/

void HighScore::loadFromFile()
{
    ofstream scoreFile("score.txt");
    if (scoreFile == nullptr){
        cout << "FILE IS MISSING";
    } else {


    }


}



void HighScore::saveToFile(){
    ofstream scoreFile;
    scoreFile.open("score.txt");
    for(size_t i = 0; i < playerscores.size(); i++ ){
         scoreFile << playerscores.at(i);
    }
    scoreFile.close();
}

/*void HighScore::BubbleSort(vector<string> &playerscore){

}*/

void testCases(){
    //don't work any more
    /*HighScore points("Bob", 40,  3);

    assert(points.getScore() == 40);
    assert(points.getName() == "Bob");
    assert(points.getDate() == 3);*/
}
