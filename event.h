#ifndef EVENT_H
#define EVENT_H

#include "background.h"
#include "mainwindow.h"
#include "object.h"

class Obstacle : QObject
{
    Q_OBJECT
public:
    std::vector<QLabel*> obstacles;
    std::vector<QLabel*> spawnedObstacles;
    std::vector<Object*> objects;
    /*const int catX;
    const int catY;
    const int catW;
    const int catH;
    const int dogX;
    const int dogY;
    const int dogW;
    const int dogH;
    const int mowerX;
    const int mowerY;
    const int mowerW;
    const int mowerH;
    const int holeX;
    const int holeY;
    const int holeW;
    const int holeH;*/
    //QLabel * dog;

private:
    static Obstacle* instance_;

public:
    static Obstacle& instance();
    QLabel* spawnObstacles(QWidget* parent);



};

#endif // EVENT_H
