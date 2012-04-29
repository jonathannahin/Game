#ifndef BULLET_H
#define BULLET_H

#include <QImage>
#include <QRect>

class Bullet
{

  public:
    Bullet();
    ~Bullet();

  public:
    void move(int);//Move Bullet
    void resetState();//Restart State
    void shoot(int);//Moves bullet from left to right
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    bool isDestroyed();//Check if destroyed
    void setDestroyed(bool);//Set if destroyed
    QRect getRect();//get location of image
    QImage & getImage();//get image

  protected:

    int xdir;
    int ydir;
    bool stuck;
    bool destroyed;

    QImage image;
    QRect rect;

};
class Fire_bullet:public Bullet
{

  public:
    Fire_bullet(){  image.load("firebullet.gif");

                    rect = image.rect();};
    ~Fire_bullet();

  public:
    void move(int pos){rect.moveTo(145,pos+15);};
    void resetState(){rect.moveTo(40, 305);};
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void shoot(int) {rect.translate(1,0 );};
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();

    QRect getRect()
    {
      return rect;
    };

    QImage&  getImage()
    {
      return image;
    };

    bool isDestroyed()
    {
      return destroyed;
    };

    void setDestroyed(bool destr)
    {
      destroyed = destr;
    };

  private:




};

#endif
