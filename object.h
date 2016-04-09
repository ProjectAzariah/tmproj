#ifndef OBJECT_H
#define OBJECT_H
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <vector>
#include <string>
#include <QTextStream>
#include <QFile>

class Object : public QObject
{
    Q_OBJECT

protected:
    int x, y, h, w;
    int healthimpact;
    std::string type;
    bool isActive();
    //bool isDog = false;
    //bool isMower = false;
    //bool isHole = false;

    //QLabel * label;

public:
    bool isCollided;
    int getX()
    {return x;}
    void setX(int newX) {x = newX;}
    int getY()
    {return y;}
    void setY(int newY) {y = newY;}
    int getW()
    {return w;}
    void setW(int newW) {w = newW;}
    int getH()
    {return h;}
    void setH(int newH) {h = newH;}
    std::string getType()
    {return type;}
    void setType(std::string newType) {type = newType;}
    void setHealthImpact(int h){healthimpact = h;}
    int getHealthImpact(){return healthimpact;}
};

class CuriousCat : public Object
{
public:
    //int jumpSpeed;
    //int gravity;
    bool isLanded;
    bool isClimbing;
    bool isFalling;
    int speed;
    int height;
    int counter;

    QLabel * cat;
    QMovie * catMovie;
    std::vector<QLabel*>catSensors;
    const int sensorW = 10;
    const int sensorH = 10;
    const int forHeadX = 268;
    const int forHeadY = 514;
    const int mouthX = 274;
    const int mouthY = 550;
    const int frontPawX = 256;
    const int frontPawY = 606;
    const int tailX = 179;
    const int tailY = 537;
    explicit CuriousCat(QWidget * parent);


    int health = 100;

};

class MadDog :public Object
{
    Q_OBJECT

public:
    explicit MadDog();
    //QTimer * dogTimer;


};

class LawnMower : public Object
{
    Q_OBJECT
private:
    //QLabel * mower;
public:
    explicit LawnMower();

};

class Hole : public Object
{
    Q_OBJECT
private:
    //QLabel * hole;
public:
    explicit Hole();

/*=======

private:
    int x;
    int y;
    int h;
    int w;
    std::string type;
    bool isActive();

    //QLabel * label;

public:
    int getX()
    {return x;}
    void setX(int newX) {x = newX;}
    int getY()
    {return y;}
    void setY(int newY) {y = newY;}
    int getW()
    {return w;}
    void setW(int newW) {w = newW;}
    int getH()
    {return h;}
    void setH(int newH) {h = newH;}
    std::string getType()
    {return type;}
    void setType(std::string newType) {type = newType;}
    //static QLabel *objectSpawner(QWidget * parent);
    //static std::vector<QLabel*> objects;
    //static std::vector<Object> spawnedObjects;

};

class CuriousCat : public Object
{
public:
    QLabel * cat;
    QMovie * catMovie;
    explicit CuriousCat(QWidget * parent);
  */
};

#endif // OBJECT_H
