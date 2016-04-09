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
    vector<int> playerScore;

public:
    //setter for <name>

    HighScore(){}

    void saveCurrentScore();

    //uses the <filename> with a certain name and saves the data to it
    //void saveToFile();

    //uses the <filename> to get the file reads from it and outputs the data in corect format
    //void loadFromFile();

    //void add();
};

#endif // HIGHSCORE_H
