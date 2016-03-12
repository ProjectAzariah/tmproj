#include "gamemodel.h"

#include <QTextStream>
#include <QFile>

gameModel::gameModel()
{
    QFile data("data.txt");

}

//saves a game object
//this code is an example of the override function that will be defined in every object class
void object::saveGame() {
    if(data.open(QIODevice::ReadWrite)){
        QTextStream out(&data);

        out << "Level:" << "8" << "\n";
    }
}

//loads a game object
//this code is an example of the override function for the level object
void object::loadGame() {
    if(data.open(QIODevice::ReadWrite)){
            QString level = data.readline();
            int levelInt = level.toInt();
            //set <levelInt> equal to instance variable
    }
}
