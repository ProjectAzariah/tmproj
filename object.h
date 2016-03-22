#ifndef OBJECT_H
#define OBJECT_H
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <vector>
#include <string>

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

    virtual void saveGame() { }
    void loadGame();

};

class CuriousCat : public Object
{
public:
    //int jumpSpeed;
    int gravity;

    QLabel * cat;
    QMovie * catMovie;
    explicit CuriousCat(QWidget * parent);

    int health = 100;
    /* //saves a game object
     void saveGame() {
         QFile data("data.txt");
         if(data.open(QIODevice::ReadWrite)){
             QTextStream out(&data);

             out << label->x() << "\n";
             out << label->y() << "\n";
         }
     }

     //loads a game object
     void loadGame() {
         QFile data("data.txt");
         if(data.open(QIODevice::ReadWrite)){
                 QString str = data.readLine();
                 int catx = str.toInt();
                 QString str2 = data.readLine();
                 int caty = str2.toInt();

                 label->setGeometry(catx, caty, 75, 75);
         }
     }*/

};

class MadDog :public Object
{
    Q_OBJECT

public:
    explicit MadDog();
    //QTimer * dogTimer;


    void saveGame();


};

class LawnMower : public Object
{
    Q_OBJECT
private:
    //QLabel * mower;
public:
    explicit LawnMower();

    void saveGame();

};

class Hole : public Object
{
    Q_OBJECT
private:
    //QLabel * hole;
public:
    explicit Hole();

    void saveGame();
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
