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
    //QLabel * dog;

private:
    static Obstacle* instance_;

public:
    static Obstacle& instance();
    QLabel* spawnObstacles(QWidget* parent);



};

#endif // EVENT_H
