#ifndef DOG_H
#define DOG_H
#include <QImage>
#include <QRect>
//#include "enemy.h"

class Dogs
{

  public:
    Dogs();
    ~Dogs();

  public:
    void move(int);
    void resetState();
    void shoot(int);
    bool isDestroyed();
    void setDestroyed(bool);

    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
    bool destroyed;
    QImage image;
    QRect rect;

};

#endif
