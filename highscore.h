#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QString>
#include <QObject>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class HighScore {

private:

    QString name;

    vector<string> playerNames;
    vector<int> playerScore;

public:

    //getter
    QString getName() {return name;}

    //setter for <name>

    HighScore(){}

    void saveCurrentScore(string name);

    //uses the <filename> with a certain name and saves the data to it
    void saveToFile();

    //uses the <filename> to get the file reads from it and outputs the data in corect format
    void loadFromFile();

    //void add();

    //BubbleSort(vector<string> &playerscore);

    //void clearscore();

    void Print();

    void testCases();

};

#endif // HIGHSCORE_H
