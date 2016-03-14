#ifndef OBJECT_H
#define OBJECT_H
#include <QLabel>

class Object {
protected:
    int x;
    int y;
    int h;
    int w;
    QLabel* label;


    public:
        /*virtual void saveGame();
        virtual void loadGame();*/
};

#endif // OBJECT_H
