#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QString>
#include <QObject>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class HighScore : public QObject {

private:
    int OBJscore, date; //time
    QString name;

    vector<string> playerscores;
public:



    //Getters
    int getScore() {return OBJscore;}
    QString getName() {return name;}
    int getDate() {return date;}
    //int getTime() {return time;}


    void setScore (int newScore) { OBJscore = newScore;}
    /*void setName(int newName) {name = newName;}
    void setDate(int newDate) {date =  newDate;}
    //void setTime(int newTime) { time = newTime;}*/


    //uses the <filename> with a certain name and saves the data to it
    void saveToFile();

    //uses the <filename> to get the file reads from it and outputs the data in corect format
    void loadFromFile();

    void add();

    //BubbleSort(vector<string> &playerscore);

    void clearscore();

    void Print();

    void testCases();

};

#endif // HIGHSCORE_H
