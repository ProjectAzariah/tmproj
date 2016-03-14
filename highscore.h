#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QString>
#include <cassert>
#include <iostream>
#include <fstream>

class HighScore{
private:
    int score, date; //time
    QString name;
public:
    HighScore();

    HighScore(QString initName, int initScore, /*int initTime,*/ int initDate):
    score(initScore), name(initName), /*time(initTime),*/ date(initDate) {}

    //Getters
    int getScore() {return score;}
    QString getName() {return name;}
    int getDate() {return date;}
    //int getTime() {return time;}


    void setScore (int newScore) { score = newScore;}
    void setName(int newName) {name = newName;}
    void setDate(int newDate) {date =  newDate;}
    //void setTime(int newTime) { time = newTime;}


    //uses the <filename> with a certain name and saves the data to it
    void saveToFile(QString filename);

    //uses the <filename> to get the file reads from it and outputs the data in corect format
    void loadFromFile(QString filename);

    void testCases();

};

#endif // HIGHSCORE_H
